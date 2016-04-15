#include "stdafx.h"

#ifndef NDEBUG 
void CmatrixUNIT::testCmatrix(){
	Cmatrix<int> *  MATmatrice = new Cmatrix<int>();

	assert(MATmatrice->TABgetNbRows() == 0);
	assert(MATmatrice->TABgetNbColumns() == 0);
	assert(MATmatrice->TABgetValues() == NULL);

	delete MATmatrice;

	MATmatrice = new Cmatrix<int>(3, 4);

	assert(MATmatrice->TABgetNbRows() == 3);
	assert(MATmatrice->TABgetNbColumns() == 4);
	assert(MATmatrice->TABgetValues() != NULL);
}

void CmatrixUNIT::testOperatorEqual(){

}

void CmatrixUNIT::testMATscalarMultiplication(){
	
	Cmatrix<double> *  MATmatrice = new Cmatrix<double>(5,5);

	unsigned int uiNbRows = MATmatrice->TABgetNbRows();
	unsigned int uiNbColumns = MATmatrice->TABgetNbColumns();

	double ** MTtable = NULL;
	if ( uiNbRows> 0 && uiNbColumns > 0){
		MTtable = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = 10;
			}
		}
	}
	MATmatrice->TABsetValues(MTtable, uiNbRows, uiNbColumns);

	Cmatrix<double> *  MATmatrice2 = new Cmatrix<double>(5, 5);

	uiNbRows = MATmatrice2->TABgetNbRows();
	uiNbColumns = MATmatrice2->TABgetNbColumns();

	double ** MTtable2 = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable2 = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable2[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable2[i][j] = 5;
			}
		}
	}
	MATmatrice2->TABsetValues(MTtable2, uiNbRows, uiNbColumns);

	assert(*MATmatrice != *MATmatrice2);

	Cmatrix<double> * MATmatrice3;
	MATmatrice3 = *MATmatrice2*2;

	assert(*MATmatrice == *MATmatrice3);	

	MATmatrice3 = 2 * *MATmatrice2 ;

	assert(*MATmatrice == *MATmatrice3);
}

void CmatrixUNIT::testMATscalarDivision(){
		
	Cmatrix<double> *  MATmatrice = new Cmatrix<double>(5, 5);

	unsigned int uiNbRows = MATmatrice->TABgetNbRows();
	unsigned int uiNbColumns = MATmatrice->TABgetNbColumns();

	double ** MTtable = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = 5;
			}
		}
	}
	MATmatrice->TABsetValues(MTtable, uiNbRows, uiNbColumns);

	Cmatrix<double> *  MATmatrice2 = new Cmatrix<double>(5, 5);

	uiNbRows = MATmatrice2->TABgetNbRows();
	uiNbColumns = MATmatrice2->TABgetNbColumns();

	double ** MTtable2 = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable2 = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable2[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable2[i][j] = 10;
			}
		}
	}
	MATmatrice2->TABsetValues(MTtable2, uiNbRows, uiNbColumns);

	assert(*MATmatrice != *MATmatrice2);

	Cmatrix<double> * MATmatrice3;
	MATmatrice3 = *MATmatrice2 / 2;

	assert(*MATmatrice == *MATmatrice3);

	MATmatrice3 = 2 / *MATmatrice2;

	assert(*MATmatrice == *MATmatrice3);
}


void CmatrixUNIT::testMATtranspose(){
	Cmatrix<double> *  MATmatrice = new Cmatrix<double>(5, 3);

	unsigned int uiNbRows = MATmatrice->TABgetNbRows();
	unsigned int uiNbColumns = MATmatrice->TABgetNbColumns();

	double ** MTtable = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = rand() % 10;
			}
		}
	}
	MATmatrice->TABsetValues(MTtable, uiNbRows, uiNbColumns);
	
	/*printf("\n\n\n\n");

	MATmatrice->TABprintf();

	printf("\n\n\n\n");

	MATmatrice->MATtranspose()->TABprintf();

	printf("\n\n\n\n");

	MATmatrice->MATtranspose()->MATtranspose()->TABprintf();*/

	assert(*MATmatrice->MATtranspose()->MATtranspose() == *MATmatrice);
}

