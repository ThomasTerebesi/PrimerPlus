#include <iostream>

const int ARRAY_SIZE = 10;

void StrCount(const char* str);

int main()
{
	char input[ARRAY_SIZE];
	char next;

	std::cout << "Enter a line:" << std::endl;
	std::cin.get(input, ARRAY_SIZE);

	while (std::cin)
	{
		std::cin.get(next);
		while (next != '\n') // string did not fit
			std::cin.get(next); // dispose of remainder

		StrCount(input);

		std::cout << "Enter next line (empty line to quit):" << std::endl;
		std::cin.get(input, ARRAY_SIZE);
	}

	std::cout << "Bye!" << std::endl;


	std::cin.clear();
	std::cin.get();
	std::cin.get();


	return 0;
}

void StrCount(const char * str)
{
	static int total = 0; // static local variable
	int count = 0; // automatic local variable

	std::cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;

	std::cout << count << " characters." << std::endl;
	std::cout << total << " characters total." << std::endl;
}
