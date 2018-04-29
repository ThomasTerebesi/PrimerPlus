// compile with support.cpp

#include <iostream>

// external variable
double warming = 0.3;

void Update(double dt);
void Local();

int main() // uses global variable
{
	std::cout << "Global warming is " << warming << " degrees." << std::endl;
	Update(0.1);
	std::cout << "Global warming is " << warming << " degrees." << std::endl;
	Local();
	std::cout << "Global warming is " << warming << " degrees." << std::endl;

	std::cin.get();
	
	return 0;
}