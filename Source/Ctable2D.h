#pragma once

#ifndef CTABLE2_D_H
#include "stdafx.h"

#define ERROR_MATRIX_NULL_AND_ROWS_COLUMNS_NOT_NULL 30
#define ERROR_MATRIX_NULL 31
#define ERROR_VALUES_RETURNED_IS_NULL 32
#define ERROR_UNEXPECTED_TOKEN 33
#define ERROR_MATRIX_TYPE_NOT_DOUBLE 34

template <class MType>
class Ctable2D
{
private:

	unsigned int uiTABnbRows;

	unsigned int uiTABnbColumns;

	MType** ppTABvalues;

public:

	/*
	* This constructor build a new Ctable2D with null values.
	* @param : void
	* @return : void
	*/
	Ctable2D<MType>();

	/*
	* This constructor build a new Ctable2D with the value of another Ctable2D in parameter.
	* If the Ctable2D in parameter is null , it throw an exception (return Ctable will be set with null values).
	* @param : const Ctable2D &table : Ctable2D to copy
	* @return : void
	*/
	Ctable2D<MType>(const Ctable2D &table);

	/*
	* This constructor build a new Ctable2D with uiNbRows number of rows, and uiNbColumns number of columns.
	* The value of the matrix are initialized to 0.
	* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
	* @param :
	* unsigned int uiNbRows : number of row to set
	* unsigned int uiNbColumns : number of columns to set
	* @return : void
	*/
	Ctable2D<MType>(unsigned int uiNbRows, unsigned int uiNbColumns);

	/*
	* This constructor build a new Ctable2D with uiNbRows number of rows, and uiNbColumns number of columns.
	* The value of the matrix are initialized with the param MTvalue.
	* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
	* @param :
	* unsigned int uiNbRows : number of row to set
	* unsigned int uiNbColumns : number of columns to set
	* MType MTvalue : the value to set in the table
	* @return : void
	*/
	Ctable2D<MType>(unsigned int uiNbRows, unsigned int uiNbColumns, MType MTvalue);

	/**
	* This constructor build a new Ctable2D with value of the two dimension table ppValues, uiNbRows and uiNbColumns need to be the dimension of ppValues.
	* If one of the uiNbRows or uiNbColumns is not null and if ppValues is null , it return an exception because the value of uiNbColumns and uiNbRows are different to the real dimension of ppValues.
	* @param :
	* MType** ppValues : new matrix to set
	* unsigned int uiNbRows : new number of rows
	* unsigned int uiNbColumns : new number of columns
	* @return : void
	*/
	Ctable2D<MType>(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns) throw(Cexception);

	/*
	* This Constructor build a new Ctable2D with the value of Cfile. It is important to call the constructor with the correct type contained inside the file.
	* The String values of the matrix of the file are converted with the function stod , then the Double result will be cast with the wanted Type.
	* So there will be no loss due to the conversion as you use the correct type of the matrix.
	* @param : Cfile &file
	* @return : void
	*/
	Ctable2D<MType>(const char* pcFile_to_parse) throw(Cexception);

	/*
	* This is the destructor of Ctable2D, it delete correctly the object.
	* If the ppTABvalues is null but uiTABnbRows or uiTABnbColumns are not, it show a warning.
	* @param : void
	* @return : void
	*/
	~Ctable2D<MType>();

	/*
	* Get the number of row of the Ctable2D
	* @param : void
	* @return : unsigned int : the number of rows
	*/
	unsigned int TABgetNbRows()const;

	/*
	* Get the number of columns of the Ctable2D
	* @param : void
	* @return : unsigned int : the number of columns
	*/
	unsigned int TABgetNbColumns()const;

	/*
	* Get the values of the Ctable2D
	* @param : void
	* @return :MType** : the values
	*/
	MType** TABgetValues()const;

	/*
	* This function is the only usefull setter for a 2 dimensions table, to set a new value in the table user need to use this one. 
	* No other function are needed , this one assure that a Ctable2D will have the correct number of row and columns corresponding to the ppValues matrix.
	* Of course the user need to give the correct number of rows and columns associated with the new matrix to set.
	* @param : 
	* ** ppValues : pointer on the new matrix to set.
	* uiNbRows : number of row of the new matrix.
	* uiNbColumns : number of columns of the new matrix.
	* @return : void
	*/
	void TABsetValues(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns) throw (Cexception);

	void TABsetValue(unsigned int uiIndexRows, unsigned int uiIndexColumns, MType value);

