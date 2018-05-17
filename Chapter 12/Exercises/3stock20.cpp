#include <iostream>
#include <cstring>
#include "3stock20.h"

Stock::Stock()
{
	company = new char[8];
	strcpy_s(company, 8, "No name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const Stock & s)
{
	if (company != nullptr)
		delete[] company;

	unsigned short length = strlen(s.company);
	company = new char[length + 1];
	strcpy_s(company, length + 1, s.company);

	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}

Stock::Stock(const char * co, long n, double pr)
{
	unsigned short length = strlen(co);
	company = new char[length + 1];
	strcpy_s(company, length + 1, co);

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
	delete[] company;
}

Stock & Stock::operator=(const Stock & s)
{
	if (this == &s)
		return *this;

	delete[] company;

	unsigned short length = strlen(s.company);
	company = new char[length + 1];
	strcpy_s(company, length + 1, s.company);

	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;

	return *this;
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

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	std::streamsize prec = os.precision(3);
	std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed);

	os << "Company: " << s.company << "  Shares: " << s.shares << std::endl;
	os << "  Share Price: $" << s.share_val;

	os.precision(2);
	os << "  Total Worth: $" << s.total_val << std::endl;

	os.precision(prec);
	os.setf(orig, std::ios_base::floatfield);

	return os;
}
