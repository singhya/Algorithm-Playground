#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    n = 250;
    m = 24;
    int a[m] = {41, 34, 46, 9, 37, 32, 42, 21, 7, 13, 1, 24, 3, 43, 2, 23, 8, 45, 19, 30, 29, 18, 35, 11};
    for(int i=0;i<m;i++)
    {
        //cin>>a[i];
    }
    long long int opt[n+1][m+1];
    for(int i=1;i<=n;i++)
    {   
       if(i%a[0]==0)
           opt[i][1]=1;
       else
           opt[i][1]=0;
    }
    bool unityIncluded = false;
    for(int i=1;i<=m;i++)
    {    
        if(a[i-1]==1 || unityIncluded)
        {
            opt[1][i]=1;
            unityIncluded = true;
        }
        else
        {
        	opt[1][i]=0;
		}
    }
    for(int i=0;i<=m;i++)
    {
        opt[0][i]=1;
    }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++)
        {
            if(i-a[j-1]>=0)
            opt[i][j] = opt[i-a[j-1]][j]+opt[i][j-1];
            else
            opt[i][j] = opt[i][j-1];
    }
    for(int i=1;i<=n;i++)
    {    for(int j=1;j<=m;j++)
        {
            cout<<opt[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<opt[n][m];
    return 0;
}

