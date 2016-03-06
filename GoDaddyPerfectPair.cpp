#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

bool BFS(int u, int v, map<int, vector<int> > graph, map<int, int>& visited_nodes)
{
	queue<int> q;
	q.push(u);
	bool goalAttained = false;
	visited_nodes[u] = 0;
	while(!q.empty() && !goalAttained)
	{
		int selected_node = q.front();
		if(selected_node==v)
		{	
			return true;
		}
		
		// Moving to next level
		vector<int> edges = graph[selected_node];
		q.pop();
		//cout<<q.front().name<<" ";
		for(vector<int>::iterator i=edges.begin(); i!=edges.end() && !goalAttained; ++i){
			int nodeTo = (*i);
			if(visited_nodes.find(nodeTo) == visited_nodes.end())
			{
				q.push(nodeTo);
   				visited_nodes[nodeTo] = selected_node;
			}	
		}
	}
	return false;
}
void display(map<int, vector<int>>g)
{
	for(map<int, vector<int>>::iterator i=g.begin(); i!=g.end() ;i++){
	cout<<i->first;
	cout<<" : ";
	for(vector<int>::iterator j=i->second.begin(); j!=i->second.end(); j++)
	{
		cout<<(*j);
		cout<<" , ";
	}
	cout<<endl;
	}
}
	
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,M,Q;
    
    cin>>N;
    cin>>M;
    cin>>Q;
    int u;
    int v;
    map<int, vector<int> > graph;
    for(int i=0;i<M;i++)
    {
        cin>>u;
        cin>>v;
        if(graph.find(u) == graph.end())
		{
   			vector<int> vec;
   			vec.push_back(v);
   			graph[u] = vec;
		}
		else
		{
			graph[u].push_back(v);
		}
		if(graph.find(v) == graph.end())
		{
   			vector<int> vec;
   			vec.push_back(u);
   			graph[v] = vec;
		}
		else
		{
			graph[v].push_back(u);
		}
    }
    
    for(int i=0;i<Q;i++)
    {
    	cin>>u;
    	cin>>v;
    	map<int, vector<int> > new_graph = graph; 
    	map<int, int> visited_nodes;
    	//display(new_graph);
    	if(BFS(u,v,graph,visited_nodes))
		{
			int current_node = v;
			/*for(map<int, int>::iterator i=visited_nodes.begin(); i!=visited_nodes.end() ;i++){
				cout<<i->first;
				cout<<" : ";
				cout<<i->second;
				cout<<endl;
			}*/
    		while(current_node!=u && visited_nodes.find(current_node) != visited_nodes.end())
			{
				int parent = visited_nodes[current_node];
				//cout<<"---- Removing edge between ";
				//cout<<current_node;
				//cout<<" and ";
				//cout<<parent<<endl;
				
				
				new_graph[current_node].erase(remove(new_graph[current_node].begin(), new_graph[current_node].end(), parent), new_graph[current_node].end());
				new_graph[parent].erase(remove(new_graph[parent].begin(), new_graph[parent].end(), current_node), new_graph[parent].end());
				current_node = parent;
			}
		}
		else
		cout<<"NO1"<<endl;
		map<int, int> new_visited_nodes;
		//display(new_graph);
		if (BFS(u,v,new_graph,new_visited_nodes))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
    return 0;
}

