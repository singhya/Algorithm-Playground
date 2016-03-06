#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
Node* sum_logic(int n1, int n2, int &carry)
{
	int sum_digit = (n1+n2+carry)%10;
	carry = (n1+n2+carry)/10;
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = sum_digit;
	new_node->next = NULL;
	return new_node;
}
List sum(List l1, List l2)
{
	Node* n1 = l1.head;
	Node* n2 = l2.head;
	Node* sum_list_node;
	List l;
	int carry = 0;
	if(n1==NULL)
	{
		l=l1;
		return l;
	}
	if(n2==NULL)
	{
		l=l2;
		return l;
	}
	while(n1!=NULL && n2!=NULL)
	{
		if(l.head==NULL)
		{
			l.head = sum_logic(n1->data,n2->data,carry);
			sum_list_node = l.head;
		}
		else
		{
			sum_list_node->next = sum_logic(n1->data,n2->data,carry);
			sum_list_node = sum_list_node->next;
		}
		n1=n1->next;
		n2=n2->next;
	}
	while(n1!=NULL)
	{
		sum_list_node->next = sum_logic(n1->data,0,carry);
		sum_list_node = sum_list_node->next;
		n1=n1->next;
	}
	while(n2!=NULL)
	{
		sum_list_node->next = sum_logic(0,n2->data,carry);
		sum_list_node = sum_list_node->next;
		n2=n2->next;
	}
	if(carry>0)
	{
		Node* new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = carry;
		new_node->next = NULL;
		sum_list_node->next = new_node;
	}
	return l;
}
int main()
{
	List l1(9);
	l1.insert_last(2);
	l1.insert_last(8);
	l1.insert_last(5);
	l1.insert_last(4);
	List l2(8);
	
	l2.insert_last(6);
	l2.insert_last(3);
	l2.insert_last(7);
	l1.display();
	l2.display();
	l1.reverse(l1.head);
	l2.reverse(l2.head);
	//l1.display();
	//l2.display();
	List l = sum(l1,l2);
	//l.display();
	l.reverse(l.head);
	l.display();
}
