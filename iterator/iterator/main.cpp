#include<iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> l;
	for (int i = 0; i < 5; i++)
	{
		l.insertFront(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << l.first();
		l.removeFront();
	}
	cout << endl;

	int foo;
	for (int i = 0; i < 5; i++)
	{
		l.insertFront(i + 1);
	}
	/*for (int i = 0; i < 5; i++)
	{
		foo = l.getAt(i);
		cout << foo;
	}*/
	cout << endl;

	for (Iterator<int> it = l.getIterator(); !it.end(); it.moveNext())
	{
		foo = it.getCurr();
		cout << foo;
	}
	cout << endl;



	return 0;
}