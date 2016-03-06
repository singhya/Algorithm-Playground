#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int count;
	int value;
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int c[6];
		int count = 0;
		int sum = 0;
		for(int i=0;i<6;i++)
		{
			cin>>c[i];
			sum+=c[i]*(i+1);
			count+=c[i];
		}
		vector<int> marbles(0);
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<c[i];j++)
			{
			    marbles.push_back(i+1);
			    //cout<<i+1<<endl;
		    }
		}
		/*for(int i=0;i<count; i++)
		{
			cout<<marbles[i]<<endl;
		}*/
		if(sum%2==1)
		{
			cout<<"No"<<endl;
			continue;
		}
		int half = sum/2;
		node opt[count][half+1];
		for(int j=0;j<count;j++)
		{
			opt[j][0].value = true;
			opt[j][0].count = 0;
		}
		for(int i=0;i<count;i++)
		    
			for(int j=1;j<=half;j++)
		    {
		    	if(i>0 && opt[i-1][j].value)
				{
					opt[i][j].value = true;
					opt[i][j].count = opt[i-1][j].count;
				}
				else if(i>0 && j-marbles[i] >=0 && opt[i-1][j-marbles[i]].value)
				{
					opt[i][j].value = true;
					opt[i][j].count = opt[i-1][j-marbles[i]].count+1;
				}
				else if(j==marbles[i])
		    	{
		    		opt[i][j].value = true;
		    		opt[i][j].count = 1;
				}
				else
				{
					opt[i][j].value = false;
					opt[i][j].count = 0;
				}
			}
		/*for(int i=0;i<count;i++)
		{
			cout<<marbles[i];
			cout<<" : ";
		    for(int j = 0; j<=half;j++)
		    {
		    	cout<<opt[i][j].count;
		    	cout<<"|";
		    	cout<<opt[i][j].value;
		    	cout<<" ";
			}
			cout<<endl;
	    }	*/
	    if(opt[count-1][half].value)
	    {
	    	cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
