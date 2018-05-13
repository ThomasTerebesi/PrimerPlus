#include <iostream>
#include "5stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, State st)
{
	stone = static_cast<int>(lbs) / LBS_PER_STN;
	pdsLeft = static_cast<int>(lbs) % LBS_PER_STN + lbs - static_cast<int>(lbs);
	pounds = lbs;
	state = st;
}

// construct Stonewt object from int and double values
Stonewt::Stonewt(int stn, double lbs, State st)
{
	stone = stn;
	pdsLeft = lbs;
	pounds = stn * LBS_PER_STN + lbs;
	state = st;
}

// default constructor, weight = 0
Stonewt::Stonewt()
{
	stone = 0;
	pounds = pdsLeft = 0.0;
	state = STONE;
}

Stonewt::~Stonewt()
{
}

void Stonewt::SetState(const State st)
{
	switch (st)
	{
	case Stonewt::STONE:
		state = Stonewt::STONE;
		break;
	case Stonewt::LBS_INT:
		state = Stonewt::LBS_INT;
		break;
	case Stonewt::LBS_FLOAT:
		state = Stonewt::LBS_FLOAT;
		break;
	default:
		std::cout << "Unknown state argument. Setting state to STONE." << std::endl;
		state = Stonewt::STONE;
		break;
	}
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
	return Stonewt(s1.pounds + s2.pounds);
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
	return Stonewt(s1.pounds - s2.pounds);
}

Stonewt operator*(const Stonewt & s, const double d)
{
	return Stonewt(s.pounds * d);
}

Stonewt operator*(const double d, const Stonewt & s)
{
	return s * d;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
	switch (s.state)
	{
	case Stonewt::STONE:
		os << s.stone << " stone, " << s.pdsLeft << " pounds";
		break;
	case Stonewt::LBS_INT:
		std::cout << static_cast<int>(s.pounds) << " pounds";
		break;
	case Stonewt::LBS_FLOAT:
		std::cout << s.pounds << " pounds";
		break;
	default:
		os << "Unknown state. Output terminated.";
		break;
	}

	return os;
}
