#include <iostream>

const unsigned short ARRAY_SIZE = 10;

unsigned short FillArray(double arr[], unsigned short maxSize);
void ShowArray(double arr[], unsigned short elements);
void ReverseArray(double arr[], unsigned short elements);

int main()
{
	double myArray[ARRAY_SIZE];

	unsigned short arrayElements = FillArray(myArray, ARRAY_SIZE);

	if (arrayElements == 0)
		std::cout << "\nNo values were entered." << std::endl;
	else if (arrayElements == 1)
	{
		std::cout << "\nYou only entered one element: " << myArray[0] << std::endl;
	}
	else
	{
		ShowArray(myArray, arrayElements);

		ReverseArray(myArray, arrayElements);
		ShowArray(myArray, arrayElements);

		if (arrayElements > 3) // Nothing will be reversed below that limit anyway
		{
			std::cout << "\nNow, reverse the array except for the first and last elements.";
			ReverseArray(myArray + 1, arrayElements - 2);
			ShowArray(myArray, arrayElements);
		}
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

unsigned short FillArray(double arr[], unsigned short maxSize)
{
	std::cout << "Enter up to " << maxSize << " values below (non-numeric values terminate input)." << std::endl;

	unsigned short inputCounter = 0;

	for (int i = 0; i < maxSize; i++)
	{
		std::cout << "Enter value #" << (i + 1) << ": ";
		std::cin >> arr[i];

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\n\aInput terminated by user." << std::endl;
			break;
		}

		inputCounter++;
	}

	return inputCounter;
}

void ShowArray(double arr[], unsigned short elements)
{
	std::cout << "\nValues in the array:" << std::endl;

	for (int i = 0; i < elements; i++)
	{
		std::cout << "Value #" << (i + 1) << ": " << arr[i] << std::endl;
	}
}

void ReverseArray(double arr[], unsigned short elements)
{
	std::cout << "\nReversing array ... ";

	double temp;

	for (int i = 0, j = (elements - 1); i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	std::cout << "Done!" << std::endl;
}
