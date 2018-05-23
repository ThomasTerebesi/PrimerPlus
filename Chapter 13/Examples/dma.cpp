#include <cstring>
#include "dma.h"

// BaseDMA methods

BaseDMA::BaseDMA(const char * l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

BaseDMA::~BaseDMA()
{
	delete[] label;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs)
{
	if (this == &rs)
		return *this;

	delete[] label;

	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;

	return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;

	return os;
}


// LacksDMA methods

LacksDMA::LacksDMA(const char * c, const char * l, int r)
	: BaseDMA(l, r)
{
	strcpy_s(color, COL_LEN - 1, c);
	color[COL_LEN - 1] = '\0';
}

LacksDMA::LacksDMA(const char * c, const BaseDMA & rs)
	: BaseDMA(rs)
{
	strcpy_s(color, COL_LEN - 1, c);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & rs)
{
	os << static_cast<const BaseDMA &>(rs);
	os << "Color: " << rs.color << std::endl;

	return os;
}


// HasDMA methods

HasDMA::HasDMA(const char * s, const char * l, int r)
	: BaseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & rs)
	: BaseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

HasDMA::HasDMA(const HasDMA & hs)
	: BaseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

HasDMA::~HasDMA()
{
	delete[] style;
}

HasDMA & HasDMA::operator=(const HasDMA & rs)
{
	if (this == &rs)
		return *this;

	BaseDMA::operator=(rs);		// copy base portion
	
	delete[] style;

	style = new char[strlen(rs.style) + 1];
	strcpy_s(style, strlen(rs.style) + 1, rs.style);

	return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & rs)
{
	os << static_cast<const BaseDMA &>(rs);
	os << "Style: " << rs.style << std::endl;

	return os;
}
