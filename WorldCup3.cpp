#include <iostream>
using namespace std;
struct Edge
{
	int Node1Index;
	int Node2Index;
	Edge* next;
};
struct Node
{
	long long int value;
	Edge* head;
};
void printVisitedArray(int* visitedNodes, int N)
{
	cout<<"Printing visited aray:";
	for(int i=0;i<N;i++)
	{
		cout<<visitedNodes[i]<<" ";
	}
	cout<<endl;
}
long long int BFS (int index,Node* array,long long int sum,int* visitedNodes,int N)
{
	Edge* iterator = array[index].head;
	if(iterator!=NULL)
	{
		long long int s = 0;
		while(iterator)
		{
			if(visitedNodes[iterator->Node2Index]==1)
			{
				iterator=iterator->next;
				continue;
			}
			visitedNodes[index] = 1;
			s += BFS(iterator->Node2Index, array, sum, visitedNodes,N);
			iterator=iterator->next;
		}
		
		//printVisitedArray(visitedNodes, N);
		/*cout<<"Sum for tree :";
		cout<<index+1<<endl;
		cout<<index+1<<" "<<s<<endl;*/
		return s+array[index].value;		
	}
	else
	{
		
		//printVisitedArray(visitedNodes, N);
		/*cout<<"Sum for tree :";
		cout<<index+1<<endl;
		cout<<index+1<<" "<<sum<<endl;*/
		visitedNodes[index] = 1;
		return array[index].value;
	}
}
int main()
{
	int N;
	cin>>N;
	Node* array = new Node[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d", &array[i].value);
		array[i].head=NULL;
	}
	for(int i=0;i<N-1;i++)
	{
		int node1;
		int node2;
		scanf("%d", &node1);
		scanf("%d", &node2);
		node1--;
		node2--;
		Edge* e = new Edge;
		e->Node1Index = node1;
		e->Node2Index = node2;
		e->next = NULL;
		if(array[node1].head==NULL)
		{
			array[node1].head =  e;
		}
		else
		{
			Edge* iterator;
			iterator = array[node1].head;
			while(iterator->next)
			{
				iterator = iterator->next;
			}
			iterator->next = e;
		}
		e = new Edge;
		e->Node1Index = node2;
		e->Node2Index = node1;
		e->next = NULL;
		if(array[node2].head==NULL)
		{
			array[node2].head = e;
		}
		else
		{
			Edge* iterator;
			iterator = array[node2].head;
			while(iterator->next)
			{
				iterator = iterator->next;
			}
			iterator->next = e;
		}
	}
	long long int totalSum = 0;
	for(int i=0;i<N;i++)
	{
		totalSum += array[i].value;
	}
	int selectedNode;
	int solution = 0;
	for(int i=0;i<N;i++)
	{
		int edgeCount = 0;
		
		Edge* iterator = array[i].head;
		while(iterator)
		{
			edgeCount++;
			iterator = iterator->next;
		}
		if(edgeCount==1 && array[i].value>totalSum/2)
		{
			cout<<array[i].value;
			solution = 1;
			break;
		}
	}
	//cout<<endl;
	/*cout<<"Display tree"<<endl;
	for(int i=0;i<N;i++)
	{
		int count = 0;
		Edge* iterator = array[i].head; 
		while(iterator!=NULL)
		{
			count++;
			cout<<iterator->Node1Index+1;
			cout<<" ";
			cout<<iterator->Node2Index+1;
			iterator=iterator->next;
			cout<<endl;
		}
		cout<<"For Node ";
		cout<<i+1;
		cout<<count<<endl;
	}*/
	for(int i=0;i<N&&!solution;i++)
	{
		selectedNode = i;
		/*cout<<endl;
		cout<<"selected Node:";
		cout<<selectedNode<<endl;*/
		
		Edge* iterator = array[selectedNode].head;
		int flag = 0;
		long long int sum = 0;
		while(iterator)
		{
			int* visitedNodes = new int[N];
			visitedNodes[iterator->Node1Index]=1;
			long long int newSum = BFS(iterator->Node2Index,array,0,visitedNodes,N);
			//cout<<newSum<<endl;
			if(newSum>sum)
			{
				sum = newSum;
			}
			if(newSum>totalSum/2)
			{
				flag = 1;
			}
			
			selectedNode = iterator->Node2Index; 
			iterator = iterator->next;
		}
		
		if(flag==0)
		{
			/*cout<<"Total sum:";
			cout<<totalSum;
			cout<<" ";
			cout<<sum;
			cout<<" ";*/
			cout<<totalSum-sum;
			break;
		}
	}
	return 0;
}
