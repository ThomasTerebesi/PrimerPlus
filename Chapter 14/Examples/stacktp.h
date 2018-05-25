#pragma once

template <class Type>
class Stack
{
private:
	static const int MAX = 10;	// constant specific to class
	Type items[MAX];			// holds stack items
	int top;					// index for top stack item
public:
	Stack();
	bool IsEmpty();
	bool IsFull();
	bool Push(const Type & item);	// add item to stack
	bool Pop(Type & item);			// pop top into item
};

template<class Type>
inline Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
inline bool Stack<Type>::IsEmpty()
{
	return top == 0;
}

template<class Type>
inline bool Stack<Type>::IsFull()
{
	return top == MAX;
}

template<class Type>
inline bool Stack<Type>::Push(const Type & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
inline bool Stack<Type>::Pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
