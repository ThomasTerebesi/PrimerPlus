#include <iostream>

int main()
{
	int carrots = 0;

	std::cout << "How many carrots do you have? " << std::endl;
	std::cin >> carrots;
	std::cout << "Here are 2 more. ";
	carrots = carrots + 2;
	std::cout << "Now you have " << carrots << " carrots." << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}