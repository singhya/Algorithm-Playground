#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int value;
    int index = 0; 
    node* next;
};
struct nodeList
{
    node* head;
};
long long int DFS(node* n,int N, nodeList** l)
{
    node* p = n;
    long long int subtree_sum = 0;
    if(p->next==NULL)
    {
        return p->value;
    }
    while(p->next!=NULL)
    {
        subtree_sum += DFS(l[p->index]->head,N,l);
        p=p->next;
    }
    return subtree_sum;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    nodeList *l;
    l = new nodeList[N]; 
    //for(int i=0;i<N;i++)
    //    l[i]->head = NULL;
    for(int i=0;i<N;i++)
    {
        int value;
        cin>>value;
        cout<<value<<endl;
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = value;
        new_node->next = NULL;
        new_node->index = i;
        l[i].head = new_node;
    }
    /*
    for(int i=0;i<N-1;i++)
    {
        int parent, child;
        cin>>parent;
        cin>>child;
        node* new_node = new node;
        new_node->value = l[child-1]->head->value;
        new_node->next = NULL;
        new_node->index = child-1;
        node* p = l[parent-1]->head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = new_node;
    }
    cout<<DFS(l[0]->head,N,l);*/
    return 0;
}

