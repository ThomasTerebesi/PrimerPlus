#include <iostream>

int main()
{
	int w = std::cout.width(30);
	std::cout << "default field width = " << w << ":" << std::endl;

	std::cout.width(5);
	std::cout << "N" << ':';
	std::cout.width(8);
	std::cout << "N * N" << ':' << std::endl;

	for (long i = 1; i <= 100; i *= 10)
	{
		std::cout.width(5);
		std::cout << i << ':';
		std::cout.width(8);
		std::cout << i * i << ':' << std::endl;
	}

	std::cin.get();

	return 0;
}