#include <iostream>
#include <bitset>

using namespace std;

bool isUnique(string str)
{
	int a = 0;
	char t = 't';
	for (int i=0; i< str.length(); i++)
	{
		int temp = 1 << (str[i] - 'a');
		int k = a & temp;
		if((a & temp)>0)
		{
			return false;
		}
		a = a | temp;
		 
		
	}
	return true;
}
int main()
{
	string str;
	cin >> str;
	bool unique = isUnique(str);
	cout << unique;
}
