#pragma once

#include <string>

// Brass Account class
class Brass
{
private:
	std::string mFullName;
	long mAccountNumber;
	double mBalance;
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAccount() const;
	virtual ~Brass();
};

// Brass Plus Account class
class BrassPlus : public Brass
{
private:
	double mMaxLoan;
	double mRate;
	double mOwesBank;
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500.0, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500.0, double r = 0.11125);
	virtual void ViewAccount() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { mMaxLoan = m; }
	void ResetRate(double r) { mRate = r; }
	void ResetOwes() { mOwesBank = 0; }
};