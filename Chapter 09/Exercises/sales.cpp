#include <iostream>
#include "sales.h"


void SALES::setSales(Sales & s, const double ar[], int n)
{
	if (n > 0 && n <= QUARTERS)
	{
		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
		}

		s.min = s.sales[0];
		s.max = s.sales[0];

		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] < s.min)
				s.min = s.sales[i];

			if (s.sales[i] > s.max)
				s.max = s.sales[i];

			s.average += s.sales[i];
		}

		s.average /= QUARTERS;
	}
	else
		std::cout << "Invalid number of quarters." << std::endl;
}

void SALES::setSales(Sales & s)
{
	for (int i = 0; i < QUARTERS; i++)
	{
		std::cout << "Please enter the sales of quarter " << (i + 1) << ": ";
		std::cin >> s.sales[i];
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aInvalid input. Please enter valid input for quarter " << (i + 1) << ": ";
			std::cin >> s.sales[i];
		}
	}

	s.min = s.sales[0];
	s.max = s.sales[0];

	for (int i = 0; i < QUARTERS; i++)
	{
		if (s.sales[i] < s.min)
			s.min = s.sales[i];

		if (s.sales[i] > s.max)
			s.max = s.sales[i];

		s.average += s.sales[i];
	}

	s.average /= QUARTERS;

	std::cin.get();
}

void SALES::showSales(const Sales & s)
{
	for (int i = 0; i < QUARTERS; i++)
		std::cout << "Quarter " << (i + 1) << " sales:\t" << s.sales[i] << std::endl;

	std::cout << "\nAverage sales per quarter:\t" << s.average << std::endl;
	std::cout << "Lowest sales of a quarter:\t" << s.min << std::endl;
	std::cout << "Largest sales of a quarter:\t" << s.max << std::endl;
}
