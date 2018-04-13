#include <iostream>

const int FAVE = 27;

int main()
{
	std::cout << "Enter a number in the range between 1 and 100 to find my favorite number: ";

	int n;

	do
	{
		std::cin >> n;
		
		if (n < FAVE)
			std::cout << "Too low -- guess again: ";
		else if (n > FAVE)
			std::cout << "Too high -- guess again: ";
		else
			std::cout << FAVE << " is my favorite number!\n";
	} while (n != FAVE);

	std::cin.get();
	std::cin.get();
	return 0;
}