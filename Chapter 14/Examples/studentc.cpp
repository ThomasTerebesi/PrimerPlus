#include "studentc.h"


// private method
std::ostream & Student::ArrOut(std::ostream & os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
				os << std::endl;
		}
		if (i % 5 != 0)
			os << std::endl;
	}
	else
		os << "No scores in array." << std::endl;

	return os;
}


// public methods
double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const std::string & Student::Name() const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];	// use valarray<double>::operator[]()
}

double Student::operator[](int i) const
{
	return scores[i];
}


// friend methods
std::istream & operator>>(std::istream & is, Student & stu)	// use string version of operator>>()
{
	is >> stu.name;

	return is;
}

std::istream & getline(std::istream & is, Student & stu)	// use string friend getline(istream &, const string &)
{
	getline(is, stu.name);

	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	os << "Scores for " << stu.name << ":" << std::endl;
	stu.ArrOut(os);	// use private method for scores

	return os;
}
