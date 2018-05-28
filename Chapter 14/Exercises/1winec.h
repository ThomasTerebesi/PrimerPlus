#pragma once

#include <iostream>
#include <valarray>
#include <string>
#include <utility>

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef std::pair<ArrayInt, ArrayInt> PairArray;
	std::string label;
	PairArray vintagesAndBottles;
	int years;
public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	~Wine() {}
	void GetBottles();
	const std::string & Label() const { return label; }
	int Sum() const;
	void Show() const;
};