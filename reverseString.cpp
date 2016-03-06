#include<iostream>
#include<string>
using namespace std;

string reverse(string str)
{
	if(str[0]!='\0')
	{
		string s = reverse(str.substr(1)) + str[0];
		return s;
	}
	return str[0]+"";
}
int main()
{
	string str = "vnsl;gpoavnlkznvdosnbposbsl;bdodpb\0";
	string reversed = reverse(str);
	cout << reversed;
}
