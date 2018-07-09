#include "2cpmv.h"

Cpmv::Cpmv()
	: pi(nullptr)
{
	std::cout << "Default constructor executed." << std::endl;
}

Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;

	std::cout << "String constructor executed." << std::endl;
}

Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;

	std::cout << "Copy constructor executed." << std::endl;
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;

	std::cout << "Move constructor executed." << std::endl;
}

Cpmv::~Cpmv()
{
	delete pi;

	std::cout << "Destructor executed." << std::endl;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{


	if (this == &cp)
	{
		return *this;
		std::cout << "operator=() executed (same object)." << std::endl;
	}

	if (pi == nullptr)
		pi = new Info;

	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;

	std::cout << "operator=() executed (different objects)." << std::endl;

	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	delete pi;

	pi = mv.pi;
	mv.pi = nullptr;

	std::cout << "operator=() executed (move assignment)." << std::endl;

	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	std::cout << "operator+() executed." << std::endl;

	return Cpmv(
		pi->qcode + obj.pi->qcode,
		pi->zcode + obj.pi->zcode
	);
}

void Cpmv::Display() const
{
	if (pi == nullptr)
	{
		std::cout << "\nNull pointer detected." << std::endl;
		return;
	}
	else
	{
		std::cout << "\nAddress:\t" << pi << std::endl;
		std::cout << "qcode:\t\t" << pi->qcode << std::endl;
		std::cout << "zcode:\t\t" << pi->zcode << std::endl;
		std::cout << std::endl;
	}
}
