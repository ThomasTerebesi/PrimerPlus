#include <iostream>

int main()
{
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	std::cout << "Monsieur cuts a striking figure!\n";
	std::cout << "chest = " << chest << " (42 in decimal)\n";
	std::cout << "waist = " << waist << " (0x42 in hex)\n";
	std::cout << "inseam = " << inseam << " (042 in octal)\n";

	std::cin.get();
	return 0;
}