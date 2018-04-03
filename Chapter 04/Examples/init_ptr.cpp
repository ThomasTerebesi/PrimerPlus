#include <iostream>

int main()
{
	int higgens = 5;
	int* pt = &higgens;

	std::cout << "Value of higgens = " << higgens << "; Address of higgens = " << &higgens << std::endl;
	std::cout << "Value of *pt = " << *pt << "; Value of pt = " << pt << std::endl;

	std::cin.get();
	return 0;
}