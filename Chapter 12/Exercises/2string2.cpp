#include <cstring>
#include <cctype>
#include "2string2.h"


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

String & String::StringLow()
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = tolower(str[i]);

	return *this;
}

String & String::StringUp()
{
	for (int i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);

	return *this;
}

short String::has(const char ch)
{
	short charCount = 0;

	for (int i = 0; i < strlen(str); i++)
		if (str[i] == ch)
			charCount++;

	return charCount;
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

String operator+(const String & st1, const String & st2)
{
	unsigned short length = strlen(st1.str) + strlen(st2.str);
	char * temp = new char[length + 1];
	strcpy_s(temp, length + 1, st1.str);
	strcat_s(temp, sizeof(char) * (length + 1), st2.str);

	String concatenated(temp);
	delete[] temp;

	return concatenated;
}

String operator+(const char * cst, const String & st)
{
	return String(cst) + st;
}

String operator+(const String & st, const char * cst)
{
	return st + String(cst);
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
