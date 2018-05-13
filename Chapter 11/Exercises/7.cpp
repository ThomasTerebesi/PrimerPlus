// compile with 7complex.h and 7complex.cpp

#include <iostream>
#include "7complex.h"

int main()
{
	Complex a(3.0, 4.0);
	Complex c;

	std::cout << "Enter a complex number (q to quit):" << std::endl;

	while (std::cin >> c)
	{
		std::cout << "c is " << c << std::endl;
		std::cout << "complex conjugate is " << ~c << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "a + c is " << a + c << std::endl;
		std::cout << "a - c is " << a - c << std::endl;
		std::cout << "a * c is " << a * c << std::endl;
		std::cout << "2 * c is " << c * 2 << std::endl;
		std::cout << "\nEnter a complex number (q to quit):" << std::endl;
	}

	return 0;
}