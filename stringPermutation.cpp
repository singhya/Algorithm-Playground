#include<iostream>
using namespace std;
bool isPermutation(string str1, string str2)
{
	int count[26];
	for(int i=0;i<26;i++)
	{
		count[i]=0;
	}
	if(str1.length()==str2.length())
	{
	for (int i=0;i<str1.length();i++)
	{
		if(!count[str1[i]-'a'])
		{
			count[str1[i]-'a']=1;
		}
		else
		{
			count[str1[i]-'a']++;
		}
	}
	for (int i=0;i<str2.length();i++)
	{
		if(!count[str2[i]-'a'])
		{
			return false;
		}
		else
		{
			count[str2[i]-'a']--;
		}
	}
	return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string str1 = "abcbdee";
	string str2 = "aecbedb";
	bool result = isPermutation(str1,str2);
	cout<<result; 
}
