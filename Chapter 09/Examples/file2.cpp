#include <iostream>
#include <cmath>
#include "coordin.h"

// convert rectangular to polar coordinates
Polar RectToPolar(Rect xyPos)
{
	Polar answer;

	answer.distance = sqrt(xyPos.x * xyPos.x + xyPos.y * xyPos.y);
	answer.angle = atan2(xyPos.y, xyPos.x);

	return answer;
}

// show polar coordinates, converting angle to degrees
void ShowPolar(Polar daPos)
{
	std::cout << "distance = " << daPos.distance;
	std::cout << ", angle = " << daPos.angle * RAD_TO_DEG;
	std::cout << " degress\n";
}