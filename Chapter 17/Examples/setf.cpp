#include <iostream>

int main()
{
	int temperature = 63;

	std::cout << "Today's water temperature: ";
	std::cout.setf(std::ios_base::showpos);				// show plus sign
	std::cout << temperature << std::endl;

	std::cout << "\nFor our programming friends, that's" << std::endl;
	std::cout << std::hex << temperature << std::endl;	// use hex
	
	std::cout.setf(std::ios_base::uppercase);			// use uppercase in hex
	std::cout.setf(std::ios_base::showbase);			// use 0X prefix for hex
	std::cout << "or" << std::endl;
	std::cout << temperature << std::endl;

	std::cout << "\nHow " << true << "! Oops -- How ";
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << true << '!' << std::endl;

	std::cin.get();

	return 0;
}