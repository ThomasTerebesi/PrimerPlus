#pragma once

#include <string>

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