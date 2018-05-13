#include <iostream>
#include "6stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = static_cast<int>(lbs) / LBS_PER_STN; // integer division
	pdsLeft = static_cast<int>(lbs) % LBS_PER_STN + lbs - static_cast<int>(lbs);
	pounds = lbs;
}

// construct Stonewt object from int and double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pdsLeft = lbs;
	pounds = stn * LBS_PER_STN + lbs;
}

// default constructor, weight = 0
Stonewt::Stonewt()
{
	stone = 0;
	pounds = pdsLeft = 0.0;
}

Stonewt::~Stonewt()
{
}

// show weight in pounds
void Stonewt::ShowLBS() const
{
	std::cout << pounds << " pounds" << std::endl;
}

// show weight in stone
void Stonewt::ShowSTN() const
{
	std::cout << stone << " stone, " << pdsLeft << " pounds" << std::endl;
}

bool operator<(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds < st2.pounds;
}

bool operator>(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds > st2.pounds;
}

bool operator<=(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds <= st2.pounds;
}

bool operator>=(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds >= st2.pounds;
}

bool operator==(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds == st2.pounds;
}

bool operator!=(const Stonewt & st1, const Stonewt & st2)
{
	return st1.pounds != st2.pounds;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
	os << s.pounds << " pounds";
	return os;
}
