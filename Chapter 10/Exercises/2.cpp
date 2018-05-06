// compile with person.h and person.cpp

#include <iostream>
#include "person.h"

int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");

	std::cout << "one.Show():" << std::endl;
	one.Show();
	std::cout << "one.FormalShow():" << std::endl;
	one.FormalShow();

	std::cout << "two.Show():" << std::endl;
	two.Show();
	std::cout << "two.FormalShow():" << std::endl;
	two.FormalShow();

	std::cout << "three.Show():" << std::endl;
	three.Show();
	std::cout << "three.FormalShow():" << std::endl;
	three.FormalShow();

	std::cin.get();

	return 0;
}