#pragma once

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDB;
	std::string name;		// contained object
	ArrayDB scores;			// contained object
	std::ostream & ArrOut(std::ostream & os) const; // private method for scores output
public:
	Student() : name("Null Student"), scores() {}
	explicit Student(const std::string & s) : name(s), scores() {}
	explicit Student(int n) : name("Nully"), scores(n) {}
	Student(const std::string & s, const ArrayDB & a) : name(s), scores(a) {}
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
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