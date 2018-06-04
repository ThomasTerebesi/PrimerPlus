#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class BaseError : virtual public std::logic_error
{
private:
	double argument1;
	double argument2;
public:
	BaseError(double a1, double a2, const std::string & str = "")
		: std::logic_error(str), argument1(a1), argument2(a2)
	{
	}

	virtual ~BaseError() = 0;
	virtual void Report() const = 0;
};

class bad_hmean : public BaseError
{
public:
	bad_hmean(double a1 = 0, double a2 = 0, const std::string str = "")
		: std::logic_error(str), BaseError(a1, a2, str)
	{
	}

	void Report() const;
};

class bad_gmean : public BaseError
{
public:
	bad_gmean(double a1 = 0, double a2 = 0, const std::string str = "")
		: std::logic_error(str), BaseError(a1, a2, str)
	{
	}

	void Report() const;
};