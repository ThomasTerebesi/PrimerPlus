#include <iostream>
#include "tabtenn1.h"

TableTennisPlayer::TableTennisPlayer(const std::string & fn, const std::string & ln, bool ht)
	: mFirstName(fn), mLastName(ln), mHasTable(ht)
{
}

void TableTennisPlayer::Name() const
{
	std::cout << mLastName << ", " << mFirstName;
}

RatedPlayer::RatedPlayer(unsigned int r, const std::string & fn, const std::string & ln, bool ht)
	: TableTennisPlayer(fn, ln, ht), mRating(r)
{
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & ttp)
	: TableTennisPlayer(ttp), mRating(r)
{
}
