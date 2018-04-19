#include <iostream>
#include <cmath>

struct Polar
{
	double distance;
	double angle;
};

struct Rect
{
	double x;
	double y;
};

void RectToPolar(const Rect * pxy, Polar * pda);
void ShowPolar(const Polar * pda);

int main()
{
	Rect rplace;
	Polar pplace;

	std::cout << "Enter the x and y values: ";
	while (std::cin >> rplace.x >> rplace.y)
	{
		RectToPolar(&rplace, &pplace);
		ShowPolar(&pplace);

		std::cout << "Next two numbers (q to quit): ";
	}

	std::cout << "Done! Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}


// convert rectangular to polar coordinates
void RectToPolar(const Rect * pxy, Polar * pda)
{
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}

// show polar coordinates, converting angle to degrees
void ShowPolar(const Polar * pda)
{
	const double RAD_TO_DEG = 57.29577951;

	std::cout << "distance = " << pda->distance;
	std::cout << ", angle = " << pda->angle * RAD_TO_DEG;
	std::cout << " degrees" << std::endl;
}
