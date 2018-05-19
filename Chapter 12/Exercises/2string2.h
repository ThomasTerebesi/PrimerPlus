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
	// constructors / destructor
	String(const char * cst);		// constructor
	String();						// default constructor
	String(const String & st);		// copy constructor
	~String();						// destructor
	
	// member functions
	int Length() const { return len; }
	String & StringLow();
	String & StringUp();
	short has(const char ch);

	// overloaded operator methods
	String & operator=(const String & st);
	String & operator=(const char * cst);
	char & operator[](int i);
	const char & operator[](int i) const;

	// overloaded operator friends
	friend bool operator<(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);
	friend String operator+(const String & st1, const String & st2);
	friend String operator+(const char * cst, const String & st);
	friend String operator+(const String & st, const char * cst);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);

	// static function
	static int HowMany();
};