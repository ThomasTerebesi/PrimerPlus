#pragma once

class Plorg
{
private:
	const static unsigned short NAME_LIMIT = 20;
	char name[NAME_LIMIT];
	int contentmentIndex;
public:
	Plorg();
	Plorg(const char* name);
	void SetCI(int newContentmentIndex);
	void Report() const;
};