#pragma once
#include "stdafx.h"

#ifndef NDEBUG 
#include <assert.h>

class CmatrixUNIT
{
public:

	static void testCmatrix();

	static void testOperatorEqual();

	static void testMATscalarMultiplication();

	static void testMATscalarDivision();

	static void testMATtranspose();

	static void testMATaddition();

	static void testMATsubstraction();

	static void testMATmultiplication();


};

#endif