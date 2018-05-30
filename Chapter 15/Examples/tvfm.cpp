#include <iostream>
#include "tvfm.h"

bool Tv::volUp()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::volDown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanUp()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chanDown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	std::cout << "TV is " << (state == Off ? "Off" : "On") << std::endl;

	if (state == On)
	{
		std::cout << "Volume setting = " << volume << std::endl;
		std::cout << "Channel setting = " << channel << std::endl;
		std::cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << std::endl;
		std::cout << "Input = " << (input == TV ? "TV" : "DVD") << std::endl;
	}
}




