#include <iostream>
#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const std::string & fn, const std::string & ln, bool ht)
	: mFirstName(fn), mLastName(ln), mHasTable(ht)
{
}

void TableTennisPlayer::Name() const
{
	std::cout << mLastName << ", " << mFirstName;
}
