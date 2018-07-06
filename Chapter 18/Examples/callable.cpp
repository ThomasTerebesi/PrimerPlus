// compile with somedefs.h

#include <iostream>
#include "somedefs.h"

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main()
{
	using std::cout;
	using std::endl;

	double y = 1.21;

	cout << "Function pointer dub:" << endl;
	cout << "\t" << use_f(y, dub) << endl;

	cout << "\nFunction pointer square:" << endl;
	cout << "\t" << use_f(y, square) << endl;

	cout << "\nFunction object Fp:" << endl;
	cout << "\t" << use_f(y, Fp(5.0)) << endl;

	cout << "\nFunction object Fq:" << endl;
	cout << "\t" << use_f(y, Fq(5.0)) << endl;

	cout << "\nLambda expression 1:" << endl;
	cout << "\t" << use_f(y, [](double u) { return u * u; }) << endl;

	cout << "\nLambda expression 2:" << endl;
	cout << "\t" << use_f(y, [](double u) { return u + u / 2.0; }) << endl;

	std::cin.get();

	return 0;
}