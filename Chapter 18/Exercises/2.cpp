// compile with 2cpmv.h and 2cpmv.cpp

#include <iostream>
#include "2cpmv.h"

int main()
{
	{
		Cpmv obj1;
		obj1.Display();

		Cpmv obj2("Hello", "World");
		obj2.Display();

		Cpmv obj3(obj2);
		obj3.Display();

		Cpmv obj4(obj2 + obj3);
		obj4.Display();

		obj4 = obj2;
		obj4.Display();

		obj1 = obj4 + obj2;
		obj1.Display();
	}

	std::cin.get();

	return 0;
}