// compile with string1.h and string1.cpp
// this uses the working String class

#include <iostream>
#include "string1.h"

void CallMe1(String &);
void CallMe2(String);

int main()
{
	{
		std::cout << "Starting an inner block." << std::endl;

		String headline1("Celery Stalks at Midnight");
		String headline2("Lettuce Prey");
		String sports("Spinach Leaves Bowl for Dollars");

		std::cout << "\n";

		std::cout << "headline1: " << headline1 << std::endl;
		std::cout << "headline2: " << headline2 << std::endl;
		std::cout << "sports: " << sports << std::endl;

		CallMe1(headline1);
		std::cout << "headline1: " << headline1 << std::endl;
		CallMe2(headline2);
		std::cout << "headline2: " << headline2 << std::endl;

		std::cout << "\nInitialize one object to another:" << std::endl;
		String sailor = sports;
		std::cout << "sailor: " << sailor << std::endl;

		std::cout << "\n";

		std::cout << "Assign one object to another:" << std::endl;
		String knot;
		knot = headline1;
		std::cout << "knot: " << knot << std::endl;

		std::cout << "\n";

		std::cout << "Assign a string to an object: " << std::endl;
		String zap = "This works?";
		std::cout << "zap: " << zap << std::endl;

		std::cout << "\n";

		std::cout << "Exiting the block." << std::endl;
	}

	std::cout << "\nEnd of main()." << std::endl;

	std::cin.get();

	return 0;
}

void CallMe1(String & rsb)
{
	std::cout << "\nString passed by reference: " << std::endl;
	std::cout << "\t\"" << rsb << "\"" << std::endl;
}

void CallMe2(String sb)
{
	std::cout << "\nString passed by value: " << std::endl;
	std::cout << "\t\"" << sb << "\"" << std::endl;
}