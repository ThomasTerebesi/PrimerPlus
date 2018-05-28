#pragma once

#include <iostream>
#include <valarray>
#include <string>
#include <utility>

typedef std::pair<std::valarray<int>, std::valarray<int>> PairArray;

class Wine : private PairArray, private std::string
{
private:
	int years;
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	~Wine() {}
	void GetBottles();
	const std::string & Label() const { return static_cast<const std::string &>(*this); }
	int Sum() const;
	void Show() const;
};