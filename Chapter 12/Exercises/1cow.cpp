#include <iostream>
#include <cstring>
#include "1cow.h"

Cow::Cow()
	: weight(653.2)
{
	strcpy_s(name, 6, "Bessy");
	
	hobby = new	char[7];
	strcpy_s(hobby, 7, "Eating");
}

Cow::Cow(const char * nm, const char * ho, double wt)
	: weight(wt)
{
	strcpy_s(name, 20, nm);
	
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
}

Cow::Cow(const Cow & c)
{
	strcpy_s(name, 20, c.name);
	
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);

	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
		return *this;

	strcpy_s(name, 20, c.name);

	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);

	weight = c.weight;

	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "Name:\t" << name << std::endl;
	std::cout << "Hobby:\t" << hobby << std::endl;
	std::cout << "Weight:\t" << weight << std::endl;
}
