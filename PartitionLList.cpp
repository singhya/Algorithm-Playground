#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#include "YashLinkListImplementation.h"
void partition(List l,int x)
{
	Node* prev, *after, *n;
	Node *break_point;
	n = l.head;
	if(n->data<x && n->next->data>=x)
	{
		prev = n;
		after = n->next;
		break_point = after;
	}
	else if (n->data<x && n->next->data<x)
	{
		prev = n->next;
		after = NULL;
	}
	else if(n->data>=x && n->next->data>=x)
	{
		prev = NULL;
		after = n->next;
		break_point = n;
	}
	Node *iterator = n->next->next;
	while(iterator!=NULL)
	{
		//cout<<iterator->data;
		
		if(iterator->data<x)
		{
			if(prev!=NULL)
			{
				prev->next = iterator;
			}	
			prev = iterator;
		}
		else
		{
			if(after==NULL)
			{
				after = iterator;
				break_point = after;
			}
			else
			{
				after->next = iterator;
				after = iterator;
			}	
		}
		iterator = iterator->next;
	}
	if(prev!=NULL && after!=NULL)
	{
		prev->next = break_point;
	}
}
int main()
{
	List l(1);
	l.insert_last(2);
	l.insert_last(8);
	l.insert_last(5);
	l.insert_last(4);
	l.insert_last(6);
	l.insert_last(3);
	l.insert_last(7);
	l.display();
	partition(l,0);
	l.display();
}
