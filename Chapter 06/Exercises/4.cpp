#include <iostream>

const unsigned short STRING_SIZE = 64;
const unsigned short ARRAY_SIZE = 3;

struct BOP
{
	char fullName[STRING_SIZE];
	char title[STRING_SIZE];
	char bopName[STRING_SIZE];
	int preference; // 0 = fullName, 1 = title, 2 = bopName
};

int main()
{
	std::cout << "Benevolent Order of Programmers Report" << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "a. display by name\tb. display by title" << std::endl;
	std::cout << "c. display by bopname\td. display by preference" << std::endl;
	std::cout << "q. quit" << std::endl;

	BOP members[ARRAY_SIZE] =
	{
		{ " ", " ", " ", 0 },
		{ " ", " ", " ", 0 },
		{ " ", " ", " ", 0 }
	};

	char ch;
	std::cin >> ch;
	
	while (ch != 'q')
	{
		// TODO: Exercise on pages 301/302
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}