#include<iostream>
using namespace std;

string replaceSpaces(string str)
{
	int start = str.length()-1;
	int toBeReplaced = start;
	for(int j=start;j>=0;j--)
	{
		if(str[j]!=' ')
		{
			toBeReplaced = j;
			break;
		}
	}
	if(toBeReplaced == start)
	{
		return str;
	}
	for( int i=toBeReplaced; i>=0;i--)
	{
		if(str[i]!=' ')
		{
			str[start--] = str[i];
		}
		if(str[i]==' ')
		{
			str[start--] = '0';
			str[start--] = '2';
			str[start--] = '%';
		}
	}
	return str;
}

int main()
{
	string str = "Mr John Smith    ";
	cout << replaceSpaces(str);
}
