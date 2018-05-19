// fixed and augmented string class definition

#pragma once
#include <iostream>

class String
{
private:
	char * str;						// pointer to string
	int len;						// length of string
	static int numStrings;			// number of objects
	static const int CINLIM = 80;	// cin input limit
public:
	// constructors and other methods
	String(const char * cst);			// constructor
	String();						// default constructor
	String(const String & st);			// copy constructor
	~String();						// destructor
	int Length() const { return len; }

	// overloaded operator methods
	String & operator=(const String & st);
	String & operator=(const char * cst);
	char & operator[](int i);
	const char & operator[](int i) const;

	// overloaded operator friends
	friend bool operator<(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);

	// static function
	static int HowMany();
};