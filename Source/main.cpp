#include "stdafx.h"

// To test an imput file, set the program's arguments to a file in the folder File_test\in
// ie. ".\\File_Test\\in\\mat1.txt"

void computationOnMatrices(Cmatrix<double> **pMatrixTable, unsigned int uiNbMatrixRead);

int main(int argc, char* argv[])
{
	std::cout << "Projet C++ - Matrices - Mathieu Boutolleau & Paul Fayoux" << std::endl << std::endl;

	#ifndef NDEBUG 
		// Unit tests, only in DEBUG target
		std::cout << "------ Debut des tests unitaires ------" << std::endl << std::endl;

		try
		{
			std::cout << "debut test Cfile" << std::endl;
			CfileUNIT::FUTtestParsingMethod();
			std::cout << "fin test Cfile" << std::endl << std::endl;

			std::cout << "debut test Ctable2D" << std::endl;
			Ctable2DUNIT::testCtable2D();
			Ctable2DUNIT::testOperatorEqualEqual();
			Ctable2DUNIT::testOperatorEqual();
			std::cout << "fin test Ctable2D" << std::endl << std::endl;

			std::cout << "debut test Cmatrix" << std::endl;
			CmatrixUNIT::testCmatrix();
			CmatrixUNIT::testMATscalarMultiplication();
			CmatrixUNIT::testMATscalarDivision();
			CmatrixUNIT::testMATtranspose();
			CmatrixUNIT::testMATaddition();
			CmatrixUNIT::testMATsubstraction();
			CmatrixUNIT::testMATmultiplication();
			std::cout << "fin test Cmatrix" << std::endl << std::endl;
		}
		catch (Cexception exc)
		{
			std::cout << "Exception levee : #" << exc.EXCgetValue() << std::endl;
			std::terminate();
		}

		std::cout << "------ Fin des tests unitaires ------" << std::endl;
	#endif

	// If there is at least one file to parse
	if (argc > 1)
	{
		// Number of the operation chosen to do on run-time
		unsigned int uiChooseOperation = 0;

		Cmatrix<double> *matrixParsed = NULL;

		// Dynamically allocated list of matrices
		Cmatrix<double> **pMatrixTable = new Cmatrix<double>*[argc - 1];

		unsigned int uiMatrixIndex = 0;
		unsigned int uiNbMatrixRead = 0;

		// Parsing the files to get matrix
		for (int i = 1; i < argc; i++)
		{
			std::cout << std::endl << "Traitement du fichier \"" << argv[i] << "\"," << std::endl;
			std::cout << "matrice : Mat " << uiMatrixIndex << " = " << std::endl;
			try
			{
				// Creating the matrix associated to the file read (if possible)
				matrixParsed = new Cmatrix<double>(argv[i]);
			}
			catch (Cexception exc)
			{
				// File can't be read, file's syntax is invalid or matrix type read is invalid (not double), we don't create the representative matrix
				// but continue by parsing the next file (if there is one)
				std::cout << "Avertissement : Fichier invalide, traitement interrompu, Mat" << uiMatrixIndex << " sera utilisee pour le fichier suivant." << std::endl;
				pMatrixTable[i - 1] = NULL;
				continue;
			}
			// Valid file, we create the representative matrix and print it so the user can check
			pMatrixTable[uiMatrixIndex] = new Cmatrix<double>(*matrixParsed);
			pMatrixTable[uiMatrixIndex]->TABprintf();

			uiMatrixIndex++;
		}

		// Storing the number of matrices created
		uiNbMatrixRead = uiMatrixIndex;

		// If we have created at least 1 valid matrix
		if (uiNbMatrixRead > 0)
		{
			// While the choice made by the user is invalid, prompt again
			while (uiChooseOperation != 1 && uiChooseOperation != 2 && uiChooseOperation != 3){
				std::cout << std::endl << "Veuiller choisir l'op\x082" << "ration \x085 faire :" << std::endl << std::endl;

				std::cout << "1 - Changement de base du vecteur pass\x082 en premier argument" << std::endl;
				std::cout << "2 - Op\x082" << "rations sur les matrices pass\x082" << "es en argument" << std::endl;
				std::cout << "3 - Quitter" << std::endl << std::endl;
					
				std::cout << "Choix : ";

				// Choose operation to do, if a non number is entered, uiChooseOperation will be equals to 0
				std::cin >> uiChooseOperation;
				if (uiChooseOperation == 0)
				{
					std::cout << std::endl << "\n Avertissement : votre choix est invalide." << std::endl;
				}
				// 1 - Switch matrix base
				else if (uiChooseOperation == 1){
					Cmatrix<double> * pResult = switchBases(pMatrixTable, uiNbMatrixRead);
				}
				// 2 - Computation on matrix
				else if (uiChooseOperation == 2)
				{
					computationOnMatrices(pMatrixTable, uiNbMatrixRead);
				}
				// 3 - Quit
				else if (uiChooseOperation == 3){
					break;
				}
				else if (uiChooseOperation == 42){
					std::cout << "\n Ceci n'est pas un oeuf de p\x083" << "cques ! " << std::endl;
				}
			}
		}
		else
		{
			// No valid matrix created, we have nothing to do
			std::cout << "Avertissement : Aucune matrice n'a pu etre cr\x082" << "e, le programme va se terminer." << std::endl;
		}
	}
	else
	{
		// No file passed in the parameters, we have nothing to do
		std::cout << "Avertissement : Aucun fichier de matrice n'a ete pass\x082 en parametre, le programme va se terminer." << std::endl;
	}

	return 0;
}

