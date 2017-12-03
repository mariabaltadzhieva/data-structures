#ifndef _LINKEDQUEUE_HEADER_
#define _LINKEDQUEUE_HEADER_

template<class T>
class LinkedQueue
{
public:
	LinkedQueue() :head(NULL), tail(NULL){}
	LinkedQueue(const LinkedQueue& other)
	{
		copy(other);
	}
	LinkedQueue& operator=(const LinkedQueue& other)
	{
		if (this != &other)
		{
			copy(other);
		}
		return *this;
	}
	~LinkedQueue()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}


	bool isEmpty()const
	{
		return !head;
	}
	void enqueue(const T& elem)
	{
		Node*n = new Node(elem, NULL);
		if (tail == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->link = n;
			tail = n;
		}
	}
	void dequeue()
	{
		if (!isEmpty())
		{
			Node* n = head;
			head = head->link;
			delete n;
		}
		else
		{
			throw "Queue is empty";
		}
		
	}
	const T& first()const
	{
		if (!isEmpty())
		{
			return head->data;
		}
		else
		{
			throw "Queue is empty";
		}
	}

private:
	void copy(const LinkedQueue& other)
	{
		head = other.head;
		tail = other.tail;
	}

private:
	struct Node
	{
		T data;
		Node* link;

		Node(const T& data, Node* link) :data(data), link(link){}
	};
	
	Node* head;
	Node* tail;
};
#endif