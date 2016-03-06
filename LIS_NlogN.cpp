#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int Bsearch(int *IS, int *a, int lbound,int ubound,int value)
{
    /*cout<<"In Bsearch : lbound - ";
    cout<<lbound;
    cout<<" , ubound - ";
    cout<<ubound<<endl;*/
    int index;
    //if(lbound>ubound)
    //    return ubound+1;
    if(value<=a[IS[lbound]])
        return lbound;
    else if(value>a[IS[ubound]])
        return ubound+1;
    else
    {
        int mid = ceil((lbound+ubound)/2);    
        if(a[IS[mid]]<value && value<a[IS[ubound]])
        {
            index = Bsearch(IS,a,mid+1,ubound,value);
        }
        else if(a[IS[mid]]>=value && value>a[IS[lbound]])
        {
            index = Bsearch(IS,a,lbound,mid-1,value);
        }
    }
    return index;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ifstream input_data;
    input_data.open("inputLIS.txt",ifstream::in);

    int N;
    input_data>>N;
    int a[N],IS[N];
    int parent_pointer[N];
    for(int i=0;i<N;i++)
    {
        input_data>>a[i];
        parent_pointer[i] = -1;
        //cout<<a[i]<<endl;
    }
    IS[0] = 0;
    int j=0;
        
    for(int i=1;i<N;i++)
    {
    	cout<<i<<endl;
        if(a[IS[j]]<a[i])
        {
            parent_pointer[i] = IS[j];
            j++;
            IS[j] = i;
        }
        else
        {
            int index = Bsearch(IS,a,0,j,a[i]);
            if(index>0)
                parent_pointer[i] = IS[index-1];
            else
                parent_pointer[i] = -1;
            IS[index] = i;
        }
        /*for(int k=0;k<N;k++)
        {
            cout<<a[k];
            cout<<" ";
        }
        cout<<endl;
    
        for(int k=0;k<N;k++)
        {
            cout<<IS[k];
            cout<<" ";
        }
        cout<<endl;
        for(int k=0;k<N;k++)
        {
            if(IS[k]>=0 &&IS[k]<100)
            cout<<a[IS[k]];
            else
                cout<<"NA";
            cout<<" ";
        }
        cout<<endl;
        for(int k=0;k<N;k++)
        {
            cout<<parent_pointer[k];
            cout<<" ";
        }
        cout<<endl<<endl;*/
    }
    int length = 0;
    int p = 2;
    int tracker = IS[j];
    while(parent_pointer[tracker]!=-1)
    {
        //cout<<a[tracker]<<endl;
        tracker = parent_pointer[tracker];
        length++;
    }
    cout<<length+1;
    return 0;
}

