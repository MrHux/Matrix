#include "stdafx.h"

/*
-- Matrix's file parsing fuction --

Input : pcFile_to_parse, filename of file to parse
Prerequisite : none
Output : A table of cstring (char *) containing all the important values in the file
		 A Cexception if we can't open the file.
Lead to : The file is parsed and all the values are stored into a table of cstring.
*/
char ** Cfile::FILparse_file(const char* pcFile_to_parse) throw (Cexception)
{
	char ** ppFile_values = NULL; // Minimum values to store 2, a pair : description => value

	unsigned int uiIndexfile_values = 0; // Index in the table of cstring ppFile_values
	unsigned int uiNumber_values_per_line = 0; // Number of tokens read (a pair contains 2 tokens : descrpition and value)

	char pcBuffer[BUFFER_SIZE]; // Buffer to store the line read

	// Pointers needed for retrieving values from a line.
	char *pcValue = NULL;
	char *pcNext_value = NULL;

	// Opening a file stream towards the file to parse
	std::ifstream streamOfFileToParse(pcFile_to_parse);

	// If the file stream opening is successful
	if (streamOfFileToParse.is_open() == true)
	{
		// While we haven't reached the end of the file or some error occured
		while (streamOfFileToParse.getline(pcBuffer, BUFFER_SIZE))
		{
			uiNumber_values_per_line = 0; // For each line read, we reset the counter of values read per line

			pcValue = strtok_s(pcBuffer, CHARS_DELIMS_TOKENS, &pcNext_value); // Trying to retrieve a token into pcValue

			// If a token has been retrieved
			while (pcValue != NULL)
			{
				uiNumber_values_per_line++;

				// If we read a character of table end ']', we need to add only one columns to table
				if (strcmp(pcValue, CHAR_END_TABLE) == 0)
				{
					ppFile_values = (char **)realloc(ppFile_values, (uiIndexfile_values + 1) * sizeof(char *));
					if (ppFile_values == NULL)
					{
						Cexception exc(ERROR_CHANGING_SIZE_TABLE_VALUES);
						throw exc;
					}
				}
				// For each new pair read in the line, add 2 columns to our table.
				else if (uiNumber_values_per_line % 2 == 1)
				{
					ppFile_values = (char **)realloc(ppFile_values, (uiIndexfile_values + 2) * sizeof(char *));
					if (ppFile_values == NULL)
					{
						Cexception exc(ERROR_CHANGING_SIZE_TABLE_VALUES);
						throw exc;
					}
				}

				// Allocating a new cstring into our table to store the token
				ppFile_values[uiIndexfile_values] = new char[strlen(pcValue) + 1];
				// Copy in ppFile_values[uiIndexfile_values] (wich is strlen(pcValue) + 1 characters long) the cstring pcValue, 
				// if pcValue is bigger than ppFile_values[uiIndexfile_values], truncate pcValue to fit
				strncpy_s(ppFile_values[uiIndexfile_values], strlen(pcValue) + 1, pcValue, _TRUNCATE);

				uiIndexfile_values++;

				pcValue = strtok_s(NULL, CHARS_DELIMS_TOKENS, &pcNext_value);
			}
		}

		// Adding a new column to store NULL, indicating the end of the table
		ppFile_values = (char **)realloc(ppFile_values, (uiIndexfile_values + 1) * sizeof(char *));
		if (ppFile_values == NULL)
		{
			Cexception exc(ERROR_CHANGING_SIZE_TABLE_VALUES);
			throw exc;
		}

		ppFile_values[uiIndexfile_values] = NULL;
	}
	// The file to parse cannot be opened
	else
	{
		Cexception exc;
		exc.EXCsetValue(ERROR_INPUT_FILE_OPEN);

		throw exc;
	}

	return ppFile_values;
}