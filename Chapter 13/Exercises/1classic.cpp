#include <iostream>
#include <cstring>
#include "1classic.h"



Classic::Classic(const char * pw, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	primaryWork = new char[strlen(pw) + 1];
	strcpy_s(primaryWork, strlen(pw) + 1, pw);
}

Classic::Classic(const Cd & d, const char * pw)
	: Cd(d)
{
	primaryWork = new char[strlen(pw) + 1];
	strcpy_s(primaryWork, strlen(pw) + 1, pw);
}

Classic::Classic(const Classic & d)
	:Cd(d)
{
	primaryWork = new char[strlen(d.primaryWork) + 1];
	strcpy_s(primaryWork, strlen(d.primaryWork) + 1, d.primaryWork);
}

Classic::~Classic()
{
	delete[] primaryWork;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Primary Work: " << primaryWork << std::endl;
}

Classic & Classic::operator=(const Classic & d)
{
	if (this == &d)
		return *this;

	delete[] primaryWork;

	primaryWork = new char[strlen(d.primaryWork) + 1];
	strcpy_s(primaryWork, strlen(d.primaryWork) + 1, d.primaryWork);

	return *this;
}