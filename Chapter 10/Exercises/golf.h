#pragma once

const int LENGTH = 40;

class Golf
{
private:
	char fullName[LENGTH];
	int handicap;
public:
	Golf();
	Golf(const char* name, int hc);
	bool SetGolf();
	void Handicap(int hc);
	void ShowGolf();
	const char* GetName();
};