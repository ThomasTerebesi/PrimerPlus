#include <iostream>

inline double Square(double x) { return x * x; }

int main()
{
	double a, b;
	double c = 13.0;

	a = Square(5.0);
	b = Square(4.5 + 7.5);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", c squared = " << Square(c++) << std::endl;
	std::cout << "Now, c = " << c << std::endl;

	std::cin.get();

	return 0;
}