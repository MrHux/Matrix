#ifndef PROJETCPP2_CFILE_H
#define PROJETCPP2_CFILE_H

#include "stdafx.h"

// String (char[]) buffer size
#define BUFFER_SIZE 1024

// Values of Cexception thrown
#define ERROR_INPUT_FILE_OPEN 10
#define ERROR_CHANGING_SIZE_TABLE_VALUES 11

// Path of test's files
#define INPUT_FILE1 ".\\File_Test\\in\\mat1.txt"
#define INPUT_FILE2 ".\\File_Test\\in\\mat2.txt"
#define INPUT_FILE3 ".\\File_Test\\in\\mat3.txt"
#define INPUT_FILE4 ".\\File_Test\\in\\mat4.txt"
#define OUTPUT_FILE ".\\File_Test\\out\\out.txt"

// Important characters in the input files
#define CHARS_DELIMS_TOKENS "= "

#define CHARS_MATRIX_TYPE "TypeMatrice"
#define CHARS_MATRIX_ROWS "NBLignes"
#define CHARS_MATRIX_COLUMNS "NBColonnes"

#define CHARS_MATRIX "Matrice"

#define CHAR_BEGIN_TABLE "["
#define CHAR_END_TABLE "]"

template <class MType>
class Cmatrix;

class Cfile
{
public:

	/*
	-- Matrix's file parsing fuction --

	Input : pcFile_to_parse, filename of file to parse
	Prerequisite : none
	Output : A table of cstring (char *) containing all the important values in the file
			 A Cexception if we can't open the file.
	Lead to : The file is parsed and all the values are stored into a table of cstring.
	*/
	static char ** FILparse_file(const char* pcFile_to_parse);

};

#endif
