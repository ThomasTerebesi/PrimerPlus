#include <iostream>
#include "acctabc.h"

// Abstract Base Class
AcctABC::Formatting AcctABC::SetFormat() const
{
	// set up ###.## format
	Formatting f;
	f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	f.pr = std::cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f) const
{
	std::cout.setf(f.flag, std::ios_base::floatfield);
	std::cout.precision(f.pr);
}

AcctABC::AcctABC(const std::string & s, long an, double bal)
{
	mFullName = s;
	mAccountNumber = an;
	mBalance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		std::cout << "Negative deposit not allowed; deposit cancelled." << std::endl;
	else
		mBalance += amt;
}

void AcctABC::Withdraw(double amt)
{
	mBalance -= amt;
}
