#include <iostream>
#include <cfloat>	// for DBL_MAX

bool hmean(double a, double b, double * ans);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";

	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative of the other. Please try again." << std::endl;

		std::cout << "\nEnter next set of numbers <q to quit>: ";
	}

	return 0;
}

bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}
