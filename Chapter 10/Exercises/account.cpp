#include "account.h"
#include <iostream>

Account::Account(std::string depositorName, std::string accountNumber, double balance)
	: mDepositorName(depositorName), mAccountNumber(accountNumber), mBalance(balance)
{
}

Account::~Account()
{
}

void Account::Display() const
{
	std::streamsize prec = std::cout.precision(2);
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "\n" << mDepositorName << "'s account:" << std::endl;
	std::cout << "\tAccount number: " << mAccountNumber << std::endl;
	std::cout << "\tBalance: $" << mBalance << std::endl;

	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);
}

void Account::Deposit(const double amount)
{
	std::streamsize prec = std::cout.precision(2);
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "\nDepositing $" << amount << " in " << mDepositorName << "'s account." << std::endl;
	mBalance += amount;
	std::cout << "\tCurrent balance: $" << mBalance << std::endl;

	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);
}

void Account::Withdraw(const double amount)
{
	std::streamsize prec = std::cout.precision(2);
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "\nWithdrawing $" << amount << " from " << mDepositorName << "'s account." << std::endl;
	mBalance -= amount;
	std::cout << "\tCurrent balance: $" << mBalance << std::endl;

	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);
}
