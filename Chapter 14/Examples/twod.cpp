#include <iostream>
#include "arraytp.h"

int main()
{
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;

	int i, j;

	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;

		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}

		aves[i] = static_cast<double>(sums[i]) / 10;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			std::cout.width(2);
			std::cout << twodee[i][j] << ' ';
		}

		std::cout << ": sum = ";
		std::cout.width(3);
		std::cout << sums[i] << ", average = " << aves[i] << std::endl;
	}

	std::cout << "\nDone." << std::endl;

	std::cin.get();

	return 0;
}