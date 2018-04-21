#include <iostream>

double HarmonicMean(double x, double y);

int main()
{
	double firstInput;
	double secondInput;

	std::cout << "I will calculate the harmonic mean of two numbers." << std::endl;

	std::cout << "Please enter two numbers ('q' to quit):" << std::endl;
	while (std::cin >> firstInput >> secondInput)
	{
		std::cout << "The harmonic mean of " << firstInput << " and " << secondInput << " is " << HarmonicMean(firstInput, secondInput) << "." << std::endl;
		std::cout << "\nPlease enter two numbers ('q' to quit):" << std::endl;
	}

	return 0;
}

double HarmonicMean(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
