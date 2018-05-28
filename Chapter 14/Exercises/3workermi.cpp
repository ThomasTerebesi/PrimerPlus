#include <iostream>
#include "3workermi.h"

// Worker methods
Worker::~Worker()	// must implement virtual destructor, even if pure
{
}

void Worker::Data() const
{
	std::cout << "Name: " << fullName << std::endl;
	std::cout << "Employee ID: " << id << std::endl;
}

void Worker::Get()
{
	getline(std::cin, fullName);
	std::cout << "Enter worker's ID: ";
	std::cin >> id;
	
	while (std::cin.get() != '\n')
		continue;
}


// Waiter methods
void Waiter::Data() const
{
	std::cout << "Panache rating: " << panache << std::endl;
}

void Waiter::Get()
{
	std::cout << "Enter waiter's panache rating: ";
	std::cin >> panache;

	while (std::cin.get() != '\n')
		continue;
}

void Waiter::Set()
{
	std::cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	std::cout << "Category: Waiter" << std::endl;
	Worker::Data();
	Data();
}


// Singer methods
const char * Singer::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Data() const
{
	std::cout << "Vocal range: " << pv[voice] << std::endl;
}

void Singer::Get()
{
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

void Singer::Set()
{
	std::cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	std::cout << "Category: Singer" << std::endl;
	Worker::Data();
	Data();
}


// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	std::cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	std::cout << "Category: Singing Waiter" << std::endl;
	Worker::Data();
	Data();
}
