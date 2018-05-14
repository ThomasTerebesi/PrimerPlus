// compile with string1.h and string1.cpp

#include <iostream>
#include "string1.h"

const short ARRAY_SIZE = 10;
const short MAX_LENGTH = 81;

int main()
{
	std::cout << "Hi, what's your name?" << std::endl;
	String name;
	std::cin >> name;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "Please enter a valid name:" << std::endl;
		std::cin >> name;
	}

	std::cout << "\n" << name << ", please enter up to " << ARRAY_SIZE << " short sayings (empty line to quit):" << std::endl;
	String sayings[ARRAY_SIZE];		// array of objects
	char temp[MAX_LENGTH];			// temporary string storage

	short i;
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << (i + 1) << ": " << sayings[i];
		std::cin.get(temp, MAX_LENGTH);
		
		while (std::cin && std::cin.get() != '\n')
			continue;

		if (!std::cin || temp[0] == '\0')	// empty line?
		{
			std::cin.clear();
			std::cin.get();
			break; // i not incremented
		}				
		else
			sayings[i] = temp;				// overloaded assignment
	}

	short total = i;

	if (total > 0)
	{
		std::cout << "\nHere are your sayings:" << std::endl;
		for (i = 0; i < total; i++)
			std::cout << sayings[i][0] << ": " << sayings[i] << std::endl;

		short shortest = 0;
		short first = 0;

		for (i = 1; i < total; i++)
		{
			if (sayings[i].Length() < sayings[shortest].Length())
				shortest = i;

			if (sayings[i] < sayings[first])
				first = i;
		}

		std::cout << "\nShortest saying:\n" << sayings[shortest] << std::endl;
		std::cout << "First saying alphabetically:\n" << sayings[first] << std::endl;

		std::cout << "\nThis program used " << String::HowMany() << " String objects. Bye." << std::endl;
	}
	else
	{
		std::cout << "\nNo input, bye." << std::endl;
	}

	std::cin.get();
	return 0;
}