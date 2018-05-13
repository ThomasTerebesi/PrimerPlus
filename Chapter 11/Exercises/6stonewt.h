#pragma once

class Stonewt
{
private:
	enum { LBS_PER_STN = 14 };		// pounds per stone
	int stone;						// whole stones
	double pdsLeft;					// fractional pounds
	double pounds;					// entire weight in pounds
public:
	Stonewt(double lbs);			// constructor for double pounds
	Stonewt(int stn, double lbs);	// constructor for stone, lbs
	Stonewt();						// default constructor
	~Stonewt();						// destructor
	void ShowLBS() const;			// show weight in pounds format
	void ShowSTN() const;			// show weight in stone format

	friend bool operator<(const Stonewt & st1, const Stonewt & st2);
	friend bool operator>(const Stonewt & st1, const Stonewt & st2);
	friend bool operator<=(const Stonewt & st1, const Stonewt & st2);
	friend bool operator>=(const Stonewt & st1, const Stonewt & st2);
	friend bool operator==(const Stonewt & st1, const Stonewt & st2);
	friend bool operator!=(const Stonewt & st1, const Stonewt & st2);
	
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};