void computationOnMatrices(Cmatrix<double> **pMatrixTable, unsigned int uiNbMatrixRead)
{
	// Constant supplied by the user for the computation
	double dConstant = 0;

	std::cout << std::endl << "\n Veuiller entrer une constante c : ";

	// Retrieving the constant, if a non number is entered, dConstant will be equals to 0
	std::cin >> dConstant;
	if (dConstant == 0)
	{
		std::cout << std::endl << "Avertissement : La constante entr\x082" << "e est nulle (\x082" << "gale à 0)." << std::endl;
	}

	std::cout << std::endl << "------ Calcul 1 : Matrice * c ------" << std::endl;
	// 1st calculation - Matrix * constant
	for (unsigned int i = 0; i < uiNbMatrixRead; i++)
	{
		std::cout << std::endl << "Mat" << i << " * c = " << std::endl;
		(*pMatrixTable[i] * dConstant)->TABprintf();
	}

	std::cout << std::endl << "------ Calcul 2 : Matrice / c ------" << std::endl;
	// 2nd calculation - Matrix / constant
	for (unsigned int i = 0; i < uiNbMatrixRead; i++)
	{
		std::cout << std::endl << "Mat" << i << " / c = " << std::endl;
		try
		{
			(*pMatrixTable[i] / dConstant)->TABprintf();
		}
		catch (Cexception exc)
		{
			// Division by 0
			std::cout << "Avertissement : Calcul impossible avec une constante nulle" << std::endl;
			continue;
		}
	}

	std::cout << std::endl << "------ Calcul 3 : Addition de toutes les matrices ------" << std::endl;
	// 3rd calculation - Matrix1 + Matrix2 + ...
	std::cout << std::endl << "R\x082" << "sultat : " << std::endl;
	// If only 1 matrix have been created, the addition result is the matix itself.
	if (uiNbMatrixRead == 1)
	{
		pMatrixTable[0]->TABprintf();
	}
	else
	{
		try
		{
			// The result begin with the addition of the 2 first matrix
			Cmatrix<double> *resultAddition = (*pMatrixTable[0] + *pMatrixTable[1]);
			// We simply add each other matrix to the exixting result
			for (unsigned int i = 2; i < uiNbMatrixRead; i++)
			{
				resultAddition = (*resultAddition + *pMatrixTable[i]);
			}
			resultAddition->TABprintf();
		}
		catch (Cexception exc)
		{
			// Error during addition, incoherent dimensions
			std::cout << "Avertissement : Calcul impossible, les matrices n'ont pas toutes les m\x088" << "mes dimensions" << std::endl;
		}
	}

	std::cout << std::endl << "------ Calcul 4 : Mat1 - Mat2 + Mat3 - Mat4 + Mat5 - Mat6 ... ------" << std::endl;
	// 3rd calculation : Matrix1 - Matrix2 + Matrix3 - ...
	std::cout << std::endl << "R\x082" << "sultat : " << std::endl;
	// If only 1 matrix have been created, the addition result is the matix itself.
	if (uiNbMatrixRead == 1)
	{
		pMatrixTable[0]->TABprintf();
	}
	else
	{
		try
		{
			// The result is the difference between the 2 first matrix
			Cmatrix<double> *resultOperation = (*pMatrixTable[0] - *pMatrixTable[1]);
			// We simply add or substract each other matrix
			for (unsigned int i = 2; i < uiNbMatrixRead; i++)
			{
				// uiNbMatrixRead is even, we have to add the next matrix
				if ((i % 2) == 0)
				{
					resultOperation = (*resultOperation + *pMatrixTable[i]);
				}
				// uiNbMatrixRead is odd, we have to substract the next matrix
				else
				{
					resultOperation = (*resultOperation - *pMatrixTable[i]);
				}
			}
			resultOperation->TABprintf();
		}
		catch (Cexception exc)
		{
			// Error during addition or substraction, incoherent dimensions
			std::cout << "Avertissement : Calcul impossible, les matrices n'ont pas toutes les memes dimensions" << std::endl;
		}
	}

	std::cout << std::endl << "------ Calcul 5 : Multiplication de toutes les matrices ------" << std::endl;
	// 5thd calculation - Matrix1 * Matrix2 * ...
	std::cout << std::endl << "R\x082" << "sultat : " << std::endl;
	// If only 1 matrix have been created, the addition result is the matix itself.
	if (uiNbMatrixRead == 1)
	{
		pMatrixTable[0]->TABprintf();
	}
	else
	{
		try
		{
			// The result is initialized with the product between the first 2 matrix
			Cmatrix<double> *resultAddition = (*pMatrixTable[0] * *pMatrixTable[1]);
			// We simply make the product between the existing result and the next matrix
			for (unsigned int i = 2; i < uiNbMatrixRead; i++)
			{
				resultAddition = (*resultAddition * *pMatrixTable[i]);
			}
			resultAddition->TABprintf();
		}
		catch (Cexception exc)
		{
			// Error during multiplication, incoherent dimensions
			std::cout << "Avertissement : Calcul impossible, les matrices n'ont pas des dimensions compatibles" << std::endl;
		}
	}
}