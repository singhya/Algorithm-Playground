#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#include "YashLinkListImplementation.h"
void kthElementFromLast(Node *n,int k,int &counter)
{
	if(n->next!=NULL)
	{
		kthElementFromLast(n->next,k,counter);
		counter++;
	}
	else
	{
		counter++;
	}
	if(counter==k)
	{
		cout<<k;
		cout<<" element from last of list is : ";
		cout<<n->data;
	}
}
int main()
{
	List l(1);
	l.insert_last(2);
	l.insert_last(3);
	l.insert_last(4);
	l.insert_last(5);
	l.insert_last(6);
	l.insert_last(7);
	l.insert_last(8);
	l.display();
	int counter = 0;
	kthElementFromLast(l.head,8,counter);
}
