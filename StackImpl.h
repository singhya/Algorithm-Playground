#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
class Stack
{
	public:
	Node *top;
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
	}
	Node* pop()
	{
		if(top!=NULL)
		{
			Node * node_to_return = top;	
			top = top->next;
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
		cout<<endl;
	}
	void sort()
	{
		Stack* s = new Stack();
		while(this->top!=NULL)
		{
			int value = this->pop()->data;
			Node* top_value_in_sorted_stack = s->pop();
			int counter = 0;
			while(top_value_in_sorted_stack!=NULL && top_value_in_sorted_stack->data>value)
			{
				this->push(top_value_in_sorted_stack->data);
				counter++;
				top_value_in_sorted_stack = s->pop();
			}		
			if(top_value_in_sorted_stack!=NULL)
			{
				s->push(top_value_in_sorted_stack->data);
			}
			s->push(value);
			while(counter)
			{
				s->push(this->pop()->data);
				counter--;	
			}	
		}
		this->top = s->top;
	}
	Stack()
	{
		top = NULL;
	}
};
