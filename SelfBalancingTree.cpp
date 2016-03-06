#include <iostream>
using namespace std;
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; 
int max(int a, int b)
{
	return (a>b)?a:b;
}
node* insertleft(node* a, int b, int c)
{
	node* n = (node*)malloc(sizeof(node));
    n->val = b;
    n->left = NULL;
    n->right = NULL;
    a->left = n;
    a->ht = c;
    return n;
}

node* insertright(node* a, int b, int c)
{
	node* n = (node*)malloc(sizeof(node));
    n->val = b;
    n->left = NULL;
    n->right = NULL;
    a->right = n;
    a->ht = c;
    return n;
}
void Preorder(node *root) {
    if(root)
    {
        cout<<root->val;
        cout<<"|";
        cout<<root->ht;
		cout<<" ";
    }
    if(root->left)
    Preorder(root->left);
    if(root->right)
    Preorder(root->right);
}
int recalculateHeight(node* n)
{
	if(n->left == NULL && n->right == NULL)
	{
		n->ht = 0;
	}
	else if(n->left == NULL)
	{
		n->ht = recalculateHeight(n->right)+ 1;
	}
	else if(n->right == NULL)
	{
		n->ht = recalculateHeight(n->left) + 1;
	}	
	else
	{
		n->ht = max(recalculateHeight(n->left),recalculateHeight(n->right))+1;
	}
	return n->ht;	
}

node* leftleft(node* n)
{
    node*temp = n->left->right;
    n->left->right = n;
    node* r = n->left;
    n->left = temp;
    return r;
}
node* leftright(node* n)
{
    node*temp = n->left;
    n->left = n->left->right;
    node* t_temp = n->left->left;
    n->left->left = temp;
    n->left->left->right = t_temp;
    return leftleft(n);
}
node* rightright(node* n)
{
    node* temp = n->right->left;
    n->right->left = n;
    node* r = n->right;
    n->right = temp;
    return r;
}
node* rightleft(node* n)
{
    node* temp = n->right;
    n->right = n->right->left;
    node* t_temp = n->right->right;
    n->right->right = temp;
    n->right->right->left = t_temp;
    return rightright(n);
}
int BF(node* a)
{
	if(a->left == NULL && a->right==NULL)
		return 0;
	else if(a->left == NULL)
		return (0-a->right->ht);
	else if(a->right == NULL)
		return (a->left->ht-0);
	return (a->left->ht-a->right->ht);
}

node* Balance(node * root)
{
	Preorder(root);
	cout<<endl;
	if(BF(root)<-1)
    {
        if(BF(root->right)<0)
        {
           root = rightright(root);
        }
        else
       	{
       		root = rightleft(root);
       	}
    }
	else if(BF(root)>1)
    {
    	if(BF(root->left)<0)
        {
          	root = leftright(root);
		}      
        else
        {
           	root = leftleft(root);
        } 
	}
	cout<<"check"<<endl;
	Preorder(root);
	cout<<endl;
    return root;
}
void Inorder(node *root) {
    if(root->left)
        Inorder(root->left);
    if(root)
    {
        cout<<root->val;
        cout<<" ";
        
    }
    if(root->right)
        Inorder(root->right);
}
node * insert(node * root,int val)
{
   if(!root)
   {    
       node*n ;
       n = (node*)malloc(sizeof(node));
       n->val = val;
       n->left = NULL;
       n->right = NULL;
       n->ht = 0;
       return n;
   }
   //Preorder(root);
   if(val>root->val)
       if(root->right)
        {
       	    root->right = insert(root->right,val);  
			//Preorder(root->right);
			//cout<<endl;
        
		}
        else
        {
           node*n ;
           n = (node*)malloc(sizeof(node));
           n->val = val;
           n->left = NULL;
           n->right = NULL;
           root->right = n;
        }
   else
        if(root->left)
        { 
           root->left = insert(root->left,val);
        }
        else
        {
           node*n ;
           n = (node*)malloc(sizeof(node));
           n->val = val;
           n->left = NULL;
           n->right = NULL;
           root->left = n;
        }
    recalculateHeight(root);
	root = Balance(root);
    recalculateHeight(root);
    //Preorder(root);
    //cout<<endl;
    //Inorder(root);
    //cout<<endl;
    return root;
}
int main()
{
	node* root = insert(NULL,3);
	node* a = insertleft(root,2,1);
	node* b = insertright(root,4,2);
	node* c = insertright(b,5,1);
	node* d = insert(root,6);
	/*root = insert(root,10);
	root = insert(root,25);
	root = insert(root,7);
	root = insert(root,14);
	root = insert(root,23);
	root = insert(root,26);
	root = insert(root,12);
	root = insert(root,16);
	root = insert(root,30);
	root = insert(root,19);*/
	Preorder(root);
	//cout<<endl;
	//Inorder(root);
	return 0;
}
