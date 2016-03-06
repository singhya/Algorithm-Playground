#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    //cin>>N;
    stack<long long int> s;
    long long int h[N+1];
    long long int max_ar = 0;
    int i = 0;
    ifstream input_data;
	input_data.open("input.txt");
	int num;
    input_data >>N;
    //cout<<N;
    
    while(N--)
    {
    	input_data>>h[i];
        cout<<h[i]<<endl;
		long long int ar;
        while(s.empty()==false && h[s.top()]>h[i])
        {
            cout<<"yash"<<endl;
			int top = s.top();
            if(s.size()>1)
            	ar = (i-top) * h[top];
            else
            	ar = i * h[top];
            if(max_ar<ar)
                max_ar = ar;
            s.pop();
            cout<<s.size();
            cout<<" ";
            cout<<"check"<<endl;
        }
        /*if(!s.empty())
            ar = (i-s.top())* h[i];
        if(s.empty())
            ar = (i + 1) * h[i];
        */
		cout<<"Let us c"<<endl;
		if(max_ar<ar)
                max_ar = ar;
        s.push(i++);
        cout<<s.size();
        cout<<" "<<endl;
        
    }
    
    //cout<<endl<<s.size()<<endl;
    while(!s.empty())
    {
        int top = s.top();
        //cout<<i;
        //cout<<" ";
        //cout<<val<<endl;
        long long int ar;
        if(s.size()>1)
            ar = (i-top) * h[top];
        else
            ar = i * h[top];
        if(max_ar<ar)
                max_ar = ar;
        s.pop();
    }
    cout<<max_ar;
    return 0;
}