void CmatrixUNIT::testMATaddition(){
	Cmatrix<double> *  MATmatrice = new Cmatrix<double>(5, 5);

	unsigned int uiNbRows = MATmatrice->TABgetNbRows();
	unsigned int uiNbColumns = MATmatrice->TABgetNbColumns();

	double ** MTtable = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = 5;
			}
		}
	}
	MATmatrice->TABsetValues(MTtable, uiNbRows, uiNbColumns);

	Cmatrix<double> *  MATmatrice2 = new Cmatrix<double>(5, 5);

	uiNbRows = MATmatrice2->TABgetNbRows();
	uiNbColumns = MATmatrice2->TABgetNbColumns();

	double ** MTtable2 = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable2 = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable2[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable2[i][j] = 10;
			}
		}
	}
	MATmatrice2->TABsetValues(MTtable2, uiNbRows, uiNbColumns);

	Cmatrix<double> * MATmatrice3 = (*MATmatrice + *MATmatrice);
	assert(*MATmatrice2 == *MATmatrice3);

	/*MATmatrice->TABprintf();

	printf("\n\n\n\n");

	MATmatrice2->TABprintf();

	printf("\n\n\n\n");

	MATmatrice3->TABprintf();*/
}

void CmatrixUNIT::testMATsubstraction(){
	Cmatrix<double> *  MATmatrice = new Cmatrix<double>(5, 5);

	unsigned int uiNbRows = MATmatrice->TABgetNbRows();
	unsigned int uiNbColumns = MATmatrice->TABgetNbColumns();

	double ** MTtable = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable[i][j] = 5;
			}
		}
	}
	MATmatrice->TABsetValues(MTtable, uiNbRows, uiNbColumns);

	Cmatrix<double> *  MATmatrice2 = new Cmatrix<double>(5, 5);

	uiNbRows = MATmatrice2->TABgetNbRows();
	uiNbColumns = MATmatrice2->TABgetNbColumns();

	double ** MTtable2 = NULL;
	if (uiNbRows> 0 && uiNbColumns > 0){
		MTtable2 = new double*[uiNbRows];
		for (unsigned int i = 0; i < uiNbRows; i++){
			MTtable2[i] = new double[uiNbColumns];
			for (unsigned int j = 0; j < uiNbColumns; j++){
				MTtable2[i][j] = 10;
			}
		}
	}
	MATmatrice2->TABsetValues(MTtable2, uiNbRows, uiNbColumns);

	assert(*MATmatrice == *(*MATmatrice2 - *MATmatrice));
}

void CmatrixUNIT::testMATmultiplication()
{
	Cmatrix<double> *  mat1 = new Cmatrix<double>(1, 3);
	Cmatrix<double> *  mat2 = new Cmatrix<double>(3, 2);

	mat1->TABsetValue(0, 0, 1);
	mat1->TABsetValue(0, 1, 2);
	mat1->TABsetValue(0, 2, 3);

	mat2->TABsetValue(0, 0, 2);
	mat2->TABsetValue(0, 1, 2);

	mat2->TABsetValue(1, 0, 3);
	mat2->TABsetValue(1, 1, 3);

	mat2->TABsetValue(2, 0, 4);
	mat2->TABsetValue(2, 1, 4);

	Cmatrix<double> *result1 = new Cmatrix<double>(1, 2);
	result1 = (*mat1) * (*mat2);

	// Result of mat1 * mat2 is [20, 20]
	Cmatrix<double> *result1_expected = new Cmatrix<double>(1, 2, 20);

	assert((* result1_expected) == (* result1));

	/****************************************/

	Cmatrix<double> *result2 = new Cmatrix<double>(0, 0);
	try
	{
		result2 = (*mat2) * (*mat1); // Impossible : should throw a Cexception
		assert(false); // Should NOT execute this
	}
	catch (Cexception exc)
	{
		if (exc.EXCgetValue() == ERROR_MULTIPLICATION_IMPOSSIBLE)
		{
			// Should execute this
			assert(true);
		}
		else
		{
			// Should NOT execute this : bad Cexception type
			assert(false);
		}
	}


}
#endif