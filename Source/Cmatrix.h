#pragma once

#ifndef CMATRIX_H
#include "stdafx.h"

#define ERROR_DIVISION_BY_0 20
#define ERROR_NUMBER_OF_ROWS_OR_COLUMNS_NOT_EQUAL 21
#define ERROR_PARAM_IS_NULL 22
#define ERROR_MULTIPLICATION_IMPOSSIBLE 23
template <class MType>
class Ctable2D;

template <class  MType>
class Cmatrix : public Ctable2D < MType >
{

public:

	/*
	* This constructor build a new Cmatrix with null values.
	* @param : void
	* @return : void
	* @do : initialize a Cmatrix with null values.
	*/
	Cmatrix<MType>();

	/*
	* This constructor build a new Cmatrix with the value of another Cmatrix in parameter.
	* If the Cmatrix in parameter is null , it throw an exception (return Ctable will be set with null values).
	* @param : const Cmatrix &table : Cmatrix to copy
	* @return : void
	*/
	Cmatrix<MType>(const Cmatrix<MType> &param1);

	/*
	* This constructor build a new Cmatrix with uiNbRows number of rows, and uiNbColumns number of columns.
	* The value of the matrix are initialized to 0.
	* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
	* @param :
	* unsigned int uiNbRows : number of row to set
	* unsigned int uiNbColumns : number of columns to set
	* @return : void
	*/
	Cmatrix<MType>(unsigned int uiNbRows, unsigned int uiNbColumns);

	/*
	* This constructor build a new Cmatrix with uiNbRows number of rows, and uiNbColumns number of columns.
	* The value of the matrix are initialized with the param MTvalue.
	* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
	* @param :
	* unsigned int uiNbRows : number of row to set
	* unsigned int uiNbColumns : number of columns to set
	* MType MTvalue : the value to set in the table
	* @return : void
	*/
	Cmatrix<MType>(unsigned int uiNbRows, unsigned int uiNbColumns, MType MTvalue);

	/**
	* This constructor build a new Cmatrix with value of the two dimension table ppValues, uiNbRows and uiNbColumns need to be the dimension of ppValues.
	* If one of the uiNbRows or uiNbColumns is not null and if ppValues is null , it return an exception because the value of uiNbColumns and uiNbRows are different to the real dimension of ppValues.
	* @param :
	* MType** ppValues : new matrix to set
	* unsigned int uiNbRows : new number of rows
	* unsigned int uiNbColumns : new number of columns
	* @return : void
	*/
	Cmatrix<MType>(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns);

	/*
	* This Constructor build a new Cmatrix with the value of Cfile. It is important to call the constructor with the correct type contained inside the file.
	* The String values of the matrix of the file are converted with the function stod , then the Double result will be cast with the wanted Type.
	* So there will be no loss due to the conversion as you use the correct type of the matrix.
	* @param : Cfile &file
	* @return : void
	*/
	Cmatrix(const char *pcFile_to_parse);

	/*
	* This is the destructor of Cmatrix, it delete correctly the object.
	* If the ppTABvalues is null but uiTABnbRows or uiTABnbColumns are not, it show a warning.
	* @param : void
	* @return : void
	*/
	~Cmatrix<MType>();

	/*
	* Transpose the matrix.
	* @param : void.
	* @return : Cmatrix<MType> * : a new matrix who contain the result.
	*/
	Cmatrix<MType> *  MATtranspose();

};

template <class  MType> Cmatrix<MType> * operator*(const Cmatrix<MType> &MATmatrix, double dScalar);
template <class  MType> Cmatrix<MType> * operator/(const Cmatrix<MType> &MATmatrix, double dScalar);
template <class  MType> Cmatrix<MType> * operator*(double dScalar, const Cmatrix<MType> &MATmatrix);
template <class  MType> Cmatrix<MType> * operator/(double dScalar, const Cmatrix<MType> &MATmatrix);
template <class  MType> Cmatrix<MType> * operator+(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoAdd) throw (Cexception);
template <class  MType> Cmatrix<MType> * operator-(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoSub) throw (Cexception);
template <class  MType> Cmatrix<MType> * operator*(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoMult) throw (Cexception);
/*
* Do the base switch of a vector
* @param :
*		Cmatrix<MType> ** pMatrixTable : table of Cmatrix, first object need to be the vector we want to base switch, other object need to be in order the switch matrix.
*		unsigned int uiNbMatrixRead : number of Cmatrix in the pMatrixTable
* @return : Cmatrix<MType> * : a pointer on the result of base switch vector.
* Could throw exception if multiplication can't be done
*
*/
template <class  MType> Cmatrix<MType> * switchBases(Cmatrix<MType> ** pMatrixTable, unsigned int uiNbMatrixRead) throw (Cexception);