	/**
	* Print to screen a Ctable2D.
	* @param : void
	* @return : void
	
	*/
	void TABprintf()const throw (Cexception);

	/**
	* Print to screen the values of the Ctable2D with the desired format.
	* @param : const char * format : The String containing the desired format (like printf() format) .
	* @return : void
	*/
	void TABprintf(const char * format)const throw (Cexception);
	
	/**
	* Create a new Ctable2D with the value of the Ctable2D in parameter.
	* @param : const Ctable2D &table : the Ctable2D to copy
	* @return : Ctable2D<MType> : return a pointer on the object who call the function
	*/
	Ctable2D<MType> &operator=(const Ctable2D &table);

	/**
	* Test if two Ctable are equal
	* @param : const Ctable2D<MType> &TABtableToCompare : The Ctable2D to compare
	* @return : bool : return True if the two Ctable2D are equal , False if not.
	*/
	bool operator==(const Ctable2D<MType> &TABtableToCompare)const;

	/**
	* Test if two Ctable2D are not equal.
	* @param : const Ctable2D<MType> &TABtableToCompare : The Ctable2d to compare.
	* @return : bool : True if the two Ctable2D are not equal , False if they are.
	*/
	bool operator!=(const Ctable2D<MType> &TABtableToCompare)const;
};
#endif



/*
* This constructor build a new Ctable2D with null values.
* @param : void
* @return : void
*/
template <class MType> Ctable2D<MType>::Ctable2D() : Ctable2D(0, 0) {
	//Call Ctable(unsigned int uiNbRows = 0, unsigned int uiNbColumns = 0);
}

/*
* This constructor build a new Ctable2D with the value of another Ctable2D in parameter.
* If the Ctable2D in parameter is null (return Ctable will be set with null values).
* @param : const Ctable2D &table : Ctable2D to copy
* @return : void
*/
template <class MType> Ctable2D<MType>::Ctable2D(const Ctable2D &table){
	MType ** MTtable = NULL;
	uiTABnbRows = 0;
	uiTABnbColumns = 0;
	if (table.uiTABnbRows > 0 && table.uiTABnbColumns > 0 && &table != NULL){
		uiTABnbRows = table.uiTABnbRows;
		uiTABnbColumns = table.uiTABnbColumns;
		MTtable = new MType*[uiTABnbRows];
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			MTtable[i] = new MType[uiTABnbColumns];
			for (unsigned int j = 0; j < uiTABnbColumns; j++){
				MTtable[i][j] = table.ppTABvalues[i][j];
			}
		}
	}
	ppTABvalues = MTtable;
}

/*
* This constructor build a new Ctable2D with uiNbRows number of rows, and uiNbColumns number of columns.
* The value of the matrix are initialized to 0.
* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
* @param : 
* unsigned int uiNbRows : number of row to set
* unsigned int uiNbColumns : number of columns to set
* @return : void
*/
template <class MType> Ctable2D<MType>::Ctable2D(unsigned int uiNbRows, unsigned int uiNbColumns) : Ctable2D<MType>(uiNbRows, uiNbColumns, 0){
	//Call Ctable2D(unsigned int uiNbRows, unsigned int uiNbColumns, MType MTvalue)
}

/*
* This constructor build a new Ctable2D with uiNbRows number of rows, and uiNbColumns number of columns.
* The value of the matrix are initialized with the param MTvalue.
* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
* @param :
* unsigned int uiNbRows : number of row to set
* unsigned int uiNbColumns : number of columns to set
* MType MTvalue : the value to set in the table
* @return : void
*/
template <class MType> Ctable2D<MType>::Ctable2D(unsigned int uiNbRows, unsigned int uiNbColumns, MType MTvalue){
	MType ** MTtable = NULL;
	uiTABnbRows = uiNbRows;
	uiTABnbColumns = uiNbColumns;
	if (uiNbColumns>0 && uiNbRows > 0){
		MTtable = new MType*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new MType[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = MTvalue;
			}
		}
	}
	else if (uiNbColumns == 0 || uiNbRows == 0){
		uiTABnbRows = 0;
		uiTABnbColumns = 0;
	}
	ppTABvalues = MTtable;
}

