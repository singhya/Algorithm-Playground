#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <fstream>

using namespace std;
struct Node
{
    int node;
    int level;
};
void BFS(unordered_map<int, vector<int>> G, int S, int N)
{
    int a[N];
    int visit_count = 0;
    //unordered_set<int> s;
    for(int i=0;i<N;i++)
    {
        a[i] = -1;
    }
    
    queue<Node> q;
    Node n;
    n.node = S;
    n.level = 0;
    q.push(n);
    //s.insert(S);
    long long int level = 0;
    while(!q.empty() && visit_count<N)
    {
        Node selected_node = q.front();
        //cout<<selected_node.node<<endl;
        q.pop();
        visit_count++;
        //if(G.find(selected_node.node)!=G.end())
        {
            vector<int> child = G[selected_node.node];
            for(int i=0;i<child.size();i++)
            {
                if(a[child[i]] == -1)
                {
                    Node n;
                    n.node = child[i];
                    n.level = selected_node.level+1;
                    //s.insert(child[i]);
                    q.push(n);
                    a[child[i]] = (selected_node.level+1) * 6;
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(i!=S)
        {
            cout<<a[i];
            cout<<" ";
        }
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ifstream fin("input.txt");
	int T,N,M,S;
    fin>>T;
    while(T--)
    {
        fin>>N;
        fin>>M;
        unordered_map<int, vector<int>> G;
        int u,v;
        for(int i=0;i<M;i++)
        {
            fin>>u;
            fin>>v;
            u = u-1;
            v= v-1;
            if(G.find(u)==G.end())
            {
                vector<int> vec;
                vec.push_back(v);
                G[u] = vec;
            }
            else
            {
                vector<int> vec = G[u];
                vec.push_back(v);
                G[u]=vec;
            }
            if(G.find(v)==G.end())
            {
                vector<int> vec;
                vec.push_back(u);
                G[v] = vec;
            }
            else
            {
                vector<int> vec = G[v];
                vec.push_back(u);
                G[v]=vec;
            }
        }
        fin>>S;
        //S=2;
        S=S-1;
        BFS(G,S,N);
        
    }
    return 0;
}

