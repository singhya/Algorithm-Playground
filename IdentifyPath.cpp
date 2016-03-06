#include "BasicBTreeOPerations.h"
findPath(TreeNode *n, Queue q, int sum, int currentSum)
{
	q.enqueue(n);
	currentSum += n->value; 
	if(sum==currentSum)
	{
		q.display();
	}
	if(n->left!=NULL)
		findPath(n->left, q, sum, currentSum);
	if(n->right!=NULL)
		findPath(n->right, q, sum, currentSum);
}
findPathForSum(TreeNode *node, int sum)
{
	TreeNode* iterator = node;
	if(iterator!=NULL)
	{
		Queue q;
		findPath(iterator,q,sum,0);
		findPathForSum(iterator->left, sum);
		findPathForSum(iterator->right, sum);
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
	t.insertLeft(12,-9);
	t.insertLeft(-9,-3);
	t.insertLeft(23,19);
	t.insertLeft(19,8);
	t.insertLeft(72,54);
	t.insertRight(72,76);
	t.insertRight(54,67);
	t.insertRight(67,10);
	t.insertRight(10,-10);
	BFS(t.root);
	findPathForSum(t.root,67);
	cout<<endl;
} 
