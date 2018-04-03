#include <iostream>

int main()
{
	int donuts = 6;
	double cups = 4.5;

	std::cout << "donuts value = " << donuts << " and donuts address = " << &donuts << std::endl;
	std::cout << "cups value = " << cups << " and cups address = " << &cups << std::endl;

	std::cin.get();
	return 0;
}