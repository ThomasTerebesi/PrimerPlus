// compile with 6stonewt.h and 6stonewt.cpp

#include <iostream>
#include <ctime>
#include "6stonewt.h"

const unsigned short WEIGHT_ARRAY_SIZE = 6;

int main()
{
	srand(static_cast<int>(time(0)));
	Stonewt weightArray[WEIGHT_ARRAY_SIZE] = { Stonewt(9, 2.8), Stonewt(12, 3.1), Stonewt(94.2) };
	Stonewt referenceElement(11, 0.0);

	/* USER INPUT VARIANT
	double poundInput;

	for (int i = 3; i < WEIGHT_ARRAY_SIZE; i++)
	{
		std::cout << "Enter the weight in pounds for object #" << (i + 1) << ": ";
		std::cin >> poundInput;

		while (poundInput < 0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aPlease enter a valid number greater than zero." << std::endl;
			std::cin >> poundInput;
		}

		weightArray[i] = Stonewt(poundInput);
	}
	*/

	// RANDOM VARIANT
	for (int i = 3; i < WEIGHT_ARRAY_SIZE; i++)
		weightArray[i] = rand() % 512;

	Stonewt smallestElement = weightArray[0], largestElement = weightArray[0];
	unsigned short referenceCounter = 0; // counts elements greater than or equal to referenceStone

	for (int i = 0; i < WEIGHT_ARRAY_SIZE; i++)
	{
		if (weightArray[i] >= referenceElement)
			referenceCounter++;

		if (weightArray[i] > largestElement)
			largestElement = weightArray[i];
		else if (weightArray[i] < smallestElement)
			smallestElement = weightArray[i];
	}

	std::cout << "Weight of the smallest element in weightArray: " << smallestElement << std::endl;
	std::cout << "Weight of the largest element in weightArray: " << largestElement << std::endl;
	std::cout << "Number of objects weighing more than " << referenceElement << ": " << referenceCounter << std::endl;

	std::cin.get();

	return 0;
}