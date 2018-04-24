#include <iostream>

int main()
{
	int rats = 101;
	int& rodents = rats; 
	// references need to be initialized when they are declared
	// a reference is something like a const pointer

	std::cout << "rats = " << rats;
	std::cout << ", rodents = " << rodents << std::endl;
	
	rodents++;

	std::cout << "rats = " << rats;
	std::cout << ", rodents = " << rodents << std::endl;

	std::cout << "rats address = " << &rats;
	std::cout << ", rodents address = " << &rodents << std::endl;

	std::cin.get();
	
	return 0;
}