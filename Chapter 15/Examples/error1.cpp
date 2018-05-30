#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";

	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		std::cout << "\nEnter next set of numbers <q to quit>: ";
	}

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "Untenable arguments to hmean()." << std::endl;
		std::abort();		// std::exit(0) would also be possible, but displays no error message
	}

	return 2.0 * a * b / (a + b);
}
