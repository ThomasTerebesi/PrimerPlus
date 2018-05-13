#pragma once

class Stonewt
{
public:
	enum State { STONE, LBS_INT, LBS_FLOAT };

private:
	enum { LBS_PER_STN = 14 };
	int stone;
	double pdsLeft;
	double pounds;
	State state;

public:
	Stonewt(double lbs, State st = STONE);
	Stonewt(int stn, double lbs, State st = STONE);
	Stonewt();
	~Stonewt();

	void SetState(State st);

	friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
	friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
	friend Stonewt operator*(const Stonewt & s1, const double d);
	friend Stonewt operator*(const double d, const Stonewt & s2);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};