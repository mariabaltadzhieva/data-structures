#pragma once
#include"Node.h"

template<class T>
class Iterator
{
public:
	Iterator(Node<T> *pstart)
	{
		curr = pstart;
		start = pstart;
	}
	const T& getCurr()const
	{
		return curr->data;
	}
	void setCurr(const T& n)
	{
		curr->data = n;
	}
	void moveNext()
	{
		if (curr)
		{
			curr = curr->link;
		}
	}
	void rewind()
	{
		curr = start;
	}
	bool end()const
	{
		return curr == NULL;
	}
	/*const T& operator*()
	{
		return curr->data;
	}
	Iterator& operator++()
	{
		if (curr)
		{
			curr = curr->link;
		}
		return *this;
	}
	bool operator!()const
	{
		return !curr;
	}
	operator bool()const
	{
		return curr;
	}
	bool operator==(const Iterator& it)const
	{
		return curr == it.curr;
	}
	Iterator& operator++(const T&)
	{
		Iterator it(*this);
		++(*this);
		return it;
	}*/



private:
	Node<T>* curr;
	Node<T>* start;
};
