#pragma once

#include <string>

class Account
{
private:
	std::string mDepositorName;
	std::string mAccountNumber;
	double mBalance;
public:
	Account(std::string depositorName, std::string accountNumber, double balance);
	~Account();
	void Display() const;
	void Deposit(const double amount);
	void Withdraw(const double amount);
};