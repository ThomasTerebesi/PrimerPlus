#include <iostream>

enum { red, orange, yellow, green, blue, violet, indigo }; // named constants

int main()
{
	std::cout << "Enter a color code (0 - 6): ";
	int code;
	std::cin >> code;

	while (code >= red && code <= indigo)
	{
		switch (code)
		{
		case red: 
			std::cout << "Her lips were red." << std::endl; 
			break;
		case orange:
			std::cout << "Her hair was orange." << std::endl;
			break;
		case yellow:
			std::cout << "Her shoes were yellow." << std::endl;
			break;
		case green:
			std::cout << "Her nails were green." << std::endl;
			break;
		case blue:
			std::cout << "Her sweatsuit was blue." << std::endl;
			break;
		case violet:
			std::cout << "Her eyes were violet." << std::endl;
			break;
		case indigo:
			std::cout << "Her mood was indigo." << std::endl;
			break;
		}

		std::cout << "\nEnter a color code (0 - 6): ";
		std::cin >> code;
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}