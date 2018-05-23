#pragma once

#include <string>

// simple base class
class TableTennisPlayer
{
private:
	std::string mFirstName;
	std::string mLastName;
	bool mHasTable;
public:
	TableTennisPlayer(const std::string & fn = "none", const std::string & ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return mHasTable; }
	void ResetTable(bool v) { mHasTable = v; }
};

// simple derived class
class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int mRating;
public:
	RatedPlayer(unsigned int r, const std::string & fn = "none", const std::string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & ttp);
	unsigned int Rating() const { return mRating; }
	void ResetRating(unsigned int r) { mRating = r; }
};