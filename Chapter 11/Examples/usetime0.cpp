// compile with mytime0.h and mytime0.cpp

#include <iostream>
#include "mytime0.h"

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

	total = coding.Sum(fixing);
	std::cout << "coding.Sum(fixing) = ";
	total.Show();

	std::cin.get();

	return 0;
}