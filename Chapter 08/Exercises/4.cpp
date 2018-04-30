#include <iostream>
#include <cstring>	// for strlen(), strcpy()

struct stringy
{
	char * str;		// points to a string
	int ct;			// length of string (not counting '\0')
};

void set(stringy & destStr, const char srcStr[]);
void show(const stringy & str, unsigned short n = 1);
void show(const char str[], unsigned short n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
						 // allocates space to hold copy of testing,
						 // sets str member of beany to point to the
						 // new block, copies testing to new block,
						 // and sets ct member of beany
	show(beany);		 // prints member string once
	show(beany, 2);		 // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);		 // prints testing string once
	show(testing, 3);	 // prints testing string thrice
	show("\nDone!");

	std::cin.get();

	delete[] beany.str;

	return 0;
}

void set(stringy & destStr, const char srcStr[])
{
	int length = strlen(srcStr);
	destStr.ct = length;

	char * temp = new char[length + 1];
	strcpy_s(temp, (length + 1), srcStr);

	destStr.str = temp;
}

void show(const stringy & str, unsigned short n)
{
	for (int i = 0; i < n; i++)
		std::cout << str.str << std::endl;
}

void show(const char str[], unsigned short n)
{
	for (int i = 0; i < n; i++)
		std::cout << str << std::endl;
}
