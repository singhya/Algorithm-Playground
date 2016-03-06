#include <iostream>
using namespace std;

int main()
{
	int a [6][6];
	int n = 6;
	int counter = 0;
	for( int i = 0; i<n ; i++)
		for (int j=0; j<n ; j++)
		{
			a[i][j] = counter++;
		}
	for( int i = 0; i<n ; i++)
	{
		for (int j=0; j<n ; j++)
		{
			cout << a[i][j] << " ";
		}
		cout<<endl;
	}
	for(int i = 0; i<n/2 ;i++)
	{
		for(int j=i; j<n-1-i; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[n-1-j][i];
			a[n-1-j][i] = a[n-1-i][n-1-j];
			a[n-1-i][n-1-j] = a[j][n-1-i];		
			a[j][n-1-i] = temp;
		}
	}
	cout<<endl;
	for( int i = 0; i<n ; i++)
	{
		for (int j=0; j<n ; j++)
		{
			cout << a[i][j] << " ";
		}
		cout<<endl;
	}
}
