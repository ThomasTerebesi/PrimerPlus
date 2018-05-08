#include "vect.h"
#include <cmath>

static const double RAD_TO_DEG = 45.0 / std::atan(1.0);	// compute degrees in one radian

// PRIVATE METHODS

// calculates magnitude from x and y
void VECTOR::Vector::SetMag()
{
	mag = std::sqrt(x * x + y * y);
}

// calculates direction from x and y
void VECTOR::Vector::SetAng()
{
	if (x == 0.0 && y == 0.0)
		ang = 0.0;
	else
		ang = std::atan2(x, y);
}

// set x from polar coordinate
void VECTOR::Vector::SetX()
{
	x = mag * std::cos(ang);
}

// set y from polar coordinate
void VECTOR::Vector::SetY()
{
	y = mag * std::sin(ang);
}

// PUBLIC METHODS

// default constructor
VECTOR::Vector::Vector()
{
	x = y = mag = ang = 0.0;
	mode = RECT;
}

// construct vector from rectangular coordinates if form is RECT
// (the default) or else from polar coordinates if form is POLAR
VECTOR::Vector::Vector(double n1, double n2, Mode form)
{
	Reset(n1, n2, form);
}

// reset vector from rectangular coordinates if form is RECT
// (the default) or else from polar coordinates if form is POLAR
void VECTOR::Vector::Reset(double n1, double n2, Mode form)
{
	mode = form;

	if (form == RECT)
	{
		x = n1;
		y = n2;
		SetMag();
		SetAng();
	}
	else if (form == POL)
	{
		mag = n1;
		ang = n2 / RAD_TO_DEG;
		SetX();
		SetY();
	}
	else
	{
		std::cout << "Incorrect 3rd argument to Vector() -- vector set to 0" << std::endl;
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

// destructor
VECTOR::Vector::~Vector()
{
}

// set to polar mode
void VECTOR::Vector::PolarMode()
{
	mode = POL;
}

// set to rectangular mode
void VECTOR::Vector::RectMode()
{
	mode = RECT;
}

// OPERATOR OVERLOADING

// add two vectors
VECTOR::Vector VECTOR::Vector::operator+(const Vector & b) const
{
	return Vector(x + b.x, y + b.y);
}

// subtract vector b from a
VECTOR::Vector VECTOR::Vector::operator-(const Vector & b) const
{
	return Vector(x - b.x, y - b.y);
}

// reverse sign of vector
VECTOR::Vector VECTOR::Vector::operator-() const
{
	return Vector(-x, -y);
}

// multiply vector by n
VECTOR::Vector VECTOR::Vector::operator*(double n) const
{
	return Vector(n*x, n*y);
}

// FRIEND METHODS

// multiply n by vector a
VECTOR::Vector VECTOR::operator*(double n, const Vector & a)
{
	return a * n;
}

// display rectangular coordinates if mode is RECT,
// else display polar coordinates if mode is POL
std::ostream & VECTOR::operator<<(std::ostream & os, const Vector & v)
{
	if (v.mode == Vector::RECT)
		os << "(x, y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == Vector::POL)
		os << "(m, a) = (" << v.mag << ", " << v.ang << ")";
	else
		os << "Vector object mode is invalid.";

	return os;
}
