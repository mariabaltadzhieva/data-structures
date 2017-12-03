#ifndef _ARRQUEUE_HEADER_
#define _ARRQUEUE_HEADER_

template<class T>
class ArrQueue
{
public:
	ArrQueue() :arr(NULL), capacity(0), begin(0), end(0){}
	ArrQueue(const T& other)
	{
		copy(other);
	}
	ArrQueue& operator=(const ArrQueue& other)
	{
		if (this != &other)
		{
			delete[] arr;
			copy(other);
		}
		return *this;
	}
	~ArrQueue()
	{
		delete[] arr;
	}


	void enqueue(const T& elem)
	{
		if (isFull())
		{
			resize(capacity ? capacity * 2 :2);
		}
		arr[end] = elem;
		end = (end + 1) % capacity;
	}
	void dequeue()
	{
		T elem = first();
		begin = (begin + 1) % capacity;
	}

	const T& first()const
	{
		if (isEmpty())
		{
			throw "Queue is empty";
		}
		return arr[begin];
	}

	bool isEmpty()const
	{
		return begin == end;
	}
	bool isFull()const
	{
		return (capacity == 0) || ((end + 1) % capacity) == begin;
	}


private:
	void copy(const ArrQueue& other)
	{
		arr = new T[other.capacity];
		for (int i = 0; i < other.capacity; i++)
		{
			arr[i] = other.arr[i];
		}
		capacity = other.capacity;
		begin = other.begin;
		end = other.end;
	}
	void resize(int newCapacity)
	{
		T* buff = new T[newCapacity];
		for (int i = 0; i < capacity; i++)
		{
			buff[i] = arr[(begin + i) % capacity];
		}
		delete[] arr;
		arr = buff;
		capacity = newCapacity;
	}

private:
	T* arr;
	int capacity;

	size_t begin;
	size_t end;

};
#endif