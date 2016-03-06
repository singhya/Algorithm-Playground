struct Node
{
	int data;
	struct Node *next;
};
class List
{
	public:
		Node *head;
		//node* create_node(int);
		//void insert_begin(int);
		//void insert_pos(int,int);
		Node* insert_last(int);
		//void delete_pos(int);
		void sort();
		//void search(int);
		//void update(int,int);
		void reverse(Node *n);
		void display();
		List(int d)
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
Node* List::insert_last(int d)
{
	Node *n;
	n = this->head;
	while(n->next!=NULL)
	{
		n = n->next;
	}
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = d;
	new_node->next = NULL;
	n->next = new_node;
	return new_node;
}
void List::reverse(Node *n)
{
	if(n->next!=NULL)
	{
		reverse(n->next);
		n->next->next =n;
		n->next = NULL;
	}
	else
	{
		this->head = n;
	}
}
void List::sort()
{
	Node *first;
	Node *second;
	first = this->head;
	while(first->next!=NULL)
	{
		second = first->next;
		Node * smallest_in_this_run_pointer;
		smallest_in_this_run_pointer = first;
		while(second!=NULL)
		{
			if(second->data<=smallest_in_this_run_pointer->data)
			{
				smallest_in_this_run_pointer = second; 
			}
			second = second->next;
		}
		if(first->data!=smallest_in_this_run_pointer->data)
		{
			int temp = first->data;
			first->data = smallest_in_this_run_pointer->data;
			smallest_in_this_run_pointer->data = temp;
		}
		first = first->next;
	}
}
