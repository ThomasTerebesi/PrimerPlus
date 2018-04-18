#include <iostream>

void n_chars(char, int);

int main()
{
	int times;
	char ch;

	std::cout << "Enter a character: ";
	std::cin >> ch;

	while (ch != 'q')
	{
		std::cout << "Enter an integer: ";
		std::cin >> times;
		n_chars(ch, times);

		std::cout << "\nEnter another character or 'q' to quit: ";
		std::cin >> ch;
	}

	std::cout << "The value of times is " << times << "." << std::endl;
	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

void n_chars(char c, int n)
{
	while (n-- > 0)
		std::cout << c;
}