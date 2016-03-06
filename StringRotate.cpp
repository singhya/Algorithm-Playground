#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2)
{
	int index = s1.find(s2);
	if(index>=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string s1="waterbottle";
	string s2 ="erbottlewatr";
	if(s1.length()==s2.length())
	{
		s1+=s1;
		if(isSubstring(s1,s2))
		{
			cout<<"Rotation";
		}
		else
		{
			cout<<"Not a rotation";
		}
	}
	else
	{
		cout<<"Not a rotation";
	}

}
