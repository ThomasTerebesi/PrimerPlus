#include <iostream>
#include "stock20.h"

Stock::Stock()
{
	company = "No name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0." << std::endl;

		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted." << std::endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted." << std::endl;
	}
	else if (num > shares)
	{
		std::cout << "You can't sell more than you have! "
			<< "Transaction is aborted." << std::endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	std::streamsize prec = std::cout.precision(3);
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "Company: " << company << "  Shares: " << shares << std::endl;
	std::cout << "  Share Price: $" << share_val;

	std::cout.precision(2);
	std::cout << "  Total Worth: $" << total_val << std::endl;

	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);
}

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}