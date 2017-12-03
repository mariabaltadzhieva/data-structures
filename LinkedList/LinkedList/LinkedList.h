#pragma once
#include<iostream>

template<class T>
class LinkedList
{
public:
	LinkedList() :head(NULL), tail(NULL){}
	LinkedList(const LinkedList& other)
	{
		copy(other);
	}
	LinkedList& operator=(const LinkedList& other)
	{
		if (this != &other)
		{
			copy(other);
		}
		return *this;
	}
	~LinkedList()
	{
		Node* n ;
		while (head != NULL)
		{
			n = head;
			head = head->link;
			delete n;
		}
	}


	void insertFront(const T& data)
	{
		Node* n = new Node(data, head);
		head = n;
		if (tail == NULL)
		{
			tail = n;
		}
	}
	void insertEnd(const T& data)
	{
		Node* n = new Node(data, NULL);
		if (head == NULL)
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
	void removeFront()
	{
		if (head == NULL)
		{
			throw "Linked list is empty";
		}
		Node* n = head;
		head = head->link;
		delete n;
	}

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l)
	{
		Node* ptr = l.head;
		while (ptr != NULL)
		{
			os << ptr->data<<" ";
			ptr = ptr->link;
		}
		os << std::endl;
		return os;
	}

private:
	void copy(const LinkedList& other)
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