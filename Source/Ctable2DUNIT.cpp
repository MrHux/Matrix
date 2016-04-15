#include "stdafx.h"
#include "Ctable2DUNIT.h"


#ifndef NDEBUG 
void Ctable2DUNIT::testCtable2D(){
	Ctable2D<double> * TABtableTest = new Ctable2D<double>();
	
	assert(TABtableTest->TABgetNbRows() == 0);
	assert(TABtableTest->TABgetNbColumns() == 0);
	assert(TABtableTest->TABgetValues() == NULL);

	Ctable2D<double> * TABtableTest2 = new Ctable2D<double>(3, 4);

	assert(TABtableTest2->TABgetNbRows() == 3);
	assert(TABtableTest2->TABgetNbColumns() == 4);
	assert(TABtableTest2->TABgetValues() != NULL);

	Ctable2D<double> * TABtableTest3 = new Ctable2D<double>(INPUT_FILE1);

	assert(TABtableTest3->TABgetNbRows() == 2);
	assert(TABtableTest3->TABgetNbColumns() == 3);
	assert(TABtableTest3->TABgetValues() != NULL);

	Ctable2D<double> * TABtableTest4 = new Ctable2D<double>(INPUT_FILE3);

	assert(TABtableTest4->TABgetNbRows() == 1);
	assert(TABtableTest4->TABgetNbColumns() == 1);
	assert(TABtableTest4->TABgetValues()[0][0] == 42);
}

void Ctable2DUNIT::testOperatorEqualEqual(){
	Ctable2D<double> * TABtableTest = new Ctable2D<double>(2,2);
	Ctable2D<double> * TABtableTest2 = new Ctable2D<double>(2,3);

	assert(TABtableTest != TABtableTest2);
	

	delete TABtableTest;
	delete TABtableTest2;

	TABtableTest = new Ctable2D<double>(2, 2);
	TABtableTest2 = new Ctable2D<double>(2, 2);

	assert(*TABtableTest == *TABtableTest2 );
}

void Ctable2DUNIT::testOperatorEqual(){
	Ctable2D<double> * TABtableTest = new Ctable2D<double>(2, 2);
	Ctable2D<double> * TABtableTest2 = TABtableTest;

	assert(TABtableTest == TABtableTest2);
}
#endif