#include <iostream>

int main()
{
	std::cout << "Enter a number of rows: ";
	unsigned short numRows;
	std::cin >> numRows;

	for (int i = 0; i < numRows; i++)
	{
		for (int k = numRows - 1; k > i; k--)
		{
			std::cout << ".";
		}

		for (int j = numRows - i; j <= numRows; j++)
		{
			
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	std::cin.get();
	std::cin.get();
	return 0;
}