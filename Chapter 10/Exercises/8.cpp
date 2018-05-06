// compile with list.h and list.cpp

#include <iostream>
#include "list.h"

template <typename T>
void Square(T & x);

template <typename T>
void Double(T & x);

int main()
{
	List list;

	std::cout << "Add up to " << list.GetMaxItems() << " numbers to a list:" << std::endl;

	while (!list.IsFull())
	{
		double inputNumber;

		std::cout << "ITEM #" << (list.ItemCount() + 1) << ": ";
		std::cin >> inputNumber;
		
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.get();
			std::cout << "\aInput terminated by user." << std::endl;
			break;
		}

		list.Add(inputNumber);

		std::cin.get();
	}

	if (list.IsEmpty())
		std::cout << "No Items were entered." << std::endl;
	else
	{
		std::cout << "\nYou can choose one of the following operations:" << std::endl;
		std::cout << "\tS: Calculate the square of all elements in the list." << std::endl;
		std::cout << "\tD: Calculate the double of all elements in the list." << std::endl;
		std::cout << "\tR: Revert your list to its original contents." << std::endl;
		std::cout << "\tQ: Quit." << std::endl;

		List backupList = list;

		char ch;
		while (std::cin >> ch)
		{
			if (std::cin.fail() || (ch == 'q' || ch == 'Q'))
			{
				std::cin.clear();
				std::cin.get();
				break;
			}

			switch (ch)
			{
			case 's':
			case 'S':
				list.Visit(Square);
				std::cout << "\nHere is the updated data in your list:" << std::endl;
				list.PrintList();
				break;
			case 'd':
			case 'D':
				list.Visit(Double);
				std::cout << "\nHere is the updated data in your list:" << std::endl;
				list.PrintList();
				break;
			case 'r':
			case 'R':
				list = backupList;
				std::cout << "\nList reverted to its original contents:" << std::endl;
				list.PrintList();
				break;
			default:
				std::cout << "\nPlease choose one of the options presented above." << std::endl;
				continue;
			}

			std::cout << "\nChoose one of the following operations:" << std::endl;
			std::cout << "\tS: Calculate the square of all elements in the list." << std::endl;
			std::cout << "\tD: Calculate the double of all elements in the list." << std::endl;
			std::cout << "\tR: Revert your list to its original contents." << std::endl;
			std::cout << "\tQ: Quit." << std::endl;

			std::cin.get();
		}
	}

	return 0;
}

template<typename T>
void Square(T & x)
{
	x *= x;
}

template<typename T>
void Double(T & x)
{
	x = x * 2;
}

