#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A;
	string B;
	A = "abc";
    B = "a";
	int N1 = A.length();
	    int N2 = B.length();
	    int opt[2][N2];
	    int max = 0;
	    for(int j=0;j<N2;j++)
	    {
		    if(A[0]==B[j])
		    {
			    opt[0][j] = 1;
			    if(opt[0][j]>max)
			        max = opt[0][j];
		    }
		    else
		    {
		    	opt[0][j] = 0;
			}
	    }
	    for(int i=1;i<N1;i++)
	        for(int j=0;j<N2;j++)
	        {
	    	    if(A[i]==B[j])
	    	    {
	    		    if(j-1<0)
	    		    {
	    			    opt[i%2][j] = 1;
				    }
	    		    else
	    		    {
	    			    opt[i%2][j] = opt[(i-1)%2][j-1]+1;
	    			    if(opt[i%2][j]>max)
	    			    {
						   max = opt[i%2][j];
						}
				    }
			    } 
			    else
			    {
				    opt[i%2][j] = 0;
			    }
		    }
		cout<< max;
	return 0;
}