/**
* This constructor build a new Ctable2D with value of the two dimension table ppValues, uiNbRows and uiNbColumns need to be the dimension of ppValues.
* If one of the uiNbRows or uiNbColumns is not null and if ppValues is null , it return an exception because the value of uiNbColumns and uiNbRows are different to the real dimension of ppValues. 
* @param :
* MType** ppValues : new matrix to set
* unsigned int uiNbRows : new number of rows
* unsigned int uiNbColumns : new number of columns
* @return : void 
*/
template <class MType> Ctable2D<MType>::Ctable2D(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns) throw(Cexception){
	
	ppTABvalues = NULL;
	uiTABnbColumns = 0;
	uiTABnbRows = 0;

	if (ppValues == NULL && (uiNbRows != 0 || uiNbColumns != 0)){
		//exception in case of not allocated ppTABvalues and number of row and columns different of 0, this should not appear if we use getter, setter, and constructor
		Cexception exc(ERROR_MATRIX_NULL_AND_ROWS_COLUMNS_NOT_NULL);
		throw exc;
	}
	else if (ppTABvalues == NULL){
		ppTABvalues = ppValues;
	}
	else{
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			delete ppTABvalues[i];
		}
		delete ppTABvalues;
		ppTABvalues = ppValues;
	}
	uiTABnbRows = uiNbRows;
	uiTABnbColumns = uiNbColumns;
}

/*
* This Constructor build a new Ctable2D by parsing a matrix's file. 
* 
* The file must contains the correct matrix's type (double) in order to succesfully construct a new Ctable2D.
* The String values of the matrix of the file are converted with the function stod , then the Double result will be cast with the wanted Type.
* So there will be no loss due to the conversion as you use the correct type of the matrix.
*
* @param : pcFile_to_parse, filename of file to parse
* @return : void 
*/
template <class MType> Ctable2D<MType>::Ctable2D(const char* pcFile_to_parse) throw(Cexception)
{
	char ** ppValues_returned = NULL;

	unsigned int uiIndex_values = 0;
	unsigned int uiIndex_matrix_rows = 0;
	unsigned int uiIndex_matrix_columns = 0;

	bool bReadingTable = false;

	uiTABnbRows = 0;
	uiTABnbColumns = 0;
	ppTABvalues = NULL;

	ppValues_returned = Cfile::FILparse_file(pcFile_to_parse);

	// Testing if there is some values returned
	if (ppValues_returned[0] != NULL)
	{
		// While there is still some values to read
		while (ppValues_returned[uiIndex_values] != NULL)
		{
			// If the next value read will be the matrix's type
			if (strcmp(ppValues_returned[uiIndex_values], CHARS_MATRIX_TYPE) == 0)
			{
				// Reading matrix's type
				if (strcmp(ppValues_returned[uiIndex_values + 1], "double") != 0)
				{
					Cexception exc(ERROR_MATRIX_TYPE_NOT_DOUBLE);
					throw exc;
				}

				uiIndex_values += 2;
			}
			// If the next value read will be the matrix's numbers od rows
			else if (strcmp(ppValues_returned[uiIndex_values], CHARS_MATRIX_ROWS) == 0)
			{
				// Reading matrix's number of rows
				unsigned int uiNumber_rows_read = atoi(ppValues_returned[uiIndex_values + 1]);
				if (uiNumber_rows_read != 0)
				{
					uiTABnbRows = uiNumber_rows_read;
					
					ppTABvalues = new MType*[uiTABnbRows];
					for (unsigned int uiIndex_TABvalues = 0; uiIndex_TABvalues < uiTABnbRows; uiIndex_TABvalues++)
					{
						ppTABvalues[uiIndex_TABvalues] = NULL;
					}

					uiIndex_values += 2;
				}
				else
				{
					Cexception exc(ERROR_UNEXPECTED_TOKEN);
					throw exc;
				}
			}
			// If the next value read will be the matrix's number of columns
			else if (strcmp(ppValues_returned[uiIndex_values], CHARS_MATRIX_COLUMNS) == 0)
			{
				// Reading matrix's number of columns
				unsigned int uiNumber_columns_read = atoi(ppValues_returned[uiIndex_values + 1]);
				if (uiNumber_columns_read != 0)
				{
					uiTABnbColumns = uiNumber_columns_read;
					uiIndex_values += 2;
				}
				else
				{
					Cexception exc(ERROR_UNEXPECTED_TOKEN);
					throw exc;
				}
			}
			// If the next value read will be the beginning of the matrix's values table
			else if (strcmp(ppValues_returned[uiIndex_values], CHARS_MATRIX) == 0)
			{
				// Reading the beginning of matrix's values
				if (strcmp(ppValues_returned[uiIndex_values + 1], CHAR_BEGIN_TABLE) == 0)
				{
					bReadingTable = true;
					uiIndex_values += 2;
				}
				else
				{
					// Table begin's char not found
					Cexception exc(ERROR_UNEXPECTED_TOKEN);
					throw exc;
				}
			}
			// If the next value read will be the matrix's values
			else if (bReadingTable == true && uiIndex_matrix_rows < uiTABnbRows)
			{
				// Reading in a single shot the matrix's values

				// While we have a matrix row to read
				while (uiIndex_matrix_rows < uiTABnbRows)
				{
					uiIndex_matrix_columns = 0;

					// Allocating the column of values read
					ppTABvalues[uiIndex_matrix_rows] = new MType[uiTABnbColumns];

					// While we have a value on the line to read
					while (uiIndex_matrix_columns < uiTABnbColumns)
					{
						// Storing the value read as a double
						ppTABvalues[uiIndex_matrix_rows][uiIndex_matrix_columns] = atof(ppValues_returned[uiIndex_values]);

						uiIndex_matrix_columns++;
						uiIndex_values++;
					}

					uiIndex_matrix_rows++;
				}
			}
			// If the next value read will be the end of the matrix's values table
			else if (strcmp(ppValues_returned[uiIndex_values], CHAR_END_TABLE) == 0)
			{
				// Reading the end of matrix's values
				if (bReadingTable == true)
				{
					bReadingTable = false;
					uiIndex_values++;
				}
				else
				{
					// Table end's char found, but not after a table begin's char
					Cexception exc(ERROR_UNEXPECTED_TOKEN);
					throw exc;
				}
			}
			// If the next value read seems to not be something related to a valid matrix file
			else
			{
				// Unexpected characters read
				Cexception exc(ERROR_UNEXPECTED_TOKEN);
				throw exc;
			}
		}
	}
	else
	{
		// No values returned (table is NULL)
		Cexception exc(ERROR_VALUES_RETURNED_IS_NULL);
		throw exc;
	}

	// Freeing up memory
	uiIndex_values = 0;

	while (ppValues_returned[uiIndex_values] != NULL)
	{
		delete[] ppValues_returned[uiIndex_values];
		uiIndex_values++;
	}
	delete ppValues_returned;
}

