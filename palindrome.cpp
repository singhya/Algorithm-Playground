#include <iostream>
using namespace std;
#include "YashLinkListImplementation.h"
struct Result
{
	Node* itertor;
	bool result;
};
Result IsPalindrome(Node *n, Result r)
{
	if(n->next!=NULL)
	{
		Result res = IsPalindrome(n->next, r);
		if(res.itertor->data!=n->data)
		{
			res.itertor = res.itertor->next;
			res.result = res.result && false;
			return res;
		}
		else
		{
			res.itertor = res.itertor->next;
			res.result = res.result && true;
			return res;
		}
		
	}
	else
	{
		if(r.itertor->data!=n->data)
		{
			r.itertor=r.itertor->next;
			r.result = r.result && false;
			return r;
		}
		else
		{
			r.itertor=r.itertor->next;
			r.result = r.result && true;
			return r;
		}
		
	}
	
}
int main()
{
	List l(9);
	l.insert_last(2);
	l.insert_last(8);
	l.insert_last(8);
	l.insert_last(2);
	l.insert_last(1);
	l.display();
	Result res;
	res.itertor = l.head;
	res.result = true;
	Result check = IsPalindrome(l.head,res);
	cout<<check.result;
}
