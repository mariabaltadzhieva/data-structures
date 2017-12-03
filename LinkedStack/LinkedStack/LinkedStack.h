#ifndef _LINKEDSTACK_HEADER_
#define _LINKEDSTACK_HEADER_

template<class T>
class LinkedStack
{
public:
	LinkedStack() :tos(NULL){}
	LinkedStack(const T& other)
	{
		tos = other.tos;
	}
	LinkedStack& operator=(const T& other)
	{
		tos = other.tos;
	}
	~LinkedStack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}


	bool isEmpty()const
	{
		return !tos;
	}
	void push(const T& elem)
	{
		Node*n = new Node(elem, tos);
		tos = n;
	}
	void pop()
	{
		Node* n = tos;
		tos = tos->link;
		delete n;
	}
	const T& top()const
	{
		return tos->data;
	}
	

private:
	struct Node
	{
		T data;
		Node* link;

		Node(const T& data, Node* link) :data(data), link(link){}
	};

	Node* tos;
};
#endif;