#pragma once

#include <iostream>
#include <stdexcept>

class bad_hmean : public std::invalid_argument
{
public:
	bad_hmean()
		: std::invalid_argument("hmean(): One value must not be the inverse of the other.\n")
	{
	}
};

class bad_gmean : public std::invalid_argument
{
public:
	bad_gmean()
		: std::invalid_argument("gmean(): Both values must be greater than zero.\n")
	{
	}
};