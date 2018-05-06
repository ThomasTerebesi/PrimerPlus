// compile with stock10.h and stock10.cpp

#include <iostream>
#include "stock10.h"

int main()
{
	{
		std::cout << "Using constructors to create new objects." << std::endl;
		
		Stock stock1("NanoSmart", 12, 20.0); // syntax 1
		stock1.show();

		Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2; may or may not create a temporary object
		stock2.show();

		// if you can set object values either through initialization or by assignment, choose initialization, it's more efficient usually

		std::cout << "Assigning stock1 to stock2." << std::endl;
		stock2 = stock1;
		
		std::cout << "Listing stock1 and stock2:" << std::endl;
		stock1.show();
		stock2.show();

		std::cout << "Using a constructor to reset an object:" << std::endl;
		stock1 = Stock("Nifty Foods", 10, 50.0); // always causes creation of a temporary object

		std::cout << "Revised stock1:" << std::endl;
		stock1.show();
		std::cout << "Done." << std::endl;
	}

	std::cin.get();

	return 0;
}