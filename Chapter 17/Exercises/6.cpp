#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "6emp.h"

const short MAX = 10;

void ShowMenu();
void EatLine();

int main()
{
	abstr_emp * pc[MAX];

	std::string filename = "employees.dat";

	short count = 0;
	char ch;

	std::ifstream fin;
	fin.open(filename);
	
	if (fin.is_open())
	{
		short empType;
		
		while ((fin >> empType).get(ch))
		{
			switch (empType)
			{
			case abstr_emp::Employee:
				pc[count] = new employee;
				pc[count]->GetAll(fin);
				break;
			case abstr_emp::Manager:
				pc[count] = new manager;
				pc[count]->GetAll(fin);
				break;
			case abstr_emp::Fink:
				pc[count] = new fink;
				pc[count]->GetAll(fin);
				break;
			case abstr_emp::Highfink:
				pc[count] = new highfink;
				pc[count]->GetAll(fin);
				break;
			default:
				std::cerr << "\aInvalid employee type: " << empType << std::endl;
				std::cerr << "Program execution terminated." << std::endl;
				std::cin.get();
				exit(EXIT_FAILURE);
				break;
			}

			++count;
		}

		std::cout << count << " employees imported from '" << filename << "':\n" << std::endl;
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			std::cout << std::endl;
		}

		fin.close();
	}

	if (count < MAX)
	{
		while (count < MAX)
		{
			std::cout << "\nThere are " << count << " entries in your list. You can still add " << MAX - count << " entries.\n" << std::endl;

			ShowMenu();
			std::cin >> ch;

			EatLine();

			switch (ch)
			{
			case '1':
				pc[count] = new employee;
				pc[count++]->SetAll();
				break;
			case '2':
				pc[count] = new manager;
				pc[count++]->SetAll();
				break;
			case '3':
				pc[count] = new fink;
				pc[count++]->SetAll();
				break;
			case '4':
				pc[count] = new highfink;
				pc[count++]->SetAll();
				break;
			case 'q':
				break;
			default:
				std::cout << "\aInvalid input. Please try again." << std::endl;
				break;
			}

			if (ch == 'q')
				break;

			std::cout << std::endl;
		}

		std::ofstream fout;
		fout.open("employees.dat");

		if (!fout.is_open())
		{
			std::cerr << "Could not open file '" << filename << "'. Program execution terminated." << std::endl;
			std::cin.get();
			exit(EXIT_FAILURE);
		}

		std::cout << count << " employees in list saved to '" << filename << "':" << std::endl;

		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			std::cout << std::endl;
			pc[i]->WriteAll(fout);
		}

		if (count >= MAX)
			std::cout << "You have reached the maximum number of " << MAX << " entries." << std::endl;
		else
			std::cout << "There are " << count << " entries in your list. You can still add " << MAX - count << " entries next time." << std::endl;

		fout.close();
	}
	else
		std::cout << "You can't save more than " << MAX << " employees in '" << filename << "'." << std::endl;

	EatLine();

	return 0;
}

void ShowMenu()
{
	std::cout << "Choose one of the following ('q' to quit):" << std::endl;
	std::cout << "1: Employee\t2: Manager" << std::endl;
	std::cout << "3: Fink\t\t4: Highfink" << std::endl;
	std::cout << "Please enter your choice: ";
}

void EatLine()
{
	char ch;
	while (std::cin.get(ch) && ch != '\n')
		continue;
}
