#include <iostream>
#include <ctime>

const int SLEN = 10;

inline void EatLine() { while (std::cin.get() != '\n') continue; }

int main()
{
	char name[SLEN];
	char title[SLEN];

	std::cout << "Enter your name: ";
	std::cin.get(name, SLEN);
	if (std::cin.peek() != '\n')
		std::cout << "Sorry, we only have enough room for " << name << std::endl;

	EatLine();

	std::cout << "\nDear " << name << ", enter your title:" << std::endl;
	std::cin.get(title, SLEN);
	if (std::cin.peek() != '\n')
		std::cout << "We were forced to truncate your title." << std::endl;

	EatLine();

	std::cout << "\n\tName:\t" << name << std::endl;
	std::cout << "\tTitle:\t" << title << std::endl;

	float seconds = 7.5;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay);

	return 0;
}