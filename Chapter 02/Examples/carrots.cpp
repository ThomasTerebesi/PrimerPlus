#include <iostream>

int main()
{
	int carrots;

	carrots = 25;

	std::cout << "I have ";
	std::cout << carrots;
	std::cout << " carrots.";
	std::cout << std::endl;
	carrots = carrots - 1;
	std::cout << "Crunch, crunch. Now I have " << carrots << " carrots." << std::endl;

	std::cin.get();
	return 0;
}