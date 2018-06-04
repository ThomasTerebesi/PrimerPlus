// compile with exc_mean.h and exc_mean.cpp

#include <iostream>
#include <cmath>
#include "3exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";

	while (std::cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			std::cout << "\nHarmonic mean of " << x << " and " << y << " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << std::endl;
			std::cout << "\nEnter next set of numbers <q to quit>: ";
		}

		catch (bad_hmean & bh)
		{
			bh.Report();
			std::cout << "Try again: ";
			continue;
		}

		catch (bad_gmean & bg)
		{
			bg.Report();
			std::cout << "Sorry, you don't get to play any more." << std::endl;

			break;
		}
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b, "Values must not be the inverse of each other.\n");

	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b, "Both values must be greater than zero.\n");

	return sqrt(a * b);
}
