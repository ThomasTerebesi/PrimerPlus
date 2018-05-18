// compile with 4stack.h and 4stack.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "4stack.h"

int main()
{
	srand(static_cast<int>(time(0)));

	Stack sOne;
	std::cout << "Created stack object sOne (size = default). ";

	if (sOne.isempty())
		std::cout << "sOne is empty." << std::endl;

	std::cout << "Filling sOne... ";
	for (int i = 0; i < 10; i++)
		sOne.push(static_cast<unsigned long>((i + 1) * rand() % 1000));
	
	if (sOne.isfull())
		std::cout << "sOne is full." << std::endl;

	std::cout << "Contents of sOne:" << std::endl;
	std::cout << sOne << std::endl;


	Stack sTwo(4);
	std::cout << "\nCreated stack object sTwo (size = 4). ";

	if (sTwo.isempty())
		std::cout << "sTwo is empty." << std::endl;

	std::cout << "Filling sTwo... ";
	for (int i = 0; i < 4; i++)
		sTwo.push(static_cast<unsigned long>((i + 1) * rand() % 1000));

	if (sTwo.isfull())
		std::cout << "sTwo is full." << std::endl;

	std::cout << "Contents of sTwo:" << std::endl;
	std::cout << sTwo << std::endl;


	Stack sThree(sTwo);
	std::cout << "\nCreated stack object sThree via deep copying sTwo." << std::endl;
	std::cout << "Contents of sThree:" << std::endl;
	std::cout << sThree << std::endl;


	std::cout << "\nAssigning sOne to sThree." << std::endl;
	sThree = sOne;
	std::cout << "Contents of sThree:" << std::endl;
	std::cout << sThree << std::endl;

	/* 
	Stack sFour(-2);
	Stack sFive(13);
	*/

	std::cin.get();

	return 0;
}