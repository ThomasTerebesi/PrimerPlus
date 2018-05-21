#pragma once

#include <iostream>
#include <string>

// abstract base class
class AcctABC
{
private:
	std::string mFullName;
	long mAccountNumber;
	double mBalance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const { return mFullName; }
	long AcctNum() const { return mAccountNumber; }
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;	// pure virtual function
	virtual void ViewAccount() const = 0;	// pure virtual function
	double Balance() const { return mBalance; }
	virtual ~AcctABC() {};
};

// Brass Account class
class Brass : public AcctABC
{
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {};
	virtual void Withdraw(double amt);
	virtual void ViewAccount() const;
	virtual ~Brass();
};

// Brass Plus Account class
class BrassPlus : public AcctABC
{
private:
	double mMaxLoan;
	double mRate;
	double mOwesBank;
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500.0, double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500.0, double r = 0.10);
	virtual void ViewAccount() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { mMaxLoan = m; }
	void ResetRate(double r) { mRate = r; }
	void ResetOwes() { mOwesBank = 0; }
};