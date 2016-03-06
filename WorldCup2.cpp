#include <iostream>
#include <stdio.h>
using namespace std;
void printArray(int* a, int N)
{
	for(int i = 0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		int a[N];
		int i = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d", &a[i]);;	
		}	
		int loops = 0;
		for(i=0;i<N;i++)
		{
			//printArray(a,N);
			if(a[i]!=-1)
			{
				int pointer_from = i;
				do
				{
					int pointing_to = a[pointer_from]-1;
					a[pointer_from] = -1;
					if(a[pointing_to] == -1)
					{
						loops++;
					}
					pointer_from = pointing_to;
				}while(a[pointer_from]!=-1);
			}
		}
		//cout<<loops<<endl;
		int total = 0;
		while(loops>1)
		{
			total += loops/2;
			loops = loops/2+loops%2;
		}
		cout<<total<<endl;
	}
	
	return 0;
}
