#include<iostream>
#include<string>
using namespace std;
bool check_palindrom(string s)
{
	for(int i=0;i<s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-1-i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string s,r;
	s="aacecaaa";
	for(int i=s.length()-1;i>=0;i--)
	{
		r+=s[i];
	}
	string longest_palindrom = s+r;
	int prefix[longest_palindrom.size()];
	prefix[0] = 0;
	int j=0;
	/*for(int i=0;i<longest_palindrom.size()/2;i++)
	{
		prefix[i] = 0;
	}*/
	for(int i=1;i<longest_palindrom.size()/2;i++)
    {
    	if(longest_palindrom[i]==longest_palindrom[j])
    	{
		    prefix[i]=++j;
    	}
        else
        {
        	while(j>0 && longest_palindrom[i]!=longest_palindrom[j])
        	{
        		j=prefix[j-1];
			}
        	if(longest_palindrom[i]==longest_palindrom[j])
        	{
        		prefix[i]=++j;
    	    }
			else
			{
				prefix[i]=0;
    	        j=0;
			}
		}
		cout<<"i : ";
		cout<<i;
		cout<<", j : ";
		cout<<j;
		cout<<", prefix : ";
		cout<<prefix[i];
		cout<<endl;
	}
	j=0;
	for(int i=longest_palindrom.size()/2;i<longest_palindrom.size();i++)
    {
    	if(longest_palindrom[i]==longest_palindrom[j])
    	{
		    prefix[i]=++j;
    	}
        else
        {
        	while(j>0 && longest_palindrom[i]!=longest_palindrom[j])
        	{
        		j=prefix[j-1];
			}
        	if(longest_palindrom[i]==longest_palindrom[j])
        	{
        		prefix[i]=++j;
    	    }
			else
			{
				prefix[i]=0;
    	        j=0;
			}
		}
		cout<<"i : ";
		cout<<i;
		cout<<", j : ";
		cout<<j;
		cout<<", prefix : ";
		cout<<prefix[i];
		cout<<endl;
	}
	cout<<longest_palindrom<<endl;
	for(int i=0;i<longest_palindrom.size();i++)
	{
		cout<<prefix[i];
		cout<<" ";
	}
	cout<<endl;
	cout<<r.substr(0,r.length()-prefix[longest_palindrom.size()-1])+s;
	return 0;
}
