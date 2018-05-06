#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string & ln, const char * fn)
{
	lname = ln;
	strcpy_s(fname, LIMIT, fn);
}

void Person::Show() const
{
	std::cout << fname << " " << lname << "\n" << std::endl;
}

void Person::FormalShow() const
{
	std::cout << lname << ", " << fname << "\n" << std::endl;
}
