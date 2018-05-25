// compile with stacktp.h

#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

int main()
{
	Stack<std::string> st;	// create an empty stack
	char ch;
	std::string po;

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
			if (st.IsFull())
				std::cout << "Stack already full." << std::endl;
			else
			{
				std::cout << "Enter a PO number to add: ";
				std::cin >> po;
				st.Push(po);
			}
			break;
		case 'P':
		case 'p':
			if (st.IsEmpty())
				std::cout << "Stack already empty." << std::endl;
			else
			{
				st.Pop(po);
				std::cout << "PO #" << po << " popped." << std::endl;
			}
			break;
		}

		std::cout << "\nPlease enter A to add a purchase order," << std::endl;
		std::cout << "P to process a PO, or Q to quit." << std::endl;
	}

	std::cout << "\nBye." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}