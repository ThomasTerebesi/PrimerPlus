// to be compiled with namesp.cpp and usenmsp.cpp

#include <string>

namespace pers
{
	struct Person
	{
		std::string fName;
		std::string lName;
	};

	void getPerson(Person &);
	void showPerson(const Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};

	void getDebt(Debt &);
	void showDebt(const Debt &);
	double sumDebts(const Debt ar[], int n);
}