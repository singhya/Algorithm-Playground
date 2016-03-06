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
	Stack()
	{
		top = NULL;
	}
};
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
}
