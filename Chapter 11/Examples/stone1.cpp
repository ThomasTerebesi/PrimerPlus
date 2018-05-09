// compile with stonewt1.h and stonewt1.cpp

#include <iostream>
#include "stonewt1.h"

void Display(const Stonewt & st, int n);

int main()
{
	Stonewt poppins(9, 2.8);	// 9 stone, 2.8 pounds
	double p_wt = poppins;		// implicit conversion

	std::cout << "Convert to double => ";
	std::cout << "Poppins: " << p_wt << " pounds." << std::endl;
	std::cout << "Convert to int => ";
	std::cout << "Poppins: " << int(poppins) << " pounds." << std::endl;
	// could have used "static_cast<int>(poppins)" too

	std::cin.get();

	return 0;
}
