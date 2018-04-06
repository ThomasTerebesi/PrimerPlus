#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::string dessert;

	std::cout << "Enter your name: ";
	getline(std::cin, name);
	std::cout << "Enter your favorite dessert: ";
	getline(std::cin, dessert);
	std::cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

	std::cin.get();
	return 0;
}