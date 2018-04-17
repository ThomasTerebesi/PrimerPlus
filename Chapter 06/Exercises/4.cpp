#include <iostream>

const unsigned short STRING_SIZE = 64;
const unsigned short ARRAY_SIZE = 5;

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
	std::cout << "q. quit\n" << std::endl;

	BOP members[ARRAY_SIZE] =
	{
		{ "Jaydon Waters", "Facility Manager", "WR3CK3R", 2 },
		{ "Anton Gillespie", "Senior Software Engineer", "Overlord", 1 },
		{ "Willie Fellows", "Technical Analyst", "lYze", 2 },
		{ "Emmanuel Aguirre", "Data Scientist", "wrath_", 0 },
		{ "Trevor Schmitt", "Project Manager", "encouraging_words", 1 }
	};

	char ch;

	std::cout << ">> ";
	std::cin >> ch;
	
	while (ch != 'q')
	{
		switch (ch)
		{
		case 'a':
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				std::cout << members[i].fullName << std::endl;
			}
			std::cout << std::endl;
			break;
		case 'b':
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				std::cout << members[i].title << std::endl;
			}
			std::cout << std::endl;
			break;
		case 'c':
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				std::cout << members[i].bopName << std::endl;
			}
			std::cout << std::endl;
			break;
		case 'd':
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				switch (members[i].preference)
				{
				case 0:
					std::cout << members[i].fullName << std::endl;
					break;
				case 1:
					std::cout << members[i].title << std::endl;
					break;
				case 2:
					std::cout << members[i].bopName << std::endl;
					break;
				default:
					std::cout << "This preference is not known!" << std::endl;
					break;
				}
			}
			std::cout << std::endl;
			break;
		default:
			std::cout << "Please enter 'a', 'b', 'c', 'd' or 'q':\n" << std::endl;
			break;
		}

		std::cout << ">> ";
		std::cin >> ch;
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}