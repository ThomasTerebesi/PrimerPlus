#include <iostream>
#include "worker0.h"

// Worker methods
Worker::~Worker()	// must implement virtual destructor, even if pure
{
}

void Worker::Set()
{
	std::cout << "Enter worker's name: ";
	getline(std::cin, fullName);
	std::cout << "Enter worker's ID: ";
	std::cin >> id;

	while (std::cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	std::cout << "Name: " << fullName << std::endl;
	std::cout << "Employee ID: " << id << std::endl;
}


// Waiter methods
void Waiter::Set()
{
	Worker::Set();

	std::cout << "Enter waiter's panache rating: ";
	std::cin >> panache;

	while (std::cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	std::cout << "Category: Waiter" << std::endl;
	Worker::Show();
	std::cout << "Panache rating: " << panache << std::endl;
}


// Singer methods
const char * Singer::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	Worker::Set();

	std::cout << "Enter number for singer's vocal range:" << std::endl;

	int i;

	for (i = 0; i < vTypes; i++)
	{
		std::cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
			std::cout << std::endl;
	}
	
	if (i % 4 != 0)
		std::cout << std::endl;

	while (std::cin >> voice && (voice < 0 || voice >= vTypes))
		std::cout << "Please enter a value >= 0 and < " << vTypes << std::endl;

	while (std::cin.get() != '\n')
		continue;
}

void Singer::Show() const
{
	std::cout << "Category: Singer" << std::endl;
	Worker::Show();
	std::cout << "Vocal range: " << pv[voice] << std::endl;
}
