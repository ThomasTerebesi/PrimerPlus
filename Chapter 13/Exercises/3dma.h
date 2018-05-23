#pragma once

#include <iostream>

class ABCDMA
{
private:
	char * label;
	int rating;
protected:
	const char * GetLabel() const { return label; }
	int GetRating() const { return rating; }
public:
	ABCDMA(const char * l = "null", int r = 0);
	ABCDMA(const ABCDMA & adma);
	virtual ~ABCDMA() = 0;
	virtual void View() const = 0;
	ABCDMA & operator=(const ABCDMA & adma);
	friend std::ostream & operator<<(std::ostream & os, const ABCDMA & adma);
};


class BaseDMA : public ABCDMA
{
public:
	BaseDMA(const char * l = "null", int r = 0);
	BaseDMA(const BaseDMA & bdma);
	virtual ~BaseDMA();
	virtual void View() const;
	BaseDMA & operator=(const BaseDMA & bdma);
	friend std::ostream & operator<<(std::ostream & os, const BaseDMA & bdma);
};


class LacksDMA : public ABCDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	LacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	LacksDMA(const LacksDMA & ldma);
	virtual void View() const;
	LacksDMA & operator=(const LacksDMA & ldma);
	friend std::ostream & operator<<(std::ostream & os, const LacksDMA & ldma);
};


class HasDMA : public ABCDMA
{
private:
	char * style;
public:
	HasDMA(const char * s = "none", const char * l = "null", int r = 0);
	HasDMA(const HasDMA & hdma);
	~HasDMA();
	HasDMA & operator=(const HasDMA & hdma);
	friend std::ostream & operator<<(std::ostream & os, const HasDMA & hdma);
	virtual void View() const;
};