/*
* This is the destructor of Ctable2D, it delete correctly the object.
* If the ppTABvalues is null but uiTABnbRows or uiTABnbColumns are not, it show a warning.
* @param : void
* @return : void
*/
template <class MType> Ctable2D<MType>::~Ctable2D(){
	if (ppTABvalues != NULL){
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			if (ppTABvalues[i]!=NULL)delete[] ppTABvalues[i];
		}
		uiTABnbRows = 0;
		uiTABnbColumns = 0;

		delete[] ppTABvalues;
	}
	else if(uiTABnbRows!=0 || uiTABnbColumns!=0){
		uiTABnbRows = 0;
		uiTABnbColumns = 0;
		printf("Avertissement : pointeur null ici sur ppTABvalue dans la fonction ~Ctable2D , uiTABnbRows = %d et uiTABnbColumns = %d ! \n", uiTABnbRows , uiTABnbColumns);
	}

}

/*
* Get the number of row of the Ctable2D
* @param : void
* @return : unsigned int : the number of rows
*/
template <class MType> unsigned int Ctable2D<MType>::TABgetNbRows()const{
	return uiTABnbRows;
}

/*
* Get the number of columns of the Ctable2D
* @param : void
* @return : unsigned int : the number of columns
*/
template <class MType> unsigned int Ctable2D<MType>::TABgetNbColumns()const{
	return uiTABnbColumns;
}

/*
* Get the values of the Ctable2D
* @param : void
* @return :MType** : the values
*/
template <class MType> MType** Ctable2D<MType>::TABgetValues()const{
	return ppTABvalues;
}

