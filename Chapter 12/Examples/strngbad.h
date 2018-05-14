// flawed string class definition

#pragma once
#include <iostream>

class StringBad
{
private:
	char * str;				// pointer to string
	int len;				// length of string
	static int numStrings;	// number of objects
public:
	StringBad(const char * s);
	StringBad();
	~StringBad();
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};