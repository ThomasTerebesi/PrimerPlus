#include <iostream>

int main()
{
	std::cout << "Enter your age in years and I will display your age in months: " << std::endl;
	float age = 0;
	std::cin >> age;

	std::cout << "You are " << age * 12 << " months old." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}