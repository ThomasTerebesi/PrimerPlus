#include <iostream>
#include <cmath>

int main()
{
	// use left justification, show the plus sign, show trailing zeros, set precision to 3
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	std::cout.setf(std::ios_base::showpos);
	std::cout.setf(std::ios_base::showpoint);
	std::cout.precision(3);

	// use e-notation and save old format setting
	std::ios_base::fmtflags old = std::cout.setf(std::ios_base::scientific, std::ios_base::floatfield);

	std::cout << "Left Justification:" << std::endl;
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		std::cout.width(4);
		std::cout << n << '|';
		std::cout.width(12);
		std::cout << sqrt(static_cast<double>(n)) << '|' << std::endl;
	}

	// change to internal justification
	std::cout.setf(std::ios_base::internal, std::ios_base::adjustfield);

	// restore default floating-point display style
	std::cout.setf(old, std::ios_base::floatfield);

	std::cout << "\nInternal Justification:" << std::endl;
	for (n = 1; n <= 41; n += 10)
	{
		std::cout.width(4);
		std::cout << n << '|';
		std::cout.width(12);
		std::cout << sqrt(static_cast<double>(n)) << '|' << std::endl;
	}

	// use right justification, fixed notation
	std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout << "\nRight Justification:" << std::endl;
	for (n = 1; n <= 41; n += 10)
	{
		std::cout.width(4);
		std::cout << n << '|';
		std::cout.width(12);
		std::cout << sqrt(static_cast<double>(n)) << '|' << std::endl;
	}

	std::cin.get();

	return 0;
}