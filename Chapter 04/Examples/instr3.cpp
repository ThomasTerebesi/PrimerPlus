#include <iostream>

int main()
{
	const int AR_SIZE = 20;
	char name[AR_SIZE];
	char dessert[AR_SIZE];

	std::cout << "Enter your name: ";
	std::cin.get(name, AR_SIZE).get();
	std::cout << "Enter your favorite dessert: ";
	std::cin.get(dessert, AR_SIZE).get();
	std::cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

	std::cin.get();
	return 0;
}