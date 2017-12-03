#pragma once
#include <iostream>

template <class T>
class DLinkedList
{
public:
	DLinkedList() :head(NULL), curr(NULL), tail(NULL){}
	DLinkedList(const DLinkedList& other)
	{
		head = other.head;
		curr = other.curr;
		tail = other.tail;
	}
	DLinkedList& operator=(const DLinkedList& other)
	{
		if (this != &other)
		{
			head = other.head;
			curr = other.curr;

			tail = other.tail;
		}
		return *this;
	}
	~DLinkedList()
	{
		Node*n;
		while (head != NULL)
		{
			n = head;
			head = head->next;
			delete n;
		}
	}

	void insert(const T& data)
	{
		Node* n = new Node(data, NULL,NULL);
		if (head == NULL)
		{
			head = n;
			curr = n;
			tail = n;
		}
		else
		{
			n->next = curr->next;
			n->prev = curr;
			curr->next = n;
			if (n->next)
			{
				n->next->prev = n;
			}
			else
			{
				tail = n;
			}
			curr = n;
		}
	}
	void remove()
	{
		Node* n = curr;
		if (curr->next && curr->prev)
		{
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			curr = curr->next;
		}
		else if (curr->next  && !curr->prev)
		{
			curr->next->prev = curr->prev;
			head = curr->next;
			curr = curr->next;
		}
		else if (!curr->next && curr->prev)
		{
			tail = curr->prev;
			curr->prev->next = curr->next;
			curr = curr->prev;
		}
		delete n;
	}

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const DLinkedList<T>& list)
	{
		Node* n = list.head;
		while (n != NULL)
		{
			os << n->data << " ";
			n = n->next;
		}
		os << std::endl;
		return os;
	}
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		
		Node(const T& data, Node* next, Node* prev) :data(data), next(next), prev(prev){}
	};
	Node* head;
	Node* tail;
	Node* curr;
};