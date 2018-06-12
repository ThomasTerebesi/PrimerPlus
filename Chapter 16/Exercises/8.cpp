#include <iostream>
#include <string>
#include <list>

void Display(std::list<std::string> & guestList, bool sort);
void InputGuests(std::list<std::string> & guestList);

int main()
{
	std::list<std::string> Mat;
	std::list<std::string> Pat;

	std::cout << "Mat -- Enter the names of friends you want to invite ('quit' to quit):" << std::endl;
	InputGuests(Mat);
	std::cout << "\nList of friends Mat wants to invite:" << std::endl;
	Display(Mat, true);

	std::cout << "\nPat -- Enter the names of friends you want to invite ('quit' to quit):" << std::endl;
	InputGuests(Pat);
	std::cout << "\nList of friends Pat wants to invite:" << std::endl;
	Display(Pat, true);

	std::list<std::string> MatAndPat(Mat.begin(), Mat.end());
	for (auto guest : Pat)
		MatAndPat.push_back(guest);

	MatAndPat.sort();
	MatAndPat.unique();

	std::cout << "\nList of friends both Mat and Pat want to invite:" << std::endl;
	Display(MatAndPat, false);

	std::cin.get();
	std::cin.get();

	return 0;
}

void Display(std::list<std::string> & guestList, bool sort)
{
	if (sort)
		guestList.sort();

	for (auto guest : guestList)
		std::cout << guest << "\t";
	std::cout << std::endl;
}

void InputGuests(std::list<std::string>& guestList)
{
	std::string input;
	while (std::cin >> input && input != "quit")
		guestList.push_back(input);
}
