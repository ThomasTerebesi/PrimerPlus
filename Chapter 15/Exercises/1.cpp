// compile with 1tv.h and 1tv.cpp

#include <iostream>
#include "1tv.h"

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
	grey.DisplayRemoteMode();

	std::cout << "\n42\" settings after using remote:" << std::endl;
	s42.settings();

	std::cout << "\nToggling the remote control's mode with the 42\" TV: " << std::endl;
	s42.ToggleRemoteMode(grey);

	std::cout << "\nTurning the 42\" TV off and trying to toggle the remote controls's mode again:" << std::endl;
	s42.onOff();
	s42.ToggleRemoteMode(grey);

	std::cout << "\nTurning the 42\" TV on again and trying to toggling the remote control's mode once more:" << std::endl;
	s42.onOff();
	s42.ToggleRemoteMode(grey);

	Tv s58(Tv::On);
	s58.setMode();
	grey.setChan(s58, 28);

	std::cout << "\n58\" settings:" << std::endl;
	s58.settings();

	std::cin.get();

	return 0;
}