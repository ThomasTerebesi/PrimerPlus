#include <iostream>
#include "brass.h"


// typedefs and helper function prototypes for formatting
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);


// Brass methods
Brass::Brass(const std::string & s, long an, double bal)
{
	mFullName = s;
	mAccountNumber = an;
	mBalance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		std::cout << "Negative deposit not allowed; deposit cancelled." << std::endl;
	else
		mBalance += amt;
}

void Brass::Withdraw(double amt)
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	if (amt < 0)
		std::cout << "Withdrawal amount must be positive; withdrawal cancelled." << std::endl;
	else if (amt <= mBalance)
		mBalance -= amt;
	else
	{
		std::cout << "Withdrawal amount of $" << amt << " exceeds your balance." << std::endl;
		std::cout << "Withdrawal cancelled." << std::endl;
	}

	restore(initialState, prec);
}

double Brass::Balance() const
{
	return mBalance;
}

void Brass::ViewAccount() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	std::cout << "Client: " << mFullName << std::endl;
	std::cout << "Account Number: " << mAccountNumber << std::endl;
	std::cout << "Balance: $" << mBalance << std::endl;

	restore(initialState, prec);
}

Brass::~Brass()
{
}


// BrassPlus methods
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
	: Brass(s, an, bal)
{
	mMaxLoan = ml;
	mOwesBank = 0.0;
	mRate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
	: Brass(ba)	// uses implicit copy constructor
{
	mMaxLoan = ml;
	mOwesBank = 0.0;
	mRate = r;
}

// redefine how ViewAccount() works for derived class
void BrassPlus::ViewAccount() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	Brass::ViewAccount();	// display base class portion; scope-resolution operator to prevent recursion
	std::cout << "Maximum loan: $" << mMaxLoan << std::endl;
	std::cout << "Owed to bank: $" << mOwesBank << std::endl;
	std::cout.precision(3);	// ###.### format
	std::cout << "Loan rate: " << 100 * mRate << "%" << std::endl;

	restore(initialState, prec);
}

// redefine how Withdraw() works for derived class
void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);

	double bal = Balance(); // no scope-resolution operator for Balance, because no redefinition in BrassPluss class
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + mMaxLoan - mOwesBank)
	{
		double advance = amt - bal;
		mOwesBank += advance * (1.0 + mRate);
		std::cout << "Bank advance: $" << advance << std::endl;
		std::cout << "Finance charge: $" << advance * mRate << std::endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		std::cout << "Credit limit exceeded. Transaction cancelled." << std::endl;

	restore(initialState, prec);
}


// helper function definitions for formatting
format setFormat()
{
	// set up ###.## format
	return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}
