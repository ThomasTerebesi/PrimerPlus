// compile with 1cow.h and 1cow.cpp

#include <iostream>
#include "1cow.h"

int main()
{
	
	std::cout << "Creating object bessy." << std::endl;
	Cow bessy;
	std::cout << "Contents of bessy:" << std::endl;
	bessy.ShowCow();

	std::cout << "\nCreating object lizzy." << std::endl;
	Cow lizzy("Lizzy", "Mooing", 783.6);
	std::cout << "Contents of lizzy:" << std::endl;
	lizzy.ShowCow();

	std::cout << "\nSaving the contents of bessy in new object temp." << std::endl;
	Cow temp(bessy);
	std::cout << "Contents of temp:" << std::endl;
	temp.ShowCow();

	std::cout << "\nbessy = lizzy." << std::endl;
	bessy = lizzy;
	std::cout << "Contents of bessy:" << std::endl;
	bessy.ShowCow();

	std::cin.get();

	return 0;
}