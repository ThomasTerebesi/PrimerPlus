// compile with brass.h and brass.cpp

#include <iostream>
#include <string>
#include "brass.h"

const short CLIENTS = 4;

int main()
{
	Brass * pClients[CLIENTS];
	std::string temp;
	long tempNum;
	double tempBal;
	char kind;

	std::cout << "Pontoon National Bank Account Management" << std::endl;

	for (int i = 0; i < CLIENTS; i++)
	{
		std::cout << "\nEnter client's name: ";
		getline(std::cin, temp);

		std::cout << "Enter client's account number: ";
		std::cin >> tempNum;

		std::cout << "Enter client's opening balance: $";
		std::cin >> tempBal;

		std::cout << "Enter '1' for Brass Account or '2' for BrassPlus Account: ";
		while (std::cin >> kind && (kind != '1' && kind != '2'))
			std::cout << "Enter '1' for Brass Account or '2' for BrassPlus Account: ";

		if (kind == '1')
			pClients[i] = new Brass(temp, tempNum, tempBal);
		else
		{
			double tMax, tRate;
			
			std::cout << "Enter the overdraft limit: $";
			std::cin >> tMax;

			std::cout << "Enter the interest rate as a decimal fraction: ";
			std::cin >> tRate;

			pClients[i] = new BrassPlus(temp, tempNum, tempBal, tMax, tRate);
		}

		while (std::cin.get() != '\n')
			continue;
	}

	std::cout << std::endl;

	for (int i = 0; i < CLIENTS; i++)
	{
		pClients[i]->ViewAccount();
		std::cout << std::endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete pClients[i];	// free memory
	}

	std::cout << "Done." << std::endl;

	std::cin.get();

	return 0;
}