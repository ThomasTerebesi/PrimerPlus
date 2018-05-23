// compile with brass.h and brass.cpp

#include <iostream>
#include "brass.h"

int main()
{
	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);

	Piggy.ViewAccount();
	std::cout << std::endl;

	Hoggy.ViewAccount();
	std::cout << std::endl;

	std::cout << "Depositing $1000 into the Hogg Account:" << std::endl;
	Hoggy.Deposit(1000.00);
	std::cout << "Hogg account balance: $" << Hoggy.Balance() << std::endl;

	std::cout << "\nWithdrawing $4200 from the Pigg Account:" << std::endl;
	Piggy.Withdraw(4200.00);
	std::cout << "Pigg account balance: $" << Piggy.Balance() << std::endl;

	std::cout << "\nWithdrawing $4200 from the Hogg Account:" << std::endl;
	Hoggy.Withdraw(4200.00);
	std::cout << std::endl;
	Hoggy.ViewAccount();

	std::cin.get();

	return 0;
}