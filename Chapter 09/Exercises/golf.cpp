#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	std::cout << "Please enter a name: ";
	std::cin.get(g.fullname, Len);
	if (g.fullname[0] == '\0') {
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid name. Input terminated." << std::endl;
		return 0;
	}

	std::cout << "Please enter " << g.fullname << "'s handicap: ";
	std::cin >> g.handicap;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.get();
		std::cout << "\aInvalid handicap. Please enter a valid handicap for " << g.fullname << ": ";
		std::cin >> g.handicap;
	}

	std::cin.get();

	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	std::cout << "Name: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}
