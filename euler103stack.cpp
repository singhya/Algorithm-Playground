#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<long long int> elements;
void findEuler(int N)
{
	vector<unsigned long long int> a(N);
	int i = 1;
	long long int modulo = 715827881;
	for(;i<=N;i++)
	{
		if(i==1)
		{
			elements.push(1);
			a[i-1]=1;
		}
		else if(i%2==0)
		{
			long long int num;
			if(((i/2)-2)>0)
			{
				num = ((elements.top()+elements.top())-a[(i/2)-2])%modulo;
			}
			else
			num = ((elements.top()+elements.top())-1)%modulo;
			elements.push(num);
			a[i-1] = num;
		}
		else
		{
			long long int num = ((elements.top()*2))%modulo;
			elements.push(num);
			a[i-1] = num;
		}
	}
	/*cout<<endl;
	for (int j=0;j<N;j++)
	{
		cout<<a[j];
		cout<<" ";
	}
	cout<<endl;*/
	long long int sum = 0;
	cout<<elements.top()%modulo;
	while (!elements.empty())
  	{
  		sum+=elements.top();
  		sum = sum%modulo;
     	//cout << sum << " ";
     	elements.pop();
  	}
}
int main()
{
	int N,a ;
	cin>>N;
	
	//cout<<N;
	//cin>>a;
	findEuler(N);
	for(int i=1;i<20;i++)
	{
		//findEuler(i);
		//cout<<endl;
	}
	return 0;
}
