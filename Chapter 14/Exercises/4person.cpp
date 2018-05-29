#include <iostream>
#include <cstdlib>
#include <ctime>

#include "4person.h"

template <typename T>
void InvalidInput(const std::string & msg, T & var)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << msg;
		std::cin >> var;
	}
}


// Person class members
void Person::Data() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
}

void Person::Get()
{
	std::cout << "First name: ";
	getline(std::cin, firstName);
	std::cout << "Last name: ";
	getline(std::cin, lastName);
}

Person::Person(const std::string & fn, const std::string & ln)
	: firstName(fn), lastName(ln)
{
}

Person::~Person()
{
}

void Person::Show() const
{
	std::cout << "Category: Person" << std::endl;
	Data();
}

void Person::Set()
{
	std::cout << "Enter the person's information below." << std::endl;
	Get();
}

// Gunslinger class members
void Gunslinger::Data() const
{
	std::cout << Person::FullName() << "'s draw time: " << drawTime << std::endl;
	std::cout << "Notches on " << Person::FullName() << "'s gun: " << notches << std::endl;
}

void Gunslinger::Get()
{
	std::cout << "Enter " <<  Person::FullName() << "'s draw time: ";
	std::cin >> drawTime;
	InvalidInput("Please enter a valid draw time: ", drawTime);

	std::cout << "Enter the number of notches on " << Person::FullName() << "'s gun: ";
	std::cin >> notches;
	InvalidInput("Please enter a valid number of notches: ", notches);
}

Gunslinger::Gunslinger(const std::string & fn, const std::string & ln, double dt, int n)
	: Person(fn, ln), drawTime(dt), notches(n)
{
}

Gunslinger::Gunslinger(const Person & p, double dt, int n)
	: Person(p), drawTime(dt), notches(n)
{
}

void Gunslinger::Show() const
{
	std::cout << "Category: Gunslinger" << std::endl;
	Person::Data();
	Data();
}

void Gunslinger::Set()
{
	std::cout << "Enter the gunslinger's information below." << std::endl;
	Person::Get();
	Get();
}


// PokerPlayer class members
PokerPlayer::PokerPlayer(const std::string & fn, const std::string & ln)
	: Person(fn, ln)
{
	cardValue = Draw();
}

int PokerPlayer::Draw() const
{
	return rand() % 52 + 1;
}

void PokerPlayer::Show() const
{
	std::cout << "Category: Poker Player" << std::endl;
	Person::Data();
}

void PokerPlayer::Set()
{
	std::cout << "Enter the poker player's information below." << std::endl;
	Person::Get();
}


// BadDude class members
void BadDude::Data() const
{
	Person::Data();
	Gunslinger::Data();
}

void BadDude::Get()
{
	Gunslinger::Get();
}

BadDude::BadDude(const std::string & fn, const std::string & ln, double dt, int n)
	: Person(fn, ln), Gunslinger(fn, ln, dt, n), PokerPlayer(fn, ln)
{
	Cdraw();
}

void BadDude::Show() const
{
	std::cout << "Category: Bad Dude" << std::endl;
	Data();
}

void BadDude::Set()
{
	std::cout << "Enter the bad dude's information below." << std::endl;
	Person::Get();
	Get();
}
