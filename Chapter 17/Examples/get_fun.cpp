#include <iostream>
#include <ctime>

const int LIMIT = 255;

int main()
{
	char input[LIMIT];

	std::cout << "Enter a string for getline() processing:" << std::endl;
	std::cin.getline(input, LIMIT, '#');
	std::cout << "Here is your input:" << std::endl;
	std::cout << input << "\nDone with phase 1." << std::endl;

	char ch;
	std::cin.get(ch);
	std::cout << "\nThe next input character is " << ch << '.' << std::endl;	// discards the '#'

	if (ch != '\n')
		std::cin.ignore(LIMIT, '\n');	// discard the rest of the line

	std::cout << "\nEnter a string for get() processing:" << std::endl;
	std::cin.get(input, LIMIT, '#');
	std::cout << "Here is your input:" << std::endl;
	std::cout << input << "\nDone with phase 2." << std::endl;

	std::cin.get(ch);
	std::cout << "\nThe next input character is " << ch << '.' << std::endl;	// does not discard the '#'

	float seconds = 7.5;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}