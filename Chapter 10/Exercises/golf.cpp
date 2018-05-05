#include "golf.h"
#include <iostream>
#include <cstring>

Golf::Golf()
{
	strcpy_s(fullName, '\0');
	handicap = 0;
}

Golf::Golf(const char * name, int hc)
{
	strcpy_s(fullName, LENGTH, name);
	handicap = hc;
}

void Golf::SetGolf()
{
	char name[LENGTH];
	int hc;

	std::cout << "Please enter a name: ";
	std::cin.get(name, LENGTH);
	if (name == '\0')
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid name. Input terminated." << std::endl;
		
	}

	std::cout << "Please enter " << name << "'s handicap: ";
	std::cin >> hc;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid handicap. Please enter a valid handicap for " << g.fullname << ": ";
		std::cin >> hc;
	}

	std::cin.get();

	Golf temp(name, hc);
	*this = temp;
}

void Golf::Handicap()
{
}

void Golf::ShowGolf()
{
}
