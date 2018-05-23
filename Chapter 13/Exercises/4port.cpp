#include <iostream>
#include <cstring>
#include "4port.h"

// Port methods
Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);

	strcpy_s(style, 20, st);

	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);

	strcpy_s(style, 20, p.style);

	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;

	delete[] brand;

	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);

	strcpy_s(style, 20, p.style);

	bottles = p.bottles;

	return *this;
}

Port & Port::operator+=(int b)
{
	if (b < 0)
	{
		operator-=(-b);
		return *this;
	}

	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	if (b > bottles)
	{
		std::cout << "Cannot subtract " << b << " bottles from " << bottles << " available bottles. Operation terminated." << std::endl;
		return *this;
	}

	bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "\nBrand: " << brand << std::endl;
	std::cout << "Style: " << style << std::endl;
	std::cout << "Bottles available: " << bottles << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
	std::cout << "\nBrand: " << p.brand << std::endl;
	std::cout << "Style: " << p.style << std::endl;
	std::cout << "Bottles available: " << p.bottles << std::endl;

	return os;
}


// VintagePort methods

VintagePort::VintagePort()
	: Port("none", "Vintage", 0)
{
	nickname = new char[strlen("none") + 1];
	strcpy_s(nickname, strlen("none") + 1, "none");

	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);

	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
	: Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);

	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;

	Port::operator=(vp);

	delete[] nickname;

	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);

	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
	os << static_cast<const Port &>(vp);
	os << "Nickname: " << vp.nickname << std::endl;
	os << "Year: " << vp.year << std::endl;

	return os;
}
