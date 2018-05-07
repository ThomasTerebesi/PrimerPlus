// compile with mytime1.h and mytime1.cpp

#include <iostream>
#include "mytime2.h"

int main()
{
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	std::cout << "weeding time = ";
	weeding.Show();

	std::cout << "waxing time = ";
	waxing.Show();

	std::cout << "total work time = ";
	total = weeding + waxing;
	total.Show();

	diff = weeding - waxing;
	std::cout << "weeding time - waxing time = ";
	diff.Show();

	adjusted = total * 1.5;
	std::cout << "adjusted work time = ";
	adjusted.Show();

	std::cin.get();

	return 0;
}