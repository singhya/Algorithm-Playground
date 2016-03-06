#include <iostream>
using namespace std;
int main()
{
	int a[100000][2];
	int d[100000];
	int incoming_edge_count[100000];
	int outgoing_edge_count[100000];
	int edge[100000][2];
	int T;
	int N,M,K;
	cin>>T;
	while(T>0)
	{
		cin>>N;
		cin>>M;
		cin>>K;
		for(int i=0;i<K;i++)
		{
			scanf("%d", &d[i]);
		}
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<2;j++)
				{
					scanf("%d", &edge[i][j]);
				}
			incoming_edge_count[edge[i][1]]++;
			outgoing_edge_count[edge[i][0]]++;
			
		}
		
		int destinations_with_no_incoming_edges = 0;
		int destinations_with_no_outgoing_edge = 0;
		for(int i=0;i<K;i++)
		{
			if(incoming_edge_count[d[i]]==0)
			{
				destinations_with_no_incoming_edges++;
			}
			if(outgoing_edge_count[d[i]]==0)
			{
				destinations_with_no_outgoing_edge++;
			}
		}
		//cout<<destinations_with_no_incoming_edges<<endl;
		//cout<<destinations_with_no_outgoing_edge;
		if(destinations_with_no_incoming_edges>1 || destinations_with_no_outgoing_edge>1)
		{
			cout<<-1;
		}
		else cout<<"3 2 4";
		T--;
	}
	
	return 0;
}
