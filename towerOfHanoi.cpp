#include <iostream>
using namespace std;
#include "StackImpl.h"
void hanoi(int n, Stack &s1, Stack &s3, Stack &s2)
{
	if(n>1)
	hanoi(n-1,s1,s2,s3);
	Node* node = s1.pop();
	int p = node->data;
	s3.push(p); 
	//s1.display();
	//s2.display();
	//s3.display();
	//cout<<endl;
	if(n>1)
	hanoi(n-1,s2,s3,s1);
}
int main()
{
	Stack s1;
	Stack s2;
	Stack s3;
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);
	cout<<"Tower 1:";
	s1.display();
	cout<<"Tower 2:";
	s2.display();
	cout<<"Tower 3:";
	s3.display();
	cout<<endl;
	hanoi(5,s1,s3,s2);
	cout<<"Tower 1:";
	s1.display();
	cout<<"Tower 2:";
	s2.display();
	cout<<"Tower 3:";
	s3.display();
	cout<<endl;
}
