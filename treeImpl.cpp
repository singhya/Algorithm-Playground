#include <iostream>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
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
			cout<<n->data->data<<" ";
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
class Tree
{
	public:
	TreeNode* root;
	Tree()
	{
		root = NULL;
	}
	Tree(int d)
	{
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->data = d;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
	}
};
TreeNode* leftInsert(TreeNode *n, int d)
{
	TreeNode *new_node;
	new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = d;
	new_node->left = NULL;
	new_node->right = NULL;
	n->left = new_node;
	return new_node;
}

TreeNode* rightInsert(TreeNode *n, int d)
{
	TreeNode *new_node;
	new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = d;
	new_node->left = NULL;
	new_node->right = NULL;
	n->right = new_node;
	return new_node;
}
DFS(TreeNode *n)
{
	cout<<n->data<< " ";
	if(n->left!=NULL)
	{
		DFS(n->left);
	}
	if(n->right!=NULL)
	{
		DFS(n->right);
	}
}
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
		cout<< popped_element->data->data<<" ";
	}
}
int main()
{
	Tree t(1);
	DFS(t.root);
	cout<<endl;
	BFS(t.root);
}
