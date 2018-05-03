// version 00
#pragma once

#include <string>

class Stock // class declaration
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;

	// set_tot() automatically becomes an inline function
	// because it's in the class declaration
	void set_tot() { total_val = shares * share_val; }; 
public:
	void acquire(const std::string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};


