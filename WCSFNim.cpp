#include <iostream>
#include <string>
#include <map>
using namespace std;
void display(long int* a, int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
		
	}
	cout<<endl;
}
long int checkNIM(long int* a, int N, map<string, bool> &nim, int k)
{
	//cout<<"Checking for : "<<endl;
	//cout<<k;
	//cout<<" : ";
	//cout<<N;
	//cout<<" : ";
	//display(a,N);
	string s;
	long int temp = 0;
	for(int j=0;j<N;j++)
	{
		temp = temp ^ a[j];
		s += to_string(a[j])+","; 
	}
	if (temp==0 && nim.find(s) == nim.end())
	{
		
		//cout<<s;
		nim[s] = true;
		/*for(map<string, bool >::const_iterator it = nim.begin();
	    it != nim.end(); ++it)
		{
		    cout << it->first << " " << it->second << "\n";
		}*/
		return 1;
	}
	else return 0;
}
long int recursive(long int *a, int N, map<string, bool> &nim, int k)
{
	if(N>2 && k<N-1)
	{
		long int counter = 0;		
		long int new_data[N-1]; 
		for(int i=0;i<N-1;i++)
		{						
			if(i>k)
			{
				new_data[i]= a[i+1];
			}
			else if(i<k)
			{
				new_data[i] = a[i];
			}
			else
			{
				new_data[i] = a[i]+a[i+1];
			}
		}
		counter+= checkNIM(new_data,N-1,nim, k);
		counter+= recursive(new_data,N-1,nim,k);
		k++;
		for(;k<N-1;k++)
		{
			new_data[k-1] = new_data[k-1] - a[k];
			new_data[k] = new_data[k]+a[k];
			if(k<N-1)
			{
				counter+= checkNIM(new_data,N-1,nim, k);
				counter+= recursive(new_data,N-1,nim,k);
			}
		}
		//counter+= recursive(new_data,N-1,nim);
		return counter;
	}
	return 0;
}

int main()
{
	int N;
	long data[36];
	map<string, bool> nim;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		scanf("%ld", &data[i]);
	}
    //display(data,N);
	int count = checkNIM(data,N,nim,0);
	count+=recursive(data,N,nim,0);
	
	cout<<count;
	return 0;
}
