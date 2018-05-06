 // compile with account.h and account.cpp

#include <iostream>
#include "account.h"

int main()
{
	Account example("Kayson King", "324-78291", 4223.78);

	example.Display();

	example.Deposit(819.77);

	example.Withdraw(5187.96);

	example.Deposit(627.41);

	example.Display();

	std::cin.get();

	return 0;
}