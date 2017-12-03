#include<iostream>
#include"ArrQueue.h"

using namespace std;

int main()
{
	ArrQueue<int> q;
	for (int i = 0; i < 5; i++)
	{
		q.enqueue(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << q.first();
		q.dequeue();
	}
	cout << endl;

	return 0;
}