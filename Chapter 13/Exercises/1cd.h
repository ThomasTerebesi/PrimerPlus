#pragma once

class Cd
{ // represents a CD disk
private:
	char performers[50];
	char label[20];
	int selections; // number of selections
	double playtime; // playing time in minutes
public:
	Cd(const char * s1 = "no artist", const char * s2 = "no label", int n = 0, double x = 0.0);
	Cd(const Cd & d);
	virtual ~Cd();
	virtual void Report() const; // reports all CD data
};