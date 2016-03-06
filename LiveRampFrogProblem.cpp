#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int min(int *M,int j, int D)
{
	int min = M[j];
	for(int i = j-1;i>j-D;i--)
	{
		if(min>M[i])
		{
			min = M[i];
		}
	}
	return min;
}
int findSol(vector<int> &A, int X, int D)
{
	if(X<=D)
	{
		return 0;
	}
	int time[100001];
	for(int i=0;i<100000;i++)
	{
		time[i] = numeric_limits<int>::max();
	}
	int index = 0;
	for(vector<int>::iterator i = A.begin(); i!=A.end(); i++)
	{
		if(time[(*i)]>index)
		{
			time[(*i)] = index;
		}
		index++;
	}
	int M[100001];
	M[0] = 0;
	for(int i=1;i<=D;i++)
	{
		M[i] = time[i];
	}
	//cout<<M[9];
	for(int j=D+1;j<X;j++)
	{
		M[j] = min(M,j,D);
		cout<<M[9];
		if(M[j]<time[j])
		{
			M[j] =time[j];
		}
	}
	for(int i = 0;i<X;i++)
	{
		cout<<i;
		cout<<" : ";
		cout<<M[i];
		cout<<endl;
	}
	bool reach = false;
	M[X] = numeric_limits<int>::max();
	for(int i=X-1;i>=X-D;i--)
	{
		if(M[i]<M[X])
		{
			reach = true;
			M[X] = M[i];
		}
	}
	if(reach)
	{
		return M[X];
	}
	else
	{
		return -1;
	}
}
int main()
{
	std::vector<int> v {5, 9, 1, 1, 2, 10, 6, 1, 7, 4, 8, 1};
	int time = findSol(v,10,3);
	cout<<time;
	return 0;
}
