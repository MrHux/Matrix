#pragma once
#include "stdafx.h"

#ifndef NDEBUG

class CfileUNIT
{
public:
	/*
	-- Unit test for Cfile parsing method --

	Input : nothing
	Prerequisite : none
	Output : nothing
	Lead to : If the parsing method doesn't return a proper table of values, the test fail and the program is aborded.
	*/
	static void FUTtestParsingMethod();

};

#endif