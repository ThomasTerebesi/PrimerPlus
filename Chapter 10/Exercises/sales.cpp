#include <iostream>
#include "sales.h"

SALES::Sales::Sales()
{
	for (int i = 0; i < QUARTERS; i++)
	{
		std::cout << "Please enter the sales of quarter " << (i + 1) << ": ";
		std::cin >> sales[i];
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aInvalid input. Please enter valid input for quarter " << (i + 1) << ": ";
			std::cin >> sales[i];
		}
	}

	min = sales[0];
	max = sales[0];

	for (int i = 0; i < QUARTERS; i++)
	{
		if (sales[i] < min)
			min = sales[i];

		if (sales[i] > max)
			max = sales[i];

		average += sales[i];
	}

	average /= QUARTERS;

	std::cin.get();
}

SALES::Sales::Sales(const double ar[], int n)
{
	if (n > 0 && n <= QUARTERS)
	{
		for (int i = 0; i < n; i++)
		{
			sales[i] = ar[i];
		}

		min = sales[0];
		max = sales[0];

		for (int i = 0; i < QUARTERS; i++)
		{
			if (sales[i] < min)
				min = sales[i];

			if (sales[i] > max)
				max = sales[i];

			average += sales[i];
		}

		average /= QUARTERS;
	}
	else
		std::cout << "Invalid number of quarter" << std::endl;
}

void SALES::Sales::ShowSales() const
{
	for (int i = 0; i < QUARTERS; i++)
		std::cout << "Quarter " << (i + 1) << " sales:\t" << sales[i] << std::endl;

	std::cout << "\nAverage sales per quarter:\t" << average << std::endl;
	std::cout << "Lowest sales of a quarter:\t" << min << std::endl;
	std::cout << "Largest sales of a quarter:\t" << max << std::endl;
}
