#include<iostream>
using namespace std;
struct ABState
{
	int state_of_a;
	int state_of_b;
};
struct TreeNode
{
	int value;
	ABState state;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
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
	Queue *searched_queue;
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
	void searchAll(int searchValue, TreeNode* node)
	{
		if(node==NULL)
		{
			return;
		}
		else if(node->value==searchValue)
		{
			searched_queue->enqueue(node);
		}
		searchAll(searchValue, node->left);
		searchAll(searchValue, node->right);
	}
	insertRight(int searchValue, int data)
	{
		TreeNode* t = searchNode(searchValue, this->root);
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = t;
		if(t!=NULL)
		t->right = new_node;
	}
	insertLeft(int searchValue, int data)
	{
		TreeNode* t = searchNode(searchValue, this->root);
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = t;
		if(t!=NULL)
		t->left = new_node;
	}
	TreeNode* commonAncestor(int a, int b)
	{
		TreeNode* node_of_a = searchNode(a,this->root);
		TreeNode* iterator = node_of_a;
		while(iterator->parent!=NULL)
		{
			if(iterator->parent->left != NULL &&
			iterator->parent->left->value == iterator->value)
			{
				iterator->parent->state.state_of_a = 1;
			}
			else 
			{
				iterator->parent->state.state_of_a = 2;
			}
			iterator = iterator->parent;			
		}
		TreeNode* node_of_b = searchNode(b,this->root);
		iterator = node_of_b;
		while(iterator->parent!=NULL)
		{
			if(iterator->parent->left != NULL && 
			iterator->parent->left->value == iterator->value)
			{
				iterator->parent->state.state_of_b = 1;
			}
			else 
			{
				iterator->parent->state.state_of_b = 2;
			}
			if((iterator->state.state_of_a==1 && iterator->state.state_of_b==2)||
			(iterator->state.state_of_a==2 && iterator->state.state_of_b==1))
			{			
				return iterator;			
			}
			iterator = iterator->parent;
		}
		return NULL;
	}
	areTreesIdentical(TreeNode* t1, TreeNode* t2)
	{
		bool flag = true;
		if(t1==NULL && t2==NULL)
		{
			return true;
		}
		else if((t1==NULL && t2!=NULL) ||
		   (t1!=NULL && t2==NULL) ||
		   (t1->value!=t2->value))
		{
			return false;
		} 
		else if(t1->value==t2->value)
		{
			flag = flag && 
				   areTreesIdentical(t1->left,t2->left) && 
				   areTreesIdentical(t1->right,t2->right);
		}
		return flag;
	}
	bool isSubtree(TreeNode* t)
	{
		searchAll(t->value,root);
		Node *node = searched_queue->dequeue();
		
		while(node)
		{
			if(areTreesIdentical(t,node->data))
			{
				return true;
			}
			node=searched_queue->dequeue();
		}
		return false;
	}
	BTree(int data)
	{
		TreeNode *new_node;
		new_node = (TreeNode*)malloc(sizeof(TreeNode));
		new_node->value = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = NULL;
		root = new_node;
		searched_queue = new Queue();
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
	int a = 14;
	int b = 23;
	TreeNode *ancestor = t.commonAncestor(a,b);
	cout<<endl;
	cout<<"Ancestor of ";
	cout<<a;
	cout<<" and ";
	cout<<b;
	cout<<": ";
	cout<<ancestor->value;
	BTree t2(72);
	t2.insertRight(72,76);
	t2.insertLeft(72,53);
	t2.insertRight(53,67);
	cout<<endl;
	//t.searchAll(t2.root->value,t.root);
	//t.searched_queue->display();
	cout<<"Is subtree : ";
	cout<<t.isSubtree(t2.root);
	cout<<endl;
} 
