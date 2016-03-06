#include<iostream>
using namespace std;

void reverse(char* str)
{
	char* end = str;
	while(*end)
	{
		++end;
	}
	end--;
	while(end>str)
	{
		char temp = *end;
		*end = *str;
		end--;
		*str = temp;
		str++;
	}
}

int main()
{
	char str[] = {'Y','a','s','h','\0'};
	reverse (str);
	cout << str;	
}
