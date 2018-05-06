// compile with customer.h and customer.cpp

#include <iostream>
#include <cctype>
#include "customer.h"

int main()
{
	Stack st;
	char ch;
	Item customer;
	double runningTotal = 0.0;

	std::cout << "Please enter A to add a customer," << std::endl;
	std::cout << "P to process a customer, or Q to quit." << std::endl;

	while (std::cin >> ch && toupper(ch) != 'Q')
	{
		while (std::cin.get() != '\n')
			continue;

		if (!isalpha(ch))
		{
			std::cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			if (st.isfull())
				std::cout << "\aThe stack is already full." << std::endl;
			else
			{
				std::cout << "Enter the customer's name: ";
				std::cin >> customer.fullname;
				std::cout << "Enter " << customer.fullname << "'s payment: $";
				std::cin >> customer.payment;
				st.push(customer);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				std::cout << "\aThe stack is already empty." << std::endl;
			else
			{
				st.pop(customer);
				runningTotal += customer.payment;
				std::cout << "Customer " << customer.fullname << " popped." << std::endl;
				std::cout << "Running total: $" << runningTotal << std::endl;
			}
			break;
		}

		std::cout << "\nPlease enter A to add a customer," << std::endl;
		std::cout << "P to process a customer, or Q to quit." << std::endl;
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}