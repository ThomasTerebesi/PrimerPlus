#include <iostream>
#include "coordin.h"

int main()
{
	Rect rPlace;
	Polar pPlace;

	std::cout << "Enter the x and y values: ";
	while (std::cin >> rPlace.x >> rPlace.y)
	{
		pPlace = RectToPolar(rPlace);
		ShowPolar(pPlace);
		std::cout << "Next two numbers (q to quit): ";
	}

	std::cout << "Bye!\n" << std::endl;

	return 0;
}