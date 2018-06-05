#include <iostream>
#include <string>

int main()
{
	std::string empty;
	std::string small = "bit";
	std::string larger = "Elephants are a girls best friend";

	std::cout << "Contents:" << std::endl;
	std::cout << "\tempty: " << empty << std::endl;
	std::cout << "\tsmall: " << small << std::endl;
	std::cout << "\tlarger: " << larger << std::endl;

	std::cout << "\nSizes:" << std::endl;
	std::cout << "\tempty: " << empty.size() << std::endl;
	std::cout << "\tsmall: " << small.size() << std::endl;
	std::cout << "\tlarger: " << larger.size() << std::endl;
	
	std::cout << "\nCapacities:" << std::endl;
	std::cout << "\tempty: " << empty.capacity() << std::endl;
	std::cout << "\tsmall: " << small.capacity() << std::endl;
	std::cout << "\tlarger: " << larger.capacity() << std::endl;

	empty.reserve(50);
	std::cout << "\nCapacity after empty.reserve(50): " << empty.capacity() << std::endl;

	std::cin.get();

	return 0;
}