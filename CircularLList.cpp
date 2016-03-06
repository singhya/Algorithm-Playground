#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
int lookStartingNode(Node* n)
{
	Node* first = n;
	Node* second = n;
	do{
		first=first->next;
		second=second->next->next;
	}while(first->data!=second->data);
	
	Node* iterator = n;
	while(iterator->data!=first->data)
	{
		iterator=iterator->next;
		first=first->next;
	}
	return iterator->data;
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
	Node* n = l.insert_last(8);
	Node* last = l.insert_last(9);
	l.display();
	last->next=n;
	cout << lookStartingNode(l.head);
}
