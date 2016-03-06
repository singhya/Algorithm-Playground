#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> a;
	a.resize(0);
	for(vector<int>::iterator i = a.begin();i!=a.end();i++)
	{
		cout<<(*i)<<endl;
	}
	a.push_back(1);
	for(vector<int>::iterator i = a.begin();i!=a.end();i++)
	{
		cout<<(*i)<<endl;
	}
}
