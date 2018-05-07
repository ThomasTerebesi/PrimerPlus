// compile with mytime1.h and mytime1.cpp

#include <iostream>
#include "mytime1.h"

int main()
{
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	std::cout << "planning time = ";
	planning.Show();

	std::cout << "coding time = ";
	coding.Show();

	std::cout << "fixing time = ";
	fixing.Show();

	total = coding + fixing;
	std::cout << "coding + fixing = ";
	total.Show();

	Time morefixing(3, 28);
	std::cout << "more fixing time = ";
	morefixing.Show();

	total = morefixing.operator+(total);
	std::cout << "morefixing.operator+(total) = ";
	total.Show();

	std::cin.get();

	return 0;
}