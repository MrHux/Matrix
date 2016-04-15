#include "stdafx.h"

#ifndef NDEBUG 

/*
-- Unit test for Cfile parsing method --

Input : nothing
Prerequisite : none
Output : nothing
Lead to : If the parsing method doesn't return a proper table of values, the test fail and the program is aborded.
*/
void CfileUNIT::FUTtestParsingMethod()
{
	char ** test1 = Cfile::FILparse_file(INPUT_FILE1);
	
	assert(strcmp(test1[0], "TypeMatrice") == 0);
	assert(strcmp(test1[1], "double") == 0);

	assert(strcmp(test1[2], "NBLignes") == 0);
	assert(strcmp(test1[3], "2") == 0);

	assert(strcmp(test1[4], "NBColonnes") == 0);
	assert(strcmp(test1[5], "3") == 0);

	assert(strcmp(test1[6], "Matrice") == 0);
	assert(strcmp(test1[7], "[") == 0);

	assert(strcmp(test1[8], "1") == 0);
	assert(strcmp(test1[9], "2.5") == 0);
	assert(strcmp(test1[10], "3.9") == 0);

	assert(strcmp(test1[11], "4") == 0);
	assert(strcmp(test1[12], "-5") == 0);
	assert(strcmp(test1[13], "6.4242") == 0);

	assert(strcmp(test1[14], "]") == 0);
	assert(test1[15] == NULL);

	char ** test2 = Cfile::FILparse_file(INPUT_FILE2);

	assert(strcmp(test2[0], "TypeMatrice") == 0);
	assert(strcmp(test2[1], "int") == 0);

	assert(strcmp(test2[2], "NBLignes") == 0);
	assert(strcmp(test2[3], "3") == 0);

	assert(strcmp(test2[4], "NBColonnes") == 0);
	assert(strcmp(test2[5], "3") == 0);

	assert(strcmp(test2[6], "Matrice") == 0);
	assert(strcmp(test2[7], "[") == 0);

	assert(strcmp(test2[8],  "1") == 0);
	assert(strcmp(test2[9],  "2") == 0);
	assert(strcmp(test2[10], "3") == 0);

	assert(strcmp(test2[11], "4") == 0);
	assert(strcmp(test2[12], "5") == 0);
	assert(strcmp(test2[13], "6") == 0);

	assert(strcmp(test2[14], "7") == 0);
	assert(strcmp(test2[15], "8") == 0);
	assert(strcmp(test2[16], "9") == 0);

	assert(strcmp(test2[17], "]") == 0);
	assert(test2[18] == NULL);

	char ** test3 = Cfile::FILparse_file(INPUT_FILE3);

	assert(strcmp(test3[0], "TypeMatrice") == 0);
	assert(strcmp(test3[1], "double") == 0);

	assert(strcmp(test3[2], "NBLignes") == 0);
	assert(strcmp(test3[3], "1") == 0);

	assert(strcmp(test3[4], "NBColonnes") == 0);
	assert(strcmp(test3[5], "1") == 0);

	assert(strcmp(test3[6], "Matrice") == 0);
	assert(strcmp(test3[7], "[") == 0);

	assert(strcmp(test3[8], "42") == 0);

	assert(strcmp(test3[9], "]") == 0);
	assert(test3[10] == NULL);

	try
	{
		char ** test4 = Cfile::FILparse_file("Fichier qui n'existe pas"); // File doesn't exists, a Cexception should be risen
		assert(false); // We should not get here
	}
	catch (Cexception exc)
	{
		if (exc.EXCgetValue() == ERROR_INPUT_FILE_OPEN)
		{
			// A Cexception corresponding to an input file opening error should be risen
			assert(true);
		}
		else
		{
			// We should not get here, (bat type of Cexcpetion)
			assert(false);
		}
	}

	// Freeing up memory
	unsigned int uiIndexTest = 0;

	while (test1[uiIndexTest] != NULL)
	{
		delete[] test1[uiIndexTest];
		uiIndexTest++;
	}
	delete test1;

	uiIndexTest = 0;

	while (test2[uiIndexTest] != NULL)
	{
		delete[] test2[uiIndexTest];
		uiIndexTest++;
	}
	delete test2;

	uiIndexTest = 0;

	while (test3[uiIndexTest] != NULL)
	{
		delete[] test3[uiIndexTest];
		uiIndexTest++;
	}
	delete test3;
}

#endif