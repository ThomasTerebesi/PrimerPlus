#include <iostream>

int main()
{
	int rats = 101;
	int& rodents = rats;

	std::cout << "rats = " << rats;
	std::cout << ", rodents = " << rodents << std::endl;

	std::cout << "rats address = " << &rats;
	std::cout << ", rodents address = " << &rodents << std::endl;

	int bunnies = 50;
	rodents = bunnies;

	std::cout << "bunnies = " << bunnies;
	std::cout << ", rats = " << rats;
	std::cout << ", rodents = " << rodents << std::endl;

	std::cout << "bunnies address = " << &bunnies;
	std::cout << ", rodents address = " << &rodents << std::endl;

	std::cin.get();

	return 0;
}