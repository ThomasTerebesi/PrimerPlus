#pragma once

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDB;
	std::ostream & ArrOut(std::ostream & os) const; // private method for scores output
public:
	Student() : std::string("Null Student"), ArrayDB() {}
	explicit Student(const std::string & s) : std::string(s), ArrayDB() {}
	explicit Student(int n) : std::string("Nully"), ArrayDB(n) {}
	Student(const std::string & s, const ArrayDB & a) : std::string(s), ArrayDB(a) {}
	Student(const char * str, const double * pd, int n) : std::string(str), ArrayDB(pd, n) {}
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;

	// friends
	// input
	friend std::istream & operator>>(std::istream & is, Student & stu);	// 1 word
	friend std::istream & getline(std::istream & is, Student & stu);	// 1 line
	// output
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};