#endif

/*
* This constructor build a new Cmatrix with null values.
* @param : void
* @return : void
* @do : initialize a Cmatrix with null values.
*/
template <class  MType> Cmatrix<MType>::Cmatrix(){
	//call Ctable2D default constructor Ctable2D()
}

/*
* This constructor build a new Cmatrix with uiNbRows number of rows, and uiNbColumns number of columns.
* The value of the matrix are initialized to 0.
* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
* @param :
* unsigned int uiNbRows : number of row to set
* unsigned int uiNbColumns : number of columns to set
* @return : void
*/
template <class  MType> Cmatrix<MType>::Cmatrix(unsigned int uiNbRows, unsigned int uiNbColumns) : Ctable2D<MType>(uiNbRows, uiNbColumns){
	//call Ctable2D constructor  Ctable2D(uiNbRows, uiNbColumns)
}

/*
* This constructor build a new Cmatrix with uiNbRows number of rows, and uiNbColumns number of columns.
* The value of the matrix are initialized with the param MTvalue.
* If there is less than one row or one columns the ppTABvalues is null, and uiNbRows and uiNbColumns are set to 0.
* @param :
* unsigned int uiNbRows : number of row to set
* unsigned int uiNbColumns : number of columns to set
* MType MTvalue : the value to set in the table
* @return : void
*/
template <class  MType> Cmatrix<MType>::Cmatrix(unsigned int uiNbRows, unsigned int uiNbColumns, MType MTvalue) : Ctable2D<MType>(uiNbRows, uiNbColumns, MTvalue){
	//call Ctable2D constructor  Ctable2D(uiNbRows, uiNbColumns)
}

/**
* This constructor build a new Cmatrix with value of the two dimension table ppValues, uiNbRows and uiNbColumns need to be the dimension of ppValues.
* If one of the uiNbRows or uiNbColumns is not null and if ppValues is null , it return an exception because the value of uiNbColumns and uiNbRows are different to the real dimension of ppValues.
* @param :
* MType** ppValues : new matrix to set
* unsigned int uiNbRows : new number of rows
* unsigned int uiNbColumns : new number of columns
* @return : void
*/
template <class  MType> Cmatrix<MType>::Cmatrix(MType** ppValues, unsigned int uiNbRows, unsigned int uiNbColumns) : Ctable2D<MType>(ppValues, uiNbRows, uiNbColumns){
	//call Ctable2D constructor
}

/*
* This constructor build a new Cmatrix with the value of another Cmatrix in parameter.
* If the Cmatrix in parameter is null , it throw an exception (return Ctable will be set with null values).
* @param : const Cmatrix &table : Cmatrix to copy
* @return : void
*/
template <class  MType> Cmatrix<MType>::Cmatrix(const Cmatrix<MType> &param1) : Ctable2D<MType>(param1){
	//call Ctable2D default copy constructor Ctable2D(&param1)
}

/*
* This Constructor build a new Cmatrix with the value of Cfile. It is important to call the constructor with the correct type contained inside the file.
* The String values of the matrix of the file are converted with the function stod , then the Double result will be cast with the wanted Type.
* So there will be no loss due to the conversion as you use the correct type of the matrix.
* @param : Cfile &file
* @return : void
*/
template <class  MType> Cmatrix<MType>::Cmatrix(const char *pcFile_to_parse) : Ctable2D(pcFile_to_parse){
	//call the Ctable2D constructor
}

/*
* This is the destructor of Cmatrix, it delete correctly the object.
* If the ppTABvalues is null but uiTABnbRows or uiTABnbColumns are not, it show a warning.
* @param : void
* @return : void
*/
template <class  MType> Cmatrix<MType>::~Cmatrix(){
	// Call destructor of Ctable2D
}


/*
* Multiplication a matrix by a scalar.
* @param :
* const Cmatrix<MType> &MATmatrix : Matrix to multiply.
* double dScalar : scalar of the multiplication.
* @return : Cmatrix<MType> * : a new matrix who contain the result.
*/
template <class  MType> Cmatrix<MType> * operator*(const Cmatrix<MType> &MATmatrix, double dScalar){

	MType ** MTtable = NULL;
	//if the number of columns or the number of row is null there is no element in the table, so we return a void matrix.
	if (MATmatrix.TABgetNbColumns() >0 && MATmatrix.TABgetNbRows() > 0){
		MTtable = new MType*[MATmatrix.TABgetNbRows()];
		//otherwise we browse the matrix and do the multiplication with the scalar member by member, and return a result matrix.
		for (unsigned int i = 0; i < MATmatrix.TABgetNbRows(); i++){
			MTtable[i] = new MType[MATmatrix.TABgetNbColumns()];
			for (unsigned int j = 0; j < MATmatrix.TABgetNbColumns(); j++){
				MTtable[i][j] = MATmatrix.TABgetValues()[i][j] * dScalar;
			}
		}
	}
	Cmatrix<double> * NewMat = new Cmatrix<MType>(MTtable, MATmatrix.TABgetNbRows(), MATmatrix.TABgetNbColumns());;
	return NewMat;
}

