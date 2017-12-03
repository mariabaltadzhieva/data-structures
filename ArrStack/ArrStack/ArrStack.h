#ifndef _ARRSTACK_HEADER_
#define _ARRSTACK_HEADER_

template<class T>
class ArrStack
{
public:
	ArrStack() :arr(NULL), tos(0), capacity(0){}
	ArrStack(const ArrStack& other)
	{
		copy(other);
	}
	ArrStack& operator=(const ArrStack& other)
	{
		if (this != &other)
		{
			delete[] arr;
			copy(other);
		}
		return *this;
	}
	~ArrStack()
	{
		delete[] arr;
	}


	void push(const T& elem)
	{
		checkSize();
		arr[tos++] = elem;
	}
	void pop()
	{
		if (!isEmpty())
		{
			tos--;
		}
		else
		{
			throw "Stack is empty";
		}
	}
	const T& top()const
	{
		if (!isEmpty())
		{
			return arr[tos-1];
		}
		else
		{
			throw "Stack is empty";
		}
	}

private:
	bool isEmpty()const
	{
		return tos == 0;
	}
	void checkSize()
	{
		if (tos == capacity)
		{
			resize(capacity ? capacity * 2 : 2);
		}
	}
	void copy(const ArrStack& other)
	{
		arr = new T[other.tos];
		for (int i = 0; i < other.tos; i++)
		{
			arr[i] = other.arr[i];
		}
		tos = other.tos;
		capacity = other.capacity;
	}
	void resize(int newCapacity)
	{
		T* buff = new T[newCapacity];
		for (int i = 0; i < tos; i++)
		{
			buff[i] = arr[i];
		}
		delete[] arr;
		arr = buff;
		capacity = newCapacity;
	}

private:
	T* arr;
	int tos;
	int capacity;

};
#endif