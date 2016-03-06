struct Node
{
	int data;
	struct Node *next;
};
class List
{
	Node *head = NULL;
	public:
		//node* create_node(int);
		//void insert_begin(int);
		//void insert_pos(int,int);
		void insert_last(int);
		//void delete_pos(int);
		//void sort();
		//void search(int);
		//void update(int,int);
		//void reverse();
		void display();
		List(int d)
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = d;
			new_node->next = NULL;
			this->head = new_node;
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
void List::insert_last(int d)
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
}
