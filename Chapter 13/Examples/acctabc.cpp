#include <iostream>
#include "acctabc.h"


// Abstract Base Class methods
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


// Brass methods

void Brass::Withdraw(double amt)
{
	Formatting f = AcctABC::SetFormat();

	if (amt < 0)
		std::cout << "Withdrawal amount must be positive; withdrawal cancelled." << std::endl;
	else if (amt <= AcctABC::Balance())
		AcctABC::Withdraw(amt);
	else
	{
		std::cout << "Withdrawal amount of $" << amt << " exceeds your balance." << std::endl;
		std::cout << "Withdrawal cancelled." << std::endl;
	}

	AcctABC::Restore(f);
}

void Brass::ViewAccount() const
{
	Formatting f = AcctABC::SetFormat();

	std::cout << "Client: " << FullName() << std::endl;
	std::cout << "Account Number: " << AcctNum() << std::endl;
	std::cout << "Balance: $" << Balance() << std::endl;

	AcctABC::Restore(f);
}

Brass::~Brass()
{
}


// BrassPlus methods
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
	: AcctABC(s, an, bal)
{
	mMaxLoan = ml;
	mOwesBank = 0.0;
	mRate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
	: AcctABC(ba)	// uses implicit copy constructor
{
	mMaxLoan = ml;
	mOwesBank = 0.0;
	mRate = r;
}

void BrassPlus::ViewAccount() const
{
	Formatting f = AcctABC::SetFormat();

	std::cout << "Client: " << FullName() << std::endl;
	std::cout << "Account Number: " << AcctNum() << std::endl;
	std::cout << "Balance: $" << Balance() << std::endl;
	std::cout << "Maximum loan: $" << mMaxLoan << std::endl;
	std::cout << "Owed to bank: $" << mOwesBank << std::endl;
	std::cout.precision(3);
	std::cout << "Loan rate: " << 100 * mRate << "%" << std::endl;

	AcctABC::Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = AcctABC::SetFormat();

	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + mMaxLoan - mOwesBank)
	{
		double advance = amt - bal;
		mOwesBank += advance * (1.0 + mRate);
		std::cout << "Bank advance: $" << advance << std::endl;
		std::cout << "Finance charge: $" << advance * mRate << std::endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		std::cout << "Credit limit exceeded. Transaction cancelled." << std::endl;

	AcctABC::Restore(f);
}
