#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
class Stack
{
	public:
	Node *top;
	int item;
	void push(int d)
	{
		Node *new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = d;
		new_node->next = NULL;
			
		if(top!=NULL)
		{
			new_node->next = top;
		}
		top = new_node;
		item++;
	}
	Node* pop()
	{
		if(top!=NULL)
		{
			Node * node_to_return = top;	
			top = top->next;
			item--;
			return node_to_return;
		}
		else
		{
			return NULL;
		}
	}
	void display()
	{
		Node* n;
		n = top;
		while(n!=NULL)
		{
			cout<<n->data<<" ";
			n=n->next;
		}
	}
	Stack()
	{
		top = NULL;
		item = 0;
	}
};
struct PlatesSetNode
{
	Stack *s;
	PlatesSetNode *next;
};
class PlatesSetStack
{
	public:
	PlatesSetNode *n;
	int maxCapacity = 10;
	void push(int d)
	{
		if(n==NULL)
		{
			PlatesSetNode *new_node;
			new_node = (PlatesSetNode*)malloc(sizeof(PlatesSetNode));
			new_node->s = new Stack();
			new_node->s->push(d);
			new_node->next = NULL;
			n = new_node;
		}
		else if(n->s->item<maxCapacity)
		{
			n->s->push(d);
		}
		else
		{
			PlatesSetNode *new_node;
			new_node = (PlatesSetNode*)malloc(sizeof(PlatesSetNode));
			new_node->s = new Stack();
			new_node->s->push(d);
			new_node->next = n;
			n = new_node;
		}
		
	}
	int pop()
	{
		if(n==NULL)
		{
			return -1;
		}
		else
		{
			if(n->s->item==0)
			{
				n = n->next;
			}
			Node* returned_node = n->s->pop();
			return returned_node->data;
		}
	}
	void display()
	{
		PlatesSetNode* iterator=n;
		while(iterator!=NULL)
		{
			iterator->s->display();
			iterator = iterator->next; 
		}	
		cout<<endl;
	}
	PlatesSetStack()
	{
		n = NULL;
	}
	PlatesSetStack(int d)
	{
		n = NULL;
		maxCapacity = d;
	}
};
int main()
{
	PlatesSetStack s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(3);
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
}
