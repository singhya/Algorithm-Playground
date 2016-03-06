#include <iostream>
using namespace std;
struct Node
{
	long int data;
	struct Node *next;
};
class List
{
	public:
		Node *head;
		int count = 0;
		//node* create_node(int);
		//void insert_begin(int);
		//void insert_pos(int,int);
		Node* insert_last(long int);
		//void delete_pos(int);
		void sort();
		//void search(int);
		//void update(int,int);
		void reverse(Node *n);
		void display();
		void checkIfNim(Node *n);
		void displayCount();
		List(long int d)
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = d;
			new_node->next = NULL;
			this->head = new_node;
		}
		List()
		{
			this->head = NULL;
		}
		
};
void List::checkIfNim(Node* n)
{
	long int temp = 0;
	List l;
	while(n!=NULL)
	{
		temp = temp ^ n->data;
		l.insert_last(n->data);
		n=n->next;
	}
	if(temp==0)
	{
		count++;
	}
	l.display();
}
void List::displayCount()
{
	cout<<count;
}
void List::display()
{
	Node *n;
	n = this->head;
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
Node* List::insert_last(long int d)
{
	Node *n;
	n = this->head;
	if(n==NULL)
	{
		Node* new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = d;
		new_node->next = NULL;
		this->head = new_node;
	}
	else
	{
	
		while(n->next!=NULL)
		{
			n = n->next;
		}
		Node* new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = d;
		new_node->next = NULL;
		n->next = new_node;
	}
}

int main()
{
	int N;
	long int data;
	cin>>N;
	List l;
	for(int i=0;i<N;i++)
	{
		scanf("%d", &data);
		l.insert_last(data);	
	}
	l.checkIfNim(l.head);
	l.displayCount();
	return 0;
}
