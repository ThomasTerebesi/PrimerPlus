#include <iostream>

class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0)
		: v1(a), v2(b)
	{
	}

	void mesg();
};

class bad_gmean
{
private:
	double v1;
	double v2;
public:
	bad_gmean(double a = 0, double b = 0)
		: v1(a), v2(b)
	{
	}

	double Value1() { return v1; }
	double Value2() { return v2; }

	const char * mesg();
};