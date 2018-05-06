#pragma once

const unsigned short NAME_LENGTH = 32;

struct Customer
{
	char fullname[NAME_LENGTH];
	double payment;
};

typedef Customer Item; // to reuse the stack class from before

class Stack
{
private:
	const static short MAX = 10;
	Item * items = new Item[MAX];
	short top;
public:
	Stack();
	~Stack();
	bool isempty() const;
	bool isfull() const;

	bool push(const Item & item);
	bool pop(Item & item);
};