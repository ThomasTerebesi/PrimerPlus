#include <iostream>

inline double f(double tf) { return 5.0*(tf - 32.0) / 9.0; }

int main()
{
	double tc = 21.5;
	double && rd1 = 7.07;
	double && rd2 = 1.8 * tc + 32.0;
	double && rd3 = f(rd2);

	std::cout << " tc value and address: " << tc << ", " << &tc << std::endl;
	std::cout << "rd1 value and address: " << rd1 << ", " << &rd1 << std::endl;
	std::cout << "rd2 value and address: " << rd2 << ", " << &rd2 << std::endl;
	std::cout << "rd3 value and address: " << rd3 << ", " << &rd3 << std::endl;

	std::cin.get();

	return 0;
}