#include <iostream>

int main()
{
	std::cout << "What year was your house built?\n";
	int year;
	std::cin >> year;
	std::cin.get();
	std::cout << "What is its street address?\n";
	char address[80];
	std::cin.getline(address, 80);
	std::cout << "Year built: " << year << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Done!\n";

	std::cin.get();
	return 0;
}