#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy
{
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
						 // allocates space to hold copy of testing,
						 // sets str member of beany to point to the
						 // new block, copies testing to new block,
						 // and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
	return 0;
}