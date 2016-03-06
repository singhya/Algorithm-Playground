#include<iostream>
using namespace std;
void hanoi(char A,char B,char C,int n)
{
	if(n>0)
	{
		
	hanoi(A,C,B,n-1);
	cout<<"move disc ";
	cout<<A;
	cout<<" to ";
	cout<<C<<endl;
	hanoi(B,A,C,n-1);
    }
}
int main()
{
	hanoi('A','B','C',3);
	return 0;
}
