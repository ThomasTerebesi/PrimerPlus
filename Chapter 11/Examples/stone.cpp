// compile with stonewt.h and stonewt.cpp

#include <iostream>
#include "stonewt.h"

void Display(const Stonewt & st, int n);

int main()
{
	Stonewt incognito = 275;	// uses constructor to initialize
	Stonewt wolfe(285.7);		// same as "Stonewt wolfe = 285.7;"
	Stonewt taft(21, 8);

	std::cout << "The celebrity weighed ";
	incognito.ShowSTN();
	std::cout << "The detective weighed ";
	wolfe.ShowSTN();
	std::cout << "The President weighed ";
	taft.ShowLBS();

	incognito = 276.8;	// uses constructor for conversion
	taft = 325;			// same as "taft = Stonewt(325);"

	std::cout << "After dinner, the celebrity weighed ";
	incognito.ShowSTN();
	std::cout << "After dinner, the President weighed ";
	taft.ShowLBS();

	Display(taft, 2);
	
	std::cout << "The wrestler weighed even more." << std::endl;
	Display(422, 2);
	std::cout << "No stone left unearned." << std::endl;

	std::cin.get();

	return 0;
}

void Display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Wow! ";
		st.ShowSTN();
	}
}