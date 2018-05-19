#pragma once

class Stock // class declaration
{
private:
	char * company;
	long shares;
	double share_val;
	double total_val;

	// set_tot() automatically becomes an inline function
	// because it's in the class declaration
	void set_tot() { total_val = shares * share_val; };
public:
	Stock();							// default constructor
	Stock(const Stock & s);				// copy constructor
	Stock(const char * co, long n = 0, double pr = 0.0);
	~Stock();							// do-nothing destructor
	Stock & operator=(const Stock & s); // assignment operator overload
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock & topval(const Stock & s) const;

	friend std::ostream & operator<<(std::ostream & os, const Stock & s);
};


