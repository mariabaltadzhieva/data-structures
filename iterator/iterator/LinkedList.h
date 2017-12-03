#pragma once
#include "Node.h"
#include "Iterator.h"

template <class T>
class LinkedList
{
public:
	LinkedList() :head(NULL),tail(NULL),size(0){}
	~LinkedList()
	{
		Node<T> *n;
		while (head != NULL)
		{
			n = head;
			head = head->link;
			delete n;
		}
	}

	bool isEmpty()const
	{
		return !head;
	}
	int getCount()const
	{
		return size;
	}
	void insertFront(const T& data)
	{
		Node<T>* n = new Node<T>(data, head);
		head = n;
		if (isEmpty())
		{
			tail = n;
		}
		size++;
	}
	void insertEnd(const T& data)
	{
		Node<T>* n = new Node<T>(data, NULL);
		if (isEmpty())
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->link = n;
			tail = n;
		}
		size++;
	}
	void removeFront()
	{
		if (!isEmpty())
		{
			Node<T>* n = head;
			head = head->link;
			if (head == NULL)
			{
				tail = NULL;
			}
			size--;
			delete n;
		}
	}
	void removeEnd()
	{
		if (!isEmpty())
		{
			removeAt(size - 1);
		}
	}
	const T& first()const
	{
		if (!isEmpty())
		{
			return head->data;
		}
	}
	const T& end()const
	{
		if (!isEmpty())
		{
			return tail->data;
		}
	}
	
	void insertAfter(int index, const T& data)
	{
		Node<T> *n = findNode(index);
		if (n->link)
		{
			Node<T> *newNode = new Node<T>(data, n->link);
			n->link = newNode;
		}
		if (n == tail)
		{
			tail = newNode;
		}
		size++;
	}
	void insertBefore(int index, const T& data)
	{
		if (index == 0)
		{
			insertFront(data);
		}
		else
		{
			insertAfter(index - 1, data);
		}
		size++;
	}
	void removeAt(int index)
	{
		if (index == 0)
		{
			removeFront();
		}
		else
		{
			Node<T> *n = findNode(index - 1);
			Node<T> *newNode = n->link;
			if (index == size - 1)
			{
				tail = n;
			}
			n->link = newNode->link;
			delete newNode;
			size--;
		}
	}
	const T& getAt(int index)const
	{
		Node<T> *n = findNode(index);
		return n->data;
	}
	void setAt(int index, const T& data)
	{
		Node<T> *n = findNode(index);
		if (n != NULL)
		{
			n->data = data;
		}
	}
	Node<T>* findNode(int index)const
	{
		if (index < 0 || index >= size)
		{
			return NULL;
		}
		else
		{
			Node<T> *n = head;
			for (int i = 0; i < index; i++)
			{
				n = n->link;
			}
			return n;
		}
	}
	Node<T>* findeNode(Node<T>* p)const
	{
		Node<T> *curr = head;
		while (curr&&curr->link != p)
		{
			curr = curr->link;
		}
	}
	Iterator<T> getIterator()const
	{
		return Iterator<T>(head);
	}


	/*Iterator getFirst()
	{
		return Iterator(head, this);
	}
	void insertAfter(Iterator& it, const T& x)
	{
		if (!it)
		{
			insertLast(x);
		}
		else
		{
			it.curr->link = new Node(x, it.curr->link);
			if ((it.curr)==tail)
			{
				tail = tail->link;
			}
		}
	}
	void removeAfter(Iterator& it)
	{
		if (!it || !it->link)
		{
			return;
		}
		Node* n = it->link;
		it->link = n->link;
		if (n == tail)
		{
			tail = n;
		}
		delete n;
	}
	void removeAt(Iterator& it)
	{
		if (it.curr = head)
		{

		}
	}*/
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};