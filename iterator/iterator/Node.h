#pragma once

template<class T>
class Node
{
public:
	Node(const T& data, Node<T>*link) :data(data), link(link){}
	Node* getLink()const
	{
		return link;
	}

public:
	T data;
	Node<T>* link;
};