template <class  MType> Cmatrix<MType> * operator*(double dScalar, const Cmatrix<MType> &MATmatrix){
	return MATmatrix * dScalar;
}
/*
* Division a matrix by a scalar.
* @param :
* const Cmatrix<MType> &MATmatrix : Matrix to divise.
* double dScalar : scalar of the division.
* @return : Cmatrix<MType> * : a new matrix who contain the result.
*/
template <class  MType> Cmatrix<MType> * operator/(const Cmatrix<MType> &MATmatrix, double dScalar) throw (Cexception) {
	if (dScalar == 0){
		Cexception exc;
		exc.EXCsetValue(ERROR_DIVISION_BY_0);
		throw exc;
	}

	MType ** MTtable = NULL;
	//if the number of columns or the number of row is null there is no element in the table, so we return a void matrix.
	if (MATmatrix.TABgetNbColumns() >0 && MATmatrix.TABgetNbRows() > 0){
		MTtable = new MType*[MATmatrix.TABgetNbRows()];
		//otherwise we browse the matrix and do the multiplication with the scalar member by member, and return a result matrix.
		for (unsigned int i = 0; i < MATmatrix.TABgetNbRows(); i++){
			MTtable[i] = new MType[MATmatrix.TABgetNbColumns()];
			for (unsigned int j = 0; j < MATmatrix.TABgetNbColumns(); j++){
				MTtable[i][j] = MATmatrix.TABgetValues()[i][j] / dScalar;
			}
		}
	}
	Cmatrix<double> * NewMat = new Cmatrix<MType>(MTtable, MATmatrix.TABgetNbRows(), MATmatrix.TABgetNbColumns());
	return NewMat;
}

template <class  MType> Cmatrix<MType> * operator/(double dScalar, const Cmatrix<MType> &MATmatrix){
	return MATmatrix / dScalar;
}

/*
* Transpose the matrix.
* @param : void.
* @return : Cmatrix<MType> * : a new matrix who contain the result.
*/
template <class  MType> Cmatrix<MType> * Cmatrix<MType>::MATtranspose(){
	unsigned int uiNbColumns = TABgetNbRows();
	unsigned int uiNbRows = TABgetNbColumns();

	MType ** ppValues = new MType*[uiNbRows];
	for (unsigned int i = 0; i < uiNbRows; i++){
		ppValues[i] = new MType[uiNbColumns];
		for (unsigned int j = 0; j < uiNbColumns; j++){
			ppValues[i][j] = TABgetValues()[j][i];
		}
	}

	Cmatrix<MType> * NewMat = new Cmatrix<MType>(ppValues, uiNbRows, uiNbColumns);
	return NewMat;
}

/*
* Do the Addition between two matrix.
* ( Matrix need to have same dimension)
* @param : const Cmatrix<MType> MATtoSub : The matrix to add.
* @return : Cmatrix<MType> * : a new matrix who contain the result.
* Throw an exception if the operation can't be done because of matrix with different dimension.
*/
template <class  MType> Cmatrix<MType> * operator+(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoAdd) throw (Cexception) {

	unsigned int uiNbColumns = MATmatrix.TABgetNbColumns();
	unsigned int uiNbRows = MATmatrix.TABgetNbRows();
	if (uiNbColumns == MATtoAdd.TABgetNbColumns() && uiNbRows == MATtoAdd.TABgetNbRows()){
		MType ** ppValues = new MType*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			ppValues[i] = new MType[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				ppValues[i][j] = MATmatrix.TABgetValues()[i][j] + MATtoAdd.TABgetValues()[i][j];
			}
		}

		Cmatrix<MType> * NewMat = new Cmatrix<MType>(ppValues, uiNbRows, uiNbColumns);
		return NewMat;
	}
	else{
		Cexception exc;
		exc.EXCsetValue(ERROR_NUMBER_OF_ROWS_OR_COLUMNS_NOT_EQUAL);
		throw exc;
		return NULL;
	}
}
/*
* Do the substraction between two matrix. Matrix in param will be removed from matrix who call the operator.
* ( Matrix need to have same dimension)
* @param : const Cmatrix<MType> MATtoSub : The matrix to substract from this.
* @return : Cmatrix<MType> * : a new matrix who contain the result.
* Throw an exception if the operation can't be done because of matrix with different dimension.
*/
template <class  MType> Cmatrix<MType> * operator-(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoSub) throw (Cexception){

	unsigned int uiNbColumns = MATmatrix.TABgetNbColumns();
	unsigned int uiNbRows = MATmatrix.TABgetNbRows();
	if (uiNbColumns == MATtoSub.TABgetNbColumns() && uiNbRows == MATtoSub.TABgetNbRows()){
		MType ** ppValues = new MType*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			ppValues[i] = new MType[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				ppValues[i][j] = MATmatrix.TABgetValues()[i][j] - MATtoSub.TABgetValues()[i][j];
			}
		}

		Cmatrix<MType> * NewMat = new Cmatrix<MType>(ppValues, uiNbRows, uiNbColumns);
		return NewMat;
	}
	else{
		Cexception exc;
		exc.EXCsetValue(ERROR_NUMBER_OF_ROWS_OR_COLUMNS_NOT_EQUAL);
		throw exc;
		return NULL;
	}
}

