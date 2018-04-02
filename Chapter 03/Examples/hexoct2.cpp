#include <iostream>

int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	std::cout << "Monsieur cuts a striking figure!\n";
	// std::cout << std::dec;
	std::cout << "chest = " << chest << " (42 in decimal)\n";
	std::cout << std::hex;
	std::cout << "waist = " << waist << " (0x42 in hex)\n";
	std::cout << std::oct;
	std::cout << "inseam = " << inseam << " (042 in octal)\n";

	std::cin.get();
	return 0;
}