#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	char animal_type;
};
class AnimalBasicQueue {
	public:
		Node *first;
		Node *last;
		void enqueue(int d, char c)
		{
			if(last==NULL)
			{
				Node *new_node;
				new_node = (Node*)malloc(sizeof(Node));
				new_node->data = d;
				new_node->animal_type = c;
				new_node->next = NULL;
				first = new_node;
				last = new_node;
			}
			else
			{
				Node *new_node;
				new_node = (Node*)malloc(sizeof(Node));
				new_node->data = d;
				new_node->animal_type = c;
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
				cout<<n->data<<":";
				cout<<n->animal_type<<" ";
				n=n->next;
			}
			cout<<endl;
		}
		AnimalBasicQueue()
		{
			first = NULL;
			last = NULL;
		}
};
class AnimalQueue
{
	public:
	AnimalBasicQueue *common;
	AnimalBasicQueue *dogs;
	AnimalBasicQueue *cats;
	void enqueue(int d, char c)
	{
		common->enqueue(d,c);
	}
	Node* dequeue()
	{
		if(common->first!=NULL || cats->first!=NULL || dogs->first!=NULL)
		{
			if(cats->first==NULL && dogs->first==NULL)
			{
				Node * node_to_return = common->first;	
				common->first = common->first->next;
				return node_to_return;
			}
			else if(cats->first!=NULL)
			{
				Node * node_to_return = cats->first;	
				cats->first = cats->first->next;
				return node_to_return;
			}
			else
			{
				Node * node_to_return = dogs->first;	
				dogs->first = dogs->first->next;
				return node_to_return;
			}
		}
		else
		{
			return NULL;
		}
	}
	Node* dogDequeue()
	{
		if(dogs->first!=NULL)
		{
			Node * node_to_return = dogs->first;	
			dogs->first = dogs->first->next;
			return node_to_return;
		}
		else
		{
			Node* node_to_return = common->dequeue();
			while(node_to_return!=NULL)
			{
				if(node_to_return->animal_type=='D')
					break;
				else if(node_to_return->animal_type=='C')
				{
					cats->enqueue(node_to_return->data,'C');
					node_to_return = common->dequeue();
				}
			}
			return node_to_return;
		}
	}
	Node* catDequeue()
	{
		if(cats->first!=NULL)
		{
			Node * node_to_return = cats->first;	
			cats->first = cats->first->next;
			return node_to_return;
		}
		else
		{
			Node* node_to_return = common->dequeue();
			while(node_to_return!=NULL)
			{
				if(node_to_return->animal_type=='C')
					break;
				else if(node_to_return->animal_type=='D')
				{
					dogs->enqueue(node_to_return->data,'D');
					node_to_return = common->dequeue();
			}
			}
			return node_to_return;
		}
	}
	void display()
	{
		cout<<"Common : ";
		common->display();
		cout<<"Dogs : ";
		dogs->display();
		cout<<"Cats : ";
		cats->display();
	}
	AnimalQueue()
	{
		common = new AnimalBasicQueue();
		cats = new AnimalBasicQueue();
		dogs = new AnimalBasicQueue();
	}
};
int main()
{
	AnimalQueue animals;
	animals.enqueue(1,'C');
	animals.enqueue(2,'D');
	animals.enqueue(3,'C');
	animals.enqueue(4,'D');
	animals.enqueue(5,'C');
	animals.enqueue(6,'D');
	animals.enqueue(7,'C');
	animals.enqueue(8,'D');
	animals.display();
	Node * n1 = animals.catDequeue();
	n1 = animals.dogDequeue();
	n1 = animals.dogDequeue();
	n1 = animals.dogDequeue();
	n1 = animals.dequeue();
	cout<<n1->data;
	cout<<":";
	cout<<n1->animal_type;
	cout<<endl;
	animals.display();
	//AnimalQueue cats;
	//AnimalQueue dogs;
}
