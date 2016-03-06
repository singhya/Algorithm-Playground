#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#include "YashLinkListImplementation.h"
void removeDuplicateUsingMap(List list)
{
	Node *n = list.head;
	unordered_map<int, int> map;
	map[n->data] = 1;
	while(n->next!=NULL)
	{
		if(map.find(n->next->data) != map.end())
		{
			n->next = n->next->next;
		}
		else
		{
			map[n->next->data] = 1;
			n=n->next;
		}
	}
}
void removeDuplicateWithoutExtraSpace(List list)
{
	Node *first = list.head;
	Node *second;
	while(first!=NULL && first->next!=NULL )
	{
		second = first->next;
		while(second!=NULL && second->data==first->data)
		{
			first->next=second->next;
			second = second->next;
		}
		first = first->next;
	}
}
int main()
{
	List l(1);
	l.insert_last(3);
	l.insert_last(3);
	l.insert_last(2);
	l.insert_last(3);
	l.insert_last(4);
	l.insert_last(3);
	l.insert_last(4);
	l.insert_last(3);
	List ul(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	ul.insert_last(8);
	List oe(1);
	cout<<"Original Link List : ";
	oe.display();
	//removeDuplicateUsingMap(l);
	//cout<<"List after deletion of duplicates : ";
	oe.sort();
	cout<<"List after sorting : ";
	oe.display();
	removeDuplicateWithoutExtraSpace(oe);
	cout<<"List after removing duplicates : ";
	oe.display();
}
