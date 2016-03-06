#include<iostream>
#include <stack> 
using namespace std;
stack<long long int> elements;
struct Node
{
	long long int value;
	Node* next;
	Node* prev;
};
class List
{
	public:
	Node* head;
	Node* middle;
	List()
	{
		head = NULL;
		//(Node*)malloc(sizeof(Node));
		//head = 
	}
	void display()
	{
		Node* iterator = head;
		while(iterator)
		{
			cout<<iterator->value%715827881;
			cout<<" ";
			iterator = iterator->next;
		}
	}
	void findEuler(long long int N)
	{
		if(N==1)
		{
			Node* new_node = (Node*)malloc(sizeof(Node));
			new_node->value = 1;
			new_node->next = NULL;
			new_node->prev = NULL;
			middle = new_node;
			head = new_node;
			elements.push(new_node->value);
			return;
		}
		else
		{
			findEuler(N-1);
			Node* new_node = (Node*)malloc(sizeof(Node));
			new_node->value = middle->value;
			new_node->next = head;
			new_node->prev = NULL;
			head->prev = new_node;
			head = new_node;
			elements.push(new_node->value);
			if(N%2!=0)
			{
				middle = middle->prev;
			}
			Node* iterator = head;
			long long int value = head->value;
			iterator = iterator->next;
			while(iterator)
			{
				iterator->value = iterator->value + value;
				iterator= iterator->next;
			}
		}		
	}
};
int main()
{
	List l;
	long long int N;
	cin>>N;
	l.findEuler(N);
	//l.display();
	long long int sum = 0;
	while (!elements.empty())
  {
  	sum+=elements.top();
     cout << sum << ' ';
     elements.pop();
  }
	return 0;
}
