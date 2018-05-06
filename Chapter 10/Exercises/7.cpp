// compile with plorg.h and plorg.cpp

#include <iostream>
#include "plorg.h"

const int ARRAY_SIZE = 5;

int main()
{
	std::cout << "Creating plorg0 and reporting its contents:" << std::endl;
	Plorg plorg0;
	plorg0.Report();
	
	std::cout << "\nChanging plorg0's contentment index to 67 and reporting plorg0's contents:" << std::endl;
	plorg0.SetCI(67);
	plorg0.Report();

	std::cout << "\nCreating plorg1, changing its contentment index to 48 and reporting its contents:" << std::endl;
	Plorg plorg1("Plorgonius III");
	plorg1.SetCI(48);
	plorg1.Report();

	std::cin.get();

	return 0;
}