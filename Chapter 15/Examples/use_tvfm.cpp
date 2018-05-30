// compile with tvfm.h and tvfm.cpp

#include <iostream>
#include "tvfm.h"

int main()
{
	Tv s42;
	std::cout << "Initial settings for 42\" TV:" << std::endl;
	s42.settings();
	s42.onOff();
	s42.chanUp();

	std::cout << "\nAdjusted settings for 42\" TV:" << std::endl;
	s42.settings();

	Remote grey;
	grey.setChan(s42, 10);
	grey.volUp(s42);
	grey.volUp(s42);

	std::cout << "\n42\" settings after using remote:" << std::endl;
	s42.settings();

	Tv s58(Tv::On);
	s58.setMode();
	grey.setChan(s58, 28);

	std::cout << "\n58\" settings:" << std::endl;
	s58.settings();

	std::cin.get();

	return 0;
}