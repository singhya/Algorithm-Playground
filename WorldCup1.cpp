#include <iostream>
using namespace std;
int main()
{
	int a[10];
	int largest = 0;
	int input;
	for(int i=0;i<10;i++)
	{
		cin>>input;
		if(input>largest)
		{
			a[i] = largest;
			largest = input;
			a[0] = largest;
		}
		else
		{
			a[i] = input;
		}
	}
	cout<<endl;
	for(int i=1;i<=4;i++)
	{
		largest = i;
		for (int j=i+1;j<10;j++)
		{
			if(a[largest]<a[j])
			{
				largest = j;
			}
		}
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
	}
	cout<<a[0] + a[2] + a[4];
	return 0;
}
