#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>
using namespace std;
long long int max(long long int a, long long int b)
{
	return (a>b)?a:b;
}

int main() 
{
	//ifstream input_data;
	//input_data.open("input.txt");
	
	int N;
	cin>>N;
	long long int h[N];
	stack<long long int> s;
	int i=0;
	long long int max_ar = 0;
	long long int temp_ar = 0;
	while(N--)
	{
		cin>>h[i];
		//cout<<h[i]<<endl;
		if(s.empty() || h[s.top()]<=h[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			while(!s.empty() && h[s.top()]>h[i])
			{
				long long int top = s.top();
				s.pop();
				if(s.empty())
					temp_ar = i * h[top]; 
				else
					temp_ar = (i-s.top()-1)* h[top];				
				max_ar = max(temp_ar,max_ar);
				/*if(i<30)
				{
				cout<<i;
				cout<<" ";
				cout<<max_ar<<endl;
				}*/
			}
			s.push(i);
			i++;
		}	
			
	}
	while(!s.empty())
	{
		long long int top = s.top();
		s.pop();
		if(s.empty())
			temp_ar = i * h[top]; 
		else
			temp_ar = (i-top)* h[top];				
		max_ar = max(temp_ar,max_ar);
		{
				cout<<i;
				cout<<" ";
				cout<<max_ar<<endl;
		}
		//cout<<max_ar<<endl;
	}
	cout<<max_ar;
	return 0;
}
	
