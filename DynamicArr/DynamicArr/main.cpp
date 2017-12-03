#include <iostream>
#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr<int> arr;
	for (int i = 0; i < 5; i++)
	{
		arr.add(i+1);
	}
	cout << arr;
	
	cout << arr.find(2)<<endl;
	
	arr.remove(2);
	cout << arr;
	
	arr.insert(1, 9);
	cout << arr;


	return 0;
}