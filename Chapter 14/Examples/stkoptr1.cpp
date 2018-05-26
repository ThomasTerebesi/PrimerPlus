// compile with stacktp1.h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stacktp1.h"

const int NUMBER = 10;

int main()
{
	std::srand(static_cast<int>(time(0)));
	
	std::cout << "Please enter the stack size: ";
	int stackSize;
	std::cin >> stackSize;

	// create an empty stack with stackSize slots
	Stack<const char *> st(stackSize);

	// in basket
	const char * in[NUMBER] = {
		" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
		" 3: Betty Rocker", " 4: Ian Flagranti",
		" 5: Wolfgang Kibble", " 6: Portia Koop",
		" 7: Joy Almondo", " 8: Xaverie Paprika",
		" 9: Juan Moore", "10: Misha Mache"
	};

	// out basket
	const char * out[NUMBER];

	int processed = 0;
	int nextin = 0;

	while (processed < NUMBER)
	{
		if (st.IsEmpty())
			st.Push(in[nextin++]);
		else if (st.IsFull())
			st.Pop(out[processed++]);
		else if (rand() % 2 && nextin < NUMBER)
			st.Push(in[nextin++]);
		else
			st.Pop(out[processed++]);
	}

	for (int i = 0; i < NUMBER; i++)
		std::cout << out[i] << std::endl;

	std::cout << "Bye." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}