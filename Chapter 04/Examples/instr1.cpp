#include <iostream>

int main()
{
	const int AR_SIZE = 20;
	char name[AR_SIZE];
	char dessert[AR_SIZE];

	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your favorite dessert: ";
	std::cin >> dessert;
	std::cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
	
	std::cin.get();
	std::cin.get();
	return 0;
}