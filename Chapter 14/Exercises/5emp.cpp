#include "5emp.h"

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


// abstr_emp class members
abstr_emp::abstr_emp()
	: fname("undefined"), lname("undefined"), job("undefined")
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
	: fname(fn), lname(ln), job(j)
{
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::ShowAll() const
{
	std::cout << "First name: " << fname << std::endl;
	std::cout << "Last name: " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
	std::cout << "Enter the employee's first name: ";
	getline(std::cin, fname);

	std::cout << "Enter the employee's last name: ";
	getline(std::cin, lname);

	std::cout << "Enter " << fname << " " << lname << "'s job title: ";
	getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << e.fname << " " << e.lname;
	return os;
}


// employee class members
employee::employee()
	: abstr_emp()
{
}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j)
	: abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	std::cout << "Category: Employee" << std::endl;
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}


// manager class members
manager::manager()
	: abstr_emp(), inchargeof(0)
{
}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{
	if (inchargeof < 0)
	{
		std::cout << "Invalid value for variable 'inchargeof'. Value set to 0." << std::endl;
		inchargeof = 0;
	}
}

manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico)
{
	if (inchargeof < 0)
	{
		std::cout << "Invalid value for variable 'inchargeof'. Value set to 0." << std::endl;
		inchargeof = 0;
	}
}

manager::manager(const manager & m)
	: abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
	std::cout << "Category: Manager" << std::endl;
	abstr_emp::ShowAll();
	std::cout << *this << " is in charge of " << inchargeof << " people." << std::endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the number of people " << *this << " is in charge of: ";
	std::cin >> inchargeof;
	InvalidInput("Please enter a valid number of people: ", inchargeof);

	while (inchargeof < 0)
	{
		std::cout << "Please enter a valid number of people : " << std::endl;
		std::cin >> inchargeof;
		InvalidInput("Please enter a valid number of people: ", inchargeof);
	}
}


// fink class members
fink::fink()
	: abstr_emp(), reportsto("undefined")
{
}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo)
	: abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e)
	: abstr_emp(e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
	std::cout << "Category: Fink" << std::endl;
	abstr_emp::ShowAll();
	std::cout << *this << " reports to " << reportsto << "." << std::endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter the person's name " << *this << " reports to: ";
	getline(std::cin, reportsto);
}


// highfink class members
highfink::highfink()
	: abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager & m, const std::string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink & h)
	: abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
	std::cout << "Category: Highfink" << std::endl;
	abstr_emp::ShowAll();
	std::cout << *this << " is in charge of " << InChargeOf() << " people." << std::endl;
	std::cout << *this << " reports to " << ReportsTo() << "." << std::endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();

	std::cout << "Enter the number of people " << *this << " is in charge of: ";
	std::cin >> InChargeOf();
	InvalidInput("Please enter a valid number of people: ", InChargeOf());

	while (InChargeOf() < 0)
	{
		std::cout << "Please enter a valid number of people : " << std::endl;
		std::cin >> InChargeOf();
		InvalidInput("Please enter a valid number of people: ", InChargeOf());
	}

	std::cin.get();

	std::cout << "Enter the person's name " << *this << " reports to: ";
	getline(std::cin, ReportsTo());
}
