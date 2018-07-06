// compile with somedefs.h

#include <iostream>
#include <functional>
#include "somedefs.h"

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main()
{
	double y = 1.21;

	std::function<double(double)> ef1 = dub;
	std::function<double(double)> ef2 = square;
	std::function<double(double)> ef3 = Fp(10.0);
	std::function<double(double)> ef4 = Fq(10.0);
	std::function<double(double)> ef5 = [](double u) { return u * u; };
	std::function<double(double)> ef6 = [](double u) { return u + u / 2.0; };

	std::cout << "Function pointer dub:" << std::endl;
	std::cout << "\t" << use_f(y, ef1) << std::endl;

	std::cout << "\nFunction pointer square:" << std::endl;
	std::cout << "\t" << use_f(y, ef2) << std::endl;

	std::cout << "\nFunction object Fp:" << std::endl;
	std::cout << "\t" << use_f(y, ef3) << std::endl;

	std::cout << "\nFunction object Fq:" << std::endl;
	std::cout << "\t" << use_f(y, ef4) << std::endl;

	std::cout << "\nLambda expression 1:" << std::endl;
	std::cout << "\t" << use_f(y, ef5) << std::endl;

	std::cout << "\nLambda expression 2:" << std::endl;
	std::cout << "\t" << use_f(y, ef6) << std::endl;

	std::cin.get();

	return 0;
}