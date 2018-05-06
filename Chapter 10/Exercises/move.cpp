#include <iostream>
#include "move.h"

Move::Move(double a, double b)
	: x(a), y(b)
{
}

void Move::showmove() const
{
	std::cout << "X: " << x << std::endl;
	std::cout << "Y: " << y << std::endl;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
