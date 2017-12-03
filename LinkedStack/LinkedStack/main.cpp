#include<iostream>
#include"LinkedStack.h"

using namespace std;

int main()
{
	LinkedStack<int> s;
	for (int i = 0; i < 5; i++)
	{
		s.push(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;


	return 0;
}