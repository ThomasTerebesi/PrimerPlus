#include <cstring>
#include "3dma.h"



// ABCDMA methods
ABCDMA::ABCDMA(const char * l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);

	rating = r;
}

ABCDMA::ABCDMA(const ABCDMA & adma)
{
	label = new char[strlen(adma.label) + 1];
	strcpy_s(label, strlen(adma.label) + 1, adma.label);

	rating = adma.rating;
}

ABCDMA::~ABCDMA()
{
	delete[] label;
}

ABCDMA & ABCDMA::operator=(const ABCDMA & adma)
{
	if (this == &adma)
		return *this;

	delete[] label;

	label = new char[strlen(adma.label) + 1];
	strcpy_s(label, strlen(adma.label) + 1, adma.label);
	rating = adma.rating;

	return *this;
}

std::ostream & operator<<(std::ostream & os, const ABCDMA & adma)
{
	os << "Label: " << adma.label << std::endl;
	os << "Rating: " << adma.rating << std::endl;

	return os;
}

void ABCDMA::View() const 
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}



// BaseDMA methods
BaseDMA::BaseDMA(const char * l, int r)
	:ABCDMA(l, r)
{
}

BaseDMA::BaseDMA(const BaseDMA & bdma)
	:ABCDMA(bdma)
{
}

BaseDMA::~BaseDMA()
{
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & bdma)
{
	os << "BaseDMA - operator<<()" << std::endl;
	os << static_cast<const ABCDMA &>(bdma);

	return os;
}

void BaseDMA::View() const
{
	std::cout << "BaseDMA - View()" << std::endl;
	std::cout << "Label: " << ABCDMA::GetLabel() << std::endl;
	std::cout << "Rating: " << ABCDMA::GetRating() << std::endl;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & bdma)
{
	if (this == &bdma)
		return *this;

	ABCDMA::operator=(bdma);

	return *this;
}



// LacksDMA methods
LacksDMA::LacksDMA(const char * c, const char * l, int r)
	: ABCDMA(l, r)
{
	strcpy_s(color, COL_LEN - 1, c);
	color[COL_LEN - 1] = '\0';
}

LacksDMA::LacksDMA(const LacksDMA & ldma)
	:ABCDMA(ldma)
{
	strcpy_s(color, COL_LEN - 1, ldma.color);
	color[COL_LEN - 1] = '\0';
}

void LacksDMA::View() const
{
	std::cout << "LacksDMA - View()" << std::endl;
	std::cout << "Label: " << ABCDMA::GetLabel() << std::endl;
	std::cout << "Rating: " << ABCDMA::GetRating() << std::endl;
	std::cout << "Color: " << color << std::endl;
}

LacksDMA & LacksDMA::operator=(const LacksDMA & ldma)
{
	if (this == &ldma)
		return *this;

	ABCDMA::operator=(ldma);

	strcpy_s(color, COL_LEN - 1, ldma.color);
	color[COL_LEN - 1] = '\0';

	return *this;
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & ldma)
{
	os << "LacksDMA - operator<<()" << std::endl;
	os << static_cast<const ABCDMA &>(ldma);
	os << "Color: " << ldma.color << std::endl;

	return os;
}



// HasDMA methods
HasDMA::HasDMA(const char * s, const char * l, int r)
	: ABCDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

HasDMA::HasDMA(const HasDMA & hdma)
	:ABCDMA(hdma)
{
	style = new char[strlen(hdma.style) + 1];
	strcpy_s(style, strlen(hdma.style) + 1, hdma.style);
}

HasDMA::~HasDMA()
{
	delete[] style;
}

HasDMA & HasDMA::operator=(const HasDMA & hdma)
{
	if (this == &hdma)
		return *this;

	ABCDMA::operator=(hdma);

	delete[] style;

	style = new char[strlen(hdma.style) + 1];
	strcpy_s(style, strlen(hdma.style) + 1, hdma.style);

	return *this;
}

void HasDMA::View() const
{
	std::cout << "HasDMA - View()" << std::endl;
	std::cout << "Label: " << ABCDMA::GetLabel() << std::endl;
	std::cout << "Rating: " << ABCDMA::GetRating() << std::endl;
	std::cout << "Style: " << style << std::endl;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & hdma)
{
	os << "LacksDMA - operator<<()" << std::endl;
	os << static_cast<const ABCDMA &>(hdma);
	os << "Style: " << hdma.style << std::endl;

	return os;
}