/**
* Set a new matrix to the Ctable2D. It delete the last ppTABvalues, and take the ppValues to replace it.
* @param :
* MType** ppValues : new matrix to set 
* unsigned int uiNbRows : new number of rows
* unsigned int uiNbColumns : new number of columns
* @return : void
*/
template <class MType> void Ctable2D<MType>::TABsetValues(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns) throw (Cexception){

	if (ppValues == NULL && (uiNbRows != 0 || uiNbColumns != 0)){
		//exception in case of not allocated ppTABvalues and number of row and columns different of 0, this should not appear if we use getter, setter, and constructor
		Cexception exc(ERROR_MATRIX_NULL_AND_ROWS_COLUMNS_NOT_NULL);
		throw exc;
	}
	else if (ppTABvalues == NULL){
		ppTABvalues = ppValues;
	}
	else{
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			delete ppTABvalues[i];
		}
		delete ppTABvalues;
		ppTABvalues = ppValues;
	}
	uiTABnbRows = uiNbRows;
	uiTABnbColumns = uiNbColumns;
}

/**
* Set a new matrix to the Ctable2D. It replace a value at poisition (uiIndexRows, uiIndexColumns) by the MTvalue.
* @param :
* MType MTvalue : value to set
* unsigned int uiNbRows : new number of rows
* unsigned int uiNbColumns : new number of columns
* @return : void
*/
template <class MType> void Ctable2D<MType>::TABsetValue(unsigned int uiIndexRows, unsigned int uiIndexColumns, MType MTvalue){
	ppTABvalues[uiIndexRows][uiIndexColumns] = MTvalue;
}

/**
* Print a Ctable2D.
* @param : void
* @return : void
*/
template <class MType> void Ctable2D<MType>::TABprintf()const throw (Cexception){
	if (ppTABvalues == NULL){
		//exception in case of not allocated ppTABvalues, this should not appear if we use getter, setter, and constructor
		Cexception exc(ERROR_MATRIX_NULL);
		throw exc;
	}
	else{
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			printf("\n");
			for (unsigned int j = 0; j < uiTABnbColumns; j++){
				printf(" %f ", (double)ppTABvalues[i][j]);
			}
		}
	}
	printf("\n");
}

/**
* Print to screen the values of the Ctable2D with the desired format.
* @param : const char * format : The String containing the desired format (like printf() format) .
* @return : void
*/
template <class MType> void Ctable2D<MType>::TABprintf(const char * format)const throw (Cexception){
	if (ppTABvalues == NULL){
		//exception in case of not allocated ppTABvalues, this should not appear if we use getter, setter, and constructor
		Cexception exc(ERROR_MATRIX_NULL);
		throw exc;
	}
	else{
		for (unsigned int i = 0; i < uiTABnbRows; i++){
			printf("\n");
			for (unsigned int j = 0; j < uiTABnbColumns; j++){
				printf(format, (double)ppTABvalues[i][j]);
			}
		}
		printf("\n\n\n");
	}
}

/**
* Create a new Ctable2D with the value of the Ctable2D in parameter.
* @param : const Ctable2D &table : the Ctable2D to copy
* @return : Ctable2D<MType> : return a pointer on the object who call the function
*/
template <class MType> Ctable2D<MType> &Ctable2D<MType>::operator=(const Ctable2D &table){
	Ctable2D(&table);
	return *this;
}

/**
* Test if two Ctable are equal
* @param : const Ctable2D<MType> &TABtableToCompare : The Ctable2D to compare
* @return : bool : return True if the two Ctable2D are equal , False if not.
*/
template <class MType> bool Ctable2D<MType>::operator==(const Ctable2D<MType> &TABtableToCompare)const{
	if (uiTABnbRows != TABtableToCompare.uiTABnbRows || uiTABnbColumns != TABtableToCompare.uiTABnbColumns){
		return false;
	}
	
	for (unsigned int i = 0; i < uiTABnbRows; i++){
		for (unsigned int j = 0; j < uiTABnbColumns; j++){
			if (ppTABvalues[i][j] != TABtableToCompare.ppTABvalues[i][j]){
				return false;
			}
		}
	}

	return true;
}

/**
* Test if two Ctable2D are not equal. 
* @param : const Ctable2D<MType> &TABtableToCompare : The Ctable2d to compare.
* @return : bool : True if the two Ctable2D are not equal , False if they are.
*/
template <class MType> bool Ctable2D<MType>::operator!=(const Ctable2D<MType> &TABtableToCompare)const{

	if (uiTABnbRows != TABtableToCompare.uiTABnbRows || uiTABnbColumns != TABtableToCompare.uiTABnbColumns){
		return false;
	}

	for (unsigned int i = 0; i < uiTABnbRows; i++){
		for (unsigned int j = 0; j < uiTABnbColumns; j++){
			if (ppTABvalues[i][j] != TABtableToCompare.ppTABvalues[i][j]){
				return true;
			}
		}
	}
	return false;
}