/*
* Do the multiplication of two matrix, matrix on left need to have same amount of row as matrix on the right has columns.
* @param : const Cmatrix<MType> MATtoMult : second matrix to do the multiplication.
* @return : Cmatrix<MType> * : a new Cmatrix who contain the result of the multiplication.
* If the multiplication cannot be done it throw an exception.
*/
template <class  MType> Cmatrix<MType> * operator*(const Cmatrix<MType> &MATmatrix, const Cmatrix<MType> &MATtoMult) throw (Cexception){


	if (MATmatrix.TABgetNbColumns() == MATtoMult.TABgetNbRows()){

		unsigned int uiNbDim = MATmatrix.TABgetNbColumns();

		MType ** ppValues = new MType*[MATmatrix.TABgetNbRows()];
		for (unsigned int i = 0; i < MATmatrix.TABgetNbRows(); i++){
			ppValues[i] = new MType[MATtoMult.TABgetNbColumns()];

			for (unsigned int j = 0; j < MATtoMult.TABgetNbColumns(); j++){
				ppValues[i][j] = 0;

				for (unsigned int k = 0; k < uiNbDim; k++){
					ppValues[i][j] = ppValues[i][j] + MATmatrix.TABgetValues()[i][k] * MATtoMult.TABgetValues()[k][j];
				}

			}

		}
		Cmatrix<MType> * NewMat = new Cmatrix<MType>(ppValues, MATmatrix.TABgetNbRows(), MATtoMult.TABgetNbColumns());
		return NewMat;
	}
	else{
		Cexception exc;
		exc.EXCsetValue(ERROR_MULTIPLICATION_IMPOSSIBLE);
		throw exc;
	}
}


/*
* Do the base switch of a vector
* @param :
*		Cmatrix<MType> ** pMatrixTable : table of Cmatrix, first object need to be the vector we want to base switch, other object need to be in order the switch matrix.
*		unsigned int uiNbMatrixRead : number of Cmatrix in the pMatrixTable
* @return : Cmatrix<MType> * : a pointer on the result of base switch vector.
* Could throw exception if multiplication can't be done
*
*/
template <class  MType> Cmatrix<MType> * switchBases(Cmatrix<MType> ** pMatrixTable, unsigned int uiNbMatrixRead){
	Cmatrix<double> * pVectorResult = new Cmatrix<double>();
	pVectorResult = pMatrixTable[0];
	std::cout << "Vecteur pass\x082 en param\x08A" << "tre : " << std::endl;
	pVectorResult->TABprintf();
	//transpose vector if this is a column vector
	if (pVectorResult->TABgetNbColumns() < pVectorResult->TABgetNbRows()){
		Cmatrix<double> * pTranpose = pVectorResult->MATtranspose();
		delete pVectorResult;
		pVectorResult = pTranpose;
		std::cout << "Avertissement : Le vecteur a \x082" << "t\x082 transpos\x082 pour faire les op\x082" << "rations " << std::endl;
	}
	if (pVectorResult->TABgetNbRows() != 1 && pVectorResult->TABgetNbColumns() > 1){
		printf("\n Avertissement : Le premier argument n'est pas un vecteur ! \n");
	}
	//do the multiplication of vector with all switch matrix
	for (unsigned int uiIndexOfMatrix = 1; uiIndexOfMatrix < uiNbMatrixRead; uiIndexOfMatrix++){
		pVectorResult = (*pVectorResult**pMatrixTable[uiIndexOfMatrix]);
		printf("\n Etape %d du changement de base : \n", uiIndexOfMatrix);
		pVectorResult->TABprintf();

	}
	//printf result
	std::cout << "\n Voici le r\x082" << "sultat du changement de base : " << std::endl;
	pVectorResult->TABprintf();

	return pVectorResult;
}