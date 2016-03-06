#include <iostream>
#include <vector>
using namespace std;
void findEuler(int N, vector<long long int> &a)
{
	if(N==1)
	{
		a[N-1] = 1;
		return;
	}
	else
	{
		findEuler(N-1, a);
		for(int i=N;i>=N/2;i--)
		{
			a[N-1] = a[N-1]+a[i-1];
		}
		
	}
}
void testCase(int N)
{
	vector<long long int> a(N);
	for(int i=0;i<N;i++)
	{
		a[i] = 0;
	}
	findEuler(N,a);
	long long int sum = 0;
	for(int i=N-1;i>=0;i--)
	{
		sum+=a[i];
		cout<<sum;
		cout<<" ";
	}
	cout<<endl;
}
int main()
{
	int N;
	/*for(int i=1;i<15;i++)
	{
		cout<<i;
		cout<<" : ";
		testCase(i);
	}*/
	testCase(1000);
	
}
