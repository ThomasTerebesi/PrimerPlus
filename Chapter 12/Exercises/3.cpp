// compile with 3stock20.h and 3stock20.cpp

#include <iostream>
#include "3stock20.h"

const int STOCKS_SIZE = 4;

int main()
{
	// create an array of initialized objects
	Stock stocks[STOCKS_SIZE] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:" << std::endl;
	
	int st;
	for (st = 0; st < STOCKS_SIZE; st++)
		std::cout << stocks[st];

	// set pointer to first element
	const Stock * top = &stocks[0];
	
	for (st = 1; st < STOCKS_SIZE; st++)
		top = &top->topval(stocks[st]); // now top point to the most valuable holding

	std::cout << "\nMost valuable holding:" << std::endl;
	std::cout << *top;


	std::cout << "\nCopy constructor and assignment overload test:" << std::endl;
	Stock test1(stocks[2]);
	Stock test2 = stocks[0];
	std::cout << test1 << test2;
	
	std::cin.get();

	return 0;
}