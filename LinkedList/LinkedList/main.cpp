#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> l;
	for (int i = 0; i < 5; i++)
	{
		l.insertFront(i + 1);
	}
	cout << l;

	LinkedList<int> l2;
	for (int i = 0; i < 5; i++)
	{
		l2.insertEnd(i + 1);
	}
	cout << l2;

	l2.removeFront();
	cout << l2;

	return 0;
}