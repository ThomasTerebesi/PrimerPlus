// compile with stack.h and stack.cpp

#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
	Stack st;
	char ch;
	unsigned long po;

	std::cout << "Please enter A to add a purchase order," << std::endl;
	std::cout << "P to process a PO, or Q to quit." << std::endl;

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
			std::cout << "Enter a PO number to add: ";
			std::cin >> po;
			if (st.isfull())
				std::cout << "The stack is already full." << std::endl;
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				std::cout << "The stack is already empty." << std::endl;
			else
			{
				st.pop(po);
				std::cout << "PO #" << po << " popped." << std::endl;
			}
			break;
		}

		std::cout << "\nPlease enter A to add a purchase order," << std::endl;
		std::cout << "P to process a PO, or Q to quit." << std::endl;
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}