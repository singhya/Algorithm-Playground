#include<iostream>
using namespace std;
struct TreeNode
{
	int value;
	int height;
	TreeNode* left;
	TreeNode* right;
};
struct Node
{
	TreeNode* data;
	Node* next;
};

class Queue
{
	public:
	Node *first;
	Node *last;
	void enqueue(TreeNode* n)
	{
		if(last==NULL)
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = n;
			new_node->next = NULL;
			first = new_node;
			last = new_node;
		}
		else
		{
			Node *new_node;
			new_node = (Node*)malloc(sizeof(Node));
			new_node->data = n;
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
			if(first==NULL)
			{
				last=NULL;
			}
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
			cout<<n->data->value<<" ";
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
class BTree
{
	public:
	TreeNode* root;
	TreeNode* searchNode(int searchValue, TreeNode* node)
	{
		TreeNode* returned_node = NULL;
		if(node==NULL)
		{
			return NULL;
		}
		else if(node->value==searchValue)
		{
			return node;
		}
		else
		{
			returned_node = searchNode(searchValue, node->left);
			if(returned_node==NULL)
			{
				returned_node = searchNode(searchValue, node->right);
			}
		}
		return returned_node;
	}
	insertRight(int searchValue, int data)
	{
		TreeNode* t = searchNode(searchValue, this->root);
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->height = 0;
		new_node->left = NULL;
		new_node->right = NULL;
		if(t!=NULL)
		t->right = new_node;
	}
	insertLeft(int searchValue, int data)
	{
		TreeNode* t = searchNode(searchValue, this->root);
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->height = 0;
		new_node->left = NULL;
		new_node->right = NULL;
		if(t!=NULL)
		t->left = new_node;
	}
	BTree(int data)
	{
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->height = 0;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
	}	
};
BFS(TreeNode* root)
{
	Queue q;
	q.enqueue(root);
	while(q.first!=NULL)
	{
		Node* popped_element = q.dequeue();
		if(popped_element->data->left!=NULL)
		{		
			q.enqueue(popped_element->data->left);
		}
		if(popped_element->data->right!=NULL)
		{
			q.enqueue(popped_element->data->right);
		}
		cout<< popped_element->data->value<<" ";
	}
}
int populateHeight(TreeNode *n, int &isBalanced)
{
	if(n==NULL)
	{
		return 0;
	}
	int leftHeight = populateHeight(n->left,isBalanced);
	int rightHeight = populateHeight(n->right,isBalanced);
	if(leftHeight-rightHeight>1 || leftHeight-rightHeight<-1)
	{
		isBalanced = 0;
	}
	int height = leftHeight;
	if(leftHeight<rightHeight)
	{
		height = rightHeight;
	}
	n->height=height;
	return height+1;
}

int main()
{
	BTree t(50);
	t.insertLeft(50,17);
	t.insertRight(50,72);
	t.insertLeft(17,12);
	t.insertRight(17,23);
	t.insertRight(12,14);
	t.insertLeft(12,9);
	t.insertLeft(23,19);
	t.insertLeft(72,54);
	t.insertRight(72,76);
	t.insertRight(54,67);
	BFS(t.root);
	int isBalanced=1;
	cout<<endl;
	populateHeight(t.root,isBalanced);
	cout<<isBalanced;
} 
