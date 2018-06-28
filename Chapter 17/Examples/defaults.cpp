#include <iostream>

int main()
{
	std::cout << "12345678901234567890" << std::endl;
	
	char ch = 'K';
	int t = 273;

	std::cout << ch << ":" << std::endl;
	std::cout << t << ":" << std::endl;
	std::cout << -t << ":" << std::endl;

	double f1 = 1.200;
	std::cout << f1 << ":" << std::endl;
	std::cout << (f1 + 1.0 / 9.0) << ":" << std::endl;

	double f2 = 1.67E2;
	std::cout << f2 << ":" << std::endl;
	f2 += 1.0 / 9.0;
	std::cout << f2 << ":" << std::endl;
	std::cout << (f2 * 1.0e4) << ":" << std::endl;

	double f3 = 2.3e-4;
	std::cout << f3 << ":" << std::endl;
	std::cout << f3 / 10 << ":" << std::endl;

	std::cin.get();

	return 0;
}