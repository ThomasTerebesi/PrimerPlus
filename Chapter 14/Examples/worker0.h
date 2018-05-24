#pragma once

#include <string>

class Worker	// abstract base class
{
private:
	std::string fullName;
	long id;
public:
	Worker() : fullName("Nobody"), id(0L) {}
	Worker(const std::string & s, long n) : fullName(s), id(n) {}
	virtual ~Worker() = 0;	// pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:
	int panache;
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
	Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer : public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { vTypes = 7 };
private:
	static const char * pv[vTypes];	// string equivalents of voice types
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};