#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
class Queue
{
	public:
	Node *first;
	Node *last;
	void enqueue(int d)
	{
		if(last==NULL)
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = d;
			new_node->next = NULL;
			first = new_node;
			last = new_node;
		}
		else
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = d;
			new_node->next = NULL;
			last->next = new_node;
			last = new_node;
		}
	}
	Node* dequeue()
	{
		if(first!=NULL)
		{
			Node * node_to_return = first;	
			first = first->next;
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
		n = first;
		while(n!=NULL)
		{
			cout<<n->data<<" ";
			n=n->next;
		}
		cout<<endl;
	}
	Queue()
	{
		first = NULL;
		last = NULL;
	}
};
int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
}
