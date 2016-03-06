#include<iostream>
using namespace std;
void printMatrix(int a[][4],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int a [3][4] ={  
 					{0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
 					{4, 5, 0, 7} ,   /*  initializers for row indexed by 1 */
 					{8, 9, 10, 0}   /*  initializers for row indexed by 2 */
				  };
	int m = 3;
	int n = 4;
	printMatrix(a,m,n);
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				a[i][0] = 0;
				a[0][j] = 0;
			}
		}
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i][0] ==0 or a[0][j]==0)
			{
				a[i][j] = 0;
			}
		}
	}
	printMatrix(a,m,n);
}
