#include <iostream>
using namespace std;

int Max(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int Max(int a, int b, int c)
{
	if(a>=b &&a>=c)
	{
		return a;
	}
	else if(b>=a && b>=c)
	{
		return b;
	}
	else
	{
		return c;
	}
}
long long int Max(long long int a, long long int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int Min(int a,int b,int c)
{
	if(a<=b && a<=c)
	{
		return a;
	}
	else if(b<=a && b<=c)
	{
		return b;
	}
	else
	return c;
}
int Min (int a, int b)
{
	if(a<b)
	return a;
	else 
	return b;
}
long long int iteratorFunction(long long int n, int a, int b, int c)
{
	//cout<<n<<endl;
	if (n==0)
	return 0;
	if (n==1)
	return 0;
	if (n==2)
	return Max(a,b);
	else if(n==3)
	return Min(a+b,Max(a,b,c));
	
	int min = Min(a,b,c);
	int max = Max(a,b,c);
	int sum = a+b+c;
	int intermediate = sum - min - max;
	long long int a1;
	if(((n*(a*b*c))%((a*b+b*c+c*a)*min))>0)
		a1 = (n*(a*b*c))/((a*b+b*c+c*a)*min)+1;
	else
		a1 = (n*(a*b*c))/((a*b+b*c+c*a)*min);
	
	long long int a2;
	if(((n-a1)*(intermediate*max))%((intermediate+max)*intermediate)>0)
	a2 = ((n-a1)*(intermediate*max))/((intermediate+max)*intermediate)+1;
	else
	a2 = ((n-a1)*(intermediate*max))/((intermediate+max)*intermediate);
	
	cout<<n<<endl;
	cout<<a1<<" ";
	cout<<a2<<" ";
	cout<<n - a1- a2<<endl;
	long long int resultFromMin = iteratorFunction(a1, a, b, c) + min;
	//long long int resultFromMin = min;
	//cout<<"Finished iterating over Min"<<endl;
	
	long long int resultFromIntermediate = iteratorFunction(a2, a, b, c) + intermediate;
	resultFromMin =  Max(resultFromMin, resultFromIntermediate);
	
	//if(a2<=9)
	//{
		long long int resultFromMax = iteratorFunction(n-a1-a2, a, b, c) + max;
		resultFromMin = Max(resultFromMin, resultFromMax);
	//}//cout<<"Finished iterating over Max"<<endl;
	//if(n-a1-a2<=9)
	//{
		//}
	return resultFromMin;
}
int main()
{
	/*int T;
	long long int n[10000];
	int a[10000][3];
	cin>>T;
	int A;
	int B;
	int C;
	for(int i=0;i<T;i++)
	{
		scanf("%d", &n[i]);
		for(int j = 0;j<3;j++)
		scanf("%d", &a[i][j]);
	}
	for(int i=0;i<T;i++)
	{
		cout<<iteratorFunction(n[i],a[i][0],a[i][1],a[i][2]);
		cout<<endl;
	}*/
	//iteratorFunction(10,1,2,3);
	int a[1000000];
	int i = 0;
	int j = 1000;
	for(;i<=1000;i++)
	{
		a[i] = 0;
	}
	/*for(;j>=0;j--)
	{
		cout<<a[j]<<endl;
	}*/
	
	return 0;
}
