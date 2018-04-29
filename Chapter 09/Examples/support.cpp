// compile with external.cpp

#include <iostream>

extern double warming; // use warming from external.cpp

void Update(double dt);
void Local();

void Update(double dt) // modifies global variable
{
	extern double warming; // optional redeclaration
	warming += dt; // uses global warming

	std::cout << "Updating global warming to " << warming << " degrees." << std::endl;
}

void Local() // uses local variable
{
	double warming = 0.8; // new variable hides external one

	std::cout << "Local warming = " << warming << " degrees." << std::endl;

	// access global variable with the scope resolution operator
	std::cout << "But global warming = " << ::warming << " degrees." << std::endl;
}