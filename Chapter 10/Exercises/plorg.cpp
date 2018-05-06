#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg()
	: contentmentIndex(50)
{
	strcpy_s(name, NAME_LIMIT, "Plorga");
}

Plorg::Plorg(const char * name)
	: contentmentIndex(50)
{
	if (strlen(name) > NAME_LIMIT)
	{
		std::cout << "\a\tA plorg can not have a name with more than 19 characters!" << std::endl;
	}

	strncpy_s(this->name, name, NAME_LIMIT - 1);
}

void Plorg::SetCI(int newContentmentIndex)
{
	contentmentIndex = newContentmentIndex;
}

void Plorg::Report() const
{
	std::cout << "My name is " << name << " and my contentment index is " << contentmentIndex << "." << std::endl;
}
