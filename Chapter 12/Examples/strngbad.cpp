#include <cstring>
#include "strngbad.h"

// initializing static class member
int StringBad::numStrings = 0;	// uses scope operator and type keyword, but no static keyword

// construct StringBad from C string
StringBad::StringBad(const char * s)
{
	len = std::strlen(s);		// set size;
	str = new char[len + 1];	// allot storage
	strcpy_s(str, len + 1, s);		// initialize pointer
	numStrings++;				// update object count
	std::cout << numStrings << ": \"" << str << "\" object created." << std::endl;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str, len + 1, "C++");
	numStrings++;
	std::cout << numStrings << ": \"" << str << "\" object created." << std::endl;
}

StringBad::~StringBad()
{
	std::cout << "\"" << str << "\" object deleted, ";
	--numStrings;
	std::cout << numStrings << " left." << std::endl;
	delete[] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}
