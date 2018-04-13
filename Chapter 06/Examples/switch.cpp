#include <iostream>


void ShowMenu();
void Report();
void Comfort();


int main()
{
	ShowMenu();

	int choice;
	std::cin >> choice;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			std::cout << "\a";
			break;
		case 2:
			Report();
			break;
		case 3:
			std::cout << "The boss was in all day." << std::endl;
			break;
		case 4:
			Comfort();
			break;
		default:
			std::cout << "That's not a choice." << std::endl;
			break;
		}

		ShowMenu();
		std::cin >> choice;
	}

	std::cout << "Bye!" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}


void ShowMenu()
{
	std::cout << "Please enter 1, 2, 3, 4 or 5:" << std::endl;
	std::cout << "1) alarm\t2) report" << std::endl;
	std::cout << "3) alibi\t4) comfort" << std::endl;
	std::cout << "5) quit" << std::endl;
}


void Report()
{
	std::cout << "It's been an excellent week for business." << std::endl;
	std::cout << "Sales are up 120%, expenses are down 35%." << std::endl;
}


void Comfort()
{
	std::cout << "Your employees think you are the finest CEO" << std::endl;
	std::cout << "in the industry. The board of directors think" << std::endl;
	std::cout << "you are the finest CEO in the industry." << std::endl;
}