#pragma once

#include "2cd.h"

class Classic : public Cd
{
private:
	char * primaryWork;
public:
	Classic(const char * pw = "no primary work", const char * s1 = "no artist", const char * s2 = "no label", int n = 0, double x = 0.0);
	Classic(const Cd & d, const char * pw = "no primary work");
	Classic(const Classic & d);
	~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & d);
};