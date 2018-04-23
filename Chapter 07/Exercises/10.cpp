#include <iostream>

const unsigned short CALC_FUNCTIONS = 4;
const char* OPERATORS[4] = { " + ", " - ", " * ", " / " };

double Calculate(double x, double y, double(*pf)(double, double));
double Add(double x, double y);
double Substract(double x, double y);
double Multiply(double x, double y);
double Divide(double x, double y);


int main()
{
	// array of pointers to functions
	double(*calcFunctions[CALC_FUNCTIONS])(double, double) = { Add, Substract, Multiply, Divide };
	double inputOne, inputTwo;

	std::cout << "Enter two numbers:" << std::endl;

	while (std::cin >> inputOne >> inputTwo)
	{
		for (int i = 0; i < CALC_FUNCTIONS; i++)
		{
			std::cout << inputOne << OPERATORS[i] << inputTwo << " = ";
			std::cout << Calculate(inputOne, inputTwo, calcFunctions[i]) << std::endl;
		}

		std::cout << "\nEnter another two numbers:" << std::endl;
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

double Calculate(double x, double y, double(*pf)(double, double))
{
	return pf(x, y);
}

double Add(double x, double y)
{
	return x + y;
}

double Substract(double x, double y)
{
	return x - y;
}

double Divide(double x, double y)
{
	if (y == 0)
	{
		return NULL;
	}
	else
		return x / y;
}

double Multiply(double x, double y)
{
	return x * y;
}
