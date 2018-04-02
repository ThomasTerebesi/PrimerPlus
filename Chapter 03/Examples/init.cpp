#include <iostream>

int main()
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	
	float tree = 3;
	int guess(3.9832);
	int debt = 7.2E12;

	std::cout << "tree = " << tree << std::endl;
	std::cout << "guess = " << guess << std::endl;
	std::cout << "debt = " << debt << std::endl;

	std::cin.get();
	return 0;
}