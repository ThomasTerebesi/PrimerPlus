#include "studenti.h"


// private method
std::ostream & Student::ArrOut(std::ostream & os) const
{
	int i;
	int lim = ArrayDB::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDB::operator[](i) << " ";
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
	if (ArrayDB::size() > 0)
		return ArrayDB::sum() / ArrayDB::size();
	else
		return 0;
}

const std::string & Student::Name() const
{
	return static_cast<const std::string &>(*this);
}

double & Student::operator[](int i)
{
	return ArrayDB::operator[](i);	
}

double Student::operator[](int i) const
{
	return ArrayDB::operator[](i);
}


// friend methods
std::istream & operator>>(std::istream & is, Student & stu)	
{
	is >> static_cast<std::string &>(stu);

	return is;
}

std::istream & getline(std::istream & is, Student & stu)	
{
	getline(is, static_cast<std::string &>(stu));

	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	os << "Scores for " << static_cast<const std::string &>(stu) << ":" << std::endl;
	stu.ArrOut(os);

	return os;
}
