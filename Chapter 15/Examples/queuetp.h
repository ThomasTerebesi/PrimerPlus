#pragma once

template <class Item>
class QueueTP
{
private:
	static const short QUEUE_SIZE = 10;

	// Node is a nested class definition
	class Node
	{
	public: 
		Item item;
		Node * next;
		
		Node(const Item & i)
			: item(i), next(nullptr)
		{
		}
	};

	Node * front;
	Node * rear;
	int items;
	const int qSize;
	
	QueueTP(const QueueTP & q) : qSize(0) {}
	QueueTP & operator=(const QueueTP & q) { return *this; }

public:
	QueueTP(int qs = QUEUE_SIZE);
	~QueueTP();

	bool IsEmpty() const { return items == 0; }
	bool IsFull() const { return items == qSize; }
	int QueueCount() const { return items; }

	bool Enqueue(const Item & item);
	bool Dequeue(Item & item);
};


// QueueTP methods
template<class Item>
inline QueueTP<Item>::QueueTP(int qs)
	: qSize(qs), front(nullptr), rear(nullptr), items(0)
{
}

template<class Item>
inline QueueTP<Item>::~QueueTP()
{
	Node * temp;

	while (front != nullptr)		// while queue is not yet empty
	{
		temp = front;				// save address of front item
		front = front->next;		// reset pointer to next item
		delete temp;				// delete former front
	}
}

// Add item to queue
template<class Item>
inline bool QueueTP<Item>::Enqueue(const Item & item)
{
	if (IsFull())
		return false;

	Node * add = new Node(item);	// create node; on failure, new throws std::bad_alloc exception
	items++;

	if (front == 0)			// if queue is empty
		front = add;		// place item at front
	else
		rear->next = add;	// else place at rear
	
	rear = add;				// have rear point to new node

	return true;
}

// Place front item into item variable and remove from queue
template<class Item>
inline bool QueueTP<Item>::Dequeue(Item & item)
{
	if (front == nullptr)
		return false;

	item = front->item;		// set item to first item in queue
	items--;

	Node * temp = front;	// save location of first item

	front = front->next;	// reset front to next item
	delete temp;			// delete former first item

	if (items == 0)
		rear = 0;

	return true;
}
