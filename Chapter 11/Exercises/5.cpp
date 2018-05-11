// compile with 5stonewt.h and 5stonewt.cpp

#include <iostream>
#include "5stonewt.h"

int main()
{
	Stonewt one(9, 2.8);
	Stonewt two(8, 3.5);
	Stonewt three(136.7);
	Stonewt temp;

	std::cout << "One:\t" << one << std::endl;
	std::cout << "Two:\t" << two << std::endl;
	std::cout << "Three:\t" << three << std::endl;

	temp = one + two;
	std::cout << "\nOne + Two:\t" << temp << std::endl;

	temp = one - two;
	std::cout << "One - Two:\t" << temp << std::endl;

	temp = one * 3;
	std::cout << "One * 3:\t" << temp << std::endl;

	temp = 2 * two;
	std::cout << "2 * two:\t" << temp << std::endl;

	three.SetState(Stonewt::LBS_INT);
	std::cout << "\nthree.SetState(Stonewt::LBS_INT): " << three << std::endl;
	three.SetState(Stonewt::LBS_FLOAT);
	std::cout << "three.SetState(Stonewt::LBS_FLOAT): " << three << std::endl;
	three.SetState(Stonewt::STONE);
	std::cout << "three.SetState(Stonewt::STONE): " << three << std::endl;

	std::cin.get();

	return 0;
}