#include <iostream>

int main()
{
	char ch;

	std::cout << "Enter a character: " << std::endl;
	std::cin >> ch;
	std::cout << "Hola! ";
	std::cout << "Thank you for the " << ch << " character." << std::endl;
	
	std::cin.get();
	std::cin.get();
	return 0;
}