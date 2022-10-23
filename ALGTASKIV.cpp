#include <iostream>
#include "Determinant.h"
#include <vector>


int main()
{
	const int arraySize = 8;

	float** pointerArray = new float* [arraySize];
	std::vector<std::vector<float>> vectorArray(arraySize, std::vector<float>(arraySize));
	float staticArray[arraySize][arraySize];

	srand(time(0));

	for (int i = 0; i < arraySize; i++) {
		pointerArray[i] = new float[arraySize];
		for (int j = 0; j < arraySize; j++) {
			pointerArray[i][j] = rand() % 9 + 1;
		}
	}

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			vectorArray[i][j] = rand() % 9 + 1;
		}
	}

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			staticArray[i][j] = rand() % 9 + 1;
		}
	}


	
	Determinant<float**> pointerDeterminant(pointerArray, arraySize);
	pointerDeterminant.Printout();
	std::cout << pointerDeterminant.CalculateDeterminant() << std::endl;

	Determinant<std::vector<std::vector<float>>> vectorDeterminant(vectorArray, arraySize);
	vectorDeterminant.Printout();
	std::cout << vectorDeterminant.CalculateDeterminant() << std::endl;

	
	


	
}
