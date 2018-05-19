#include <cstring>
#include "string1.h"


// initializing static class member
int String::numStrings = 0;

// static method
int String::HowMany()
{
	return numStrings;
}


// class methods
String::String(const char * cst)
{
	len = strlen(cst);
	str = new char[len + 1];
	strcpy_s(str, len + 1, cst);
	numStrings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	numStrings++;
}

String::String(const String & st)	// <== copy constructor
{
	numStrings++;					// handle static member update
	len = st.len;					// same length
	str = new char[len + 1];		// allot space
	strcpy_s(str, len + 1, st.str);	// copy string to new location
}

String::~String()
{
	--numStrings;
	delete[] str;
}


// overloaded operator methods
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;

	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);

	return *this;
}

String & String::operator=(const char * cst)
{
	delete[] str;
	len = strlen(cst);
	str = new char[len + 1];
	strcpy_s(str, len + 1, cst);

	return *this;
}

// read-write char access for non-const String
char & String::operator[](int i)
{
	return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
	return str[i];
}


// overloaded operator friends
bool operator<(const String & st1, const String & st2)
{
	return(strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return(strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;

	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];

	is.get(temp, String::CINLIM);

	if (is)
		st = temp;

	while (is && is.get() != '\n')
		continue;

	return is;
}
