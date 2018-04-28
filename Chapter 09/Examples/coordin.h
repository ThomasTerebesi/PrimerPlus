#ifndef COORDIN_H_
#define COORDIN_H_

const double RAD_TO_DEG = 57.29577951;

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

Polar RectToPolar(Rect xyPos);
void ShowPolar(Polar daPos);

#endif