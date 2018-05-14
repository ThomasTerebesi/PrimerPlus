// compile with strngbad.h and strngbad.cpp

#include <iostream>
#include "strngbad.h"

void CallMe1(StringBad &);
void CallMe2(StringBad);

int main()
{
	{
		std::cout << "Starting an inner block." << std::endl;

		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		std::cout << "\n";

		std::cout << "headline1: " << headline1 << std::endl;
		std::cout << "headline2: " << headline2 << std::endl;
		std::cout << "sports: " << sports << std::endl;

		std::cout << "\n";

		CallMe1(headline1);
		std::cout << "headline1: " << headline1 << std::endl;
		CallMe2(headline2);
		std::cout << "headline2: " << headline2 << std::endl;

		std::cout << "Initialize one object to another:" << std::endl;
		StringBad sailor = sports;
		std::cout << "sailor: " << sailor << std::endl;

		std::cout << "\n";

		std::cout << "Assign one object to another:" << std::endl;
		StringBad knot;
		knot = headline1;
		std::cout << "knot: " << knot << std::endl;

		std::cout << "\n";

		std::cout << "Assign a string to an object: " << std::endl;
		StringBad zap = "This works?";
		std::cout << "zap: " << zap << std::endl;

		std::cout << "\n";

		std::cout << "Exiting the block." << std::endl;
	}

	std::cout << "\nEnd of main()." << std::endl;

	std::cin.get();

	return 0;
}

void CallMe1(StringBad & rsb)
{
	std::cout << "String passed by reference: " << std::endl;
	std::cout << "\t\"" << rsb << "\"" << std::endl;
}

void CallMe2(StringBad sb)
{
	std::cout << "String passed by value: " << std::endl;
	std::cout << "\t\"" << sb << "\"" << std::endl;
}