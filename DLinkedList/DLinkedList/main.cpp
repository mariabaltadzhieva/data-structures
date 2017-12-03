#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main()
{
	DLinkedList<int> l;
	for (int i = 0; i < 5; i++)
	{
		l.insert(i + 1);
	}
	cout << l;
	l.remove();
	cout << l;

	return 0;
}