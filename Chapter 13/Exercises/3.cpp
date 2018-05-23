// compile with 3dma.h and 3dma.cpp

#include <iostream>
#include "3dma.h"

const short ARRAY_SIZE = 4;
const short INPUT_LENGTH = 64;

int main()
{
	ABCDMA * abcPointerArray[ARRAY_SIZE];

	char inputLabel[INPUT_LENGTH];
	char inputStyle[INPUT_LENGTH];
	char inputColor[INPUT_LENGTH];

	int inputRating;

	short inputChoice;

	std::cout << "Enter " << ARRAY_SIZE << " entries and choose their object type (BaseDMA, LacksDMA, HasDMA)." << std::endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "\nPlease enter the label for entry #" << (i + 1) << ": ";
		std::cin.getline(inputLabel, INPUT_LENGTH);

		std::cout << "Enter the rating for entry #" << (i + 1) << ": ";
		std::cin >> inputRating;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "\aPlease enter a valid rating for entry #" << (i + 1) << ": ";
			std::cin >> inputRating;
		}

		std::cout << "Choose entry #" << (i + 1) << "'s object type:" << std::endl;
		std::cout << "\t1 - BaseDMA\t\t2- LacksDMA" << std::endl;
		std::cout << "\t3 - HasDMA" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> inputChoice;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "\aPlease enter a valid choice for entry #" << (i + 1) << "'s object type: ";
			std::cin >> inputChoice;
		}

		std::cin.get();

		switch (inputChoice)
		{
		case 1:
			abcPointerArray[i] = new BaseDMA(inputLabel, inputRating);
			break;
		case 2:
			std::cout << "Enter the color for entry #" << (i + 1) << ": ";
			std::cin.getline(inputColor, INPUT_LENGTH);
			abcPointerArray[i] = new LacksDMA(inputColor, inputLabel, inputRating);
			break;
		case 3:
			std::cout << "Enter the style for entry #" << (i + 1) << ": ";
			std::cin.getline(inputStyle, INPUT_LENGTH);
			abcPointerArray[i] = new HasDMA(inputStyle, inputLabel, inputRating);
			break;
		default:
			std::cout << "\aInvalid choice detected. Setting entry #" << (i + 1) << "'s object type to BaseDMA." << std::endl;
			abcPointerArray[i] = new BaseDMA(inputLabel, inputRating);
			break;
		}
	}

	std::cout << "\n\nList of all entries:" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "\nEntry #" << (i + 1) << ":" << std::endl;
		abcPointerArray[i]->View();
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		delete[] abcPointerArray[i];
	}

	std::cin.get();

	return 0;
}