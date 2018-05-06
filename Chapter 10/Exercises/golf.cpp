#include "golf.h"
#include <iostream>
#include <cstring>

Golf::Golf()
{
	strcpy_s(fullName, "");
	handicap = 0;
}

Golf::Golf(const char * name, int hc)
{
	strcpy_s(fullName, LENGTH, name);
	handicap = hc;
}

bool Golf::SetGolf()
{
	char name[LENGTH];
	int hc;

	std::cout << "Please enter a name: ";
	std::cin.get(name, LENGTH);
	if (name[0] == '\0')
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid name. Input terminated." << std::endl;
		return false;
	}

	std::cout << "Please enter " << name << "'s handicap: ";
	std::cin >> hc;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid handicap. Please enter a valid handicap for " << fullName << ": ";
		std::cin >> hc;
	}

	std::cin.get();

	Golf temp(name, hc);
	*this = temp;

	return true;
}

void Golf::Handicap(int hc)
{
	handicap = hc;
}

void Golf::ShowGolf()
{
	std::cout << "Name: " << fullName << std::endl;
	std::cout << "Handicap: " << handicap << std::endl;
}

const char * Golf::GetName()
{
	return fullName;
}
