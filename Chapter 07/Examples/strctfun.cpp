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

Polar RectToPolar(Rect xypos);
void ShowPolar(Polar dapos);

int main()
{
	Rect rplace;
	Polar pplace;

	std::cout << "Enter the x and y values: ";
	while (std::cin >> rplace.x >> rplace.y)
	{
		pplace = RectToPolar(rplace);
		ShowPolar(pplace);

		std::cout << "Next two numbers (q to quit): ";
	}

	std::cout << "Done! Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}


// convert rectangular to polar coordinates
Polar RectToPolar(Rect xypos)
{
	Polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);

	return answer;
}

// show polar coordinates, converting angle to degrees
void ShowPolar(Polar dapos)
{
	const double RAD_TO_DEG = 57.29577951;

	std::cout << "distance = " << dapos.distance;
	std::cout << ", angle = " << dapos.angle * RAD_TO_DEG;
	std::cout << " degrees" << std::endl;
}
