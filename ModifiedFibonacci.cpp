#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

string productFun(string a, string b)
{
	vector<int> result(a.size() + b.size(), 0);
	for( int i = a.size() - 1; i >= 0; i-- )
	{
		for( int j = b.size() - 1; j >= 0; j-- )
		{
			
			result[ i + j + 1 ] += ( b[ j ] - '0') * ( a[ i ] - '0' ); //single array to store intermediate values
		}
	}
    for( int i = a.size() + b.size() - 1; i >= 0; i-- ){
		if( result[ i ] >= 10 ){
			result[ i - 1 ] +=result[ i ] / 10;result[ i ] %= 10;
		}
	}
    string product="";
    for (int i = 0; i < result.size(); i++) 
    {
		product = product + to_string(result[i]);
    }
    return product;
}

string sum(string str1, string str2)
{
	size_t n = max(str1.size(), str2.size());
    if (n > str1.size())
        str1 = string(n-str1.size(), '0') + str1;
    if (n > str2.size())
        str2 = string(n-str2.size(), '0') + str2;

    string final(n+1, '0');

    char carry = 0;

    // Iterators
    string::const_reverse_iterator s1 = str1.rbegin(), e = str1.rend(),
                                   s2 = str2.rbegin();
    string::reverse_iterator f = final.rbegin();

    // Conversion
    for (; s1 != e; ++s1, ++s2, ++f)
    {
        // Bracketing to avoid overflow
        char tmp = (*s1-'0')+(*s2-'0') + carry;
        if (tmp > 9)
        {
            carry = 1;
            tmp -= 10;
        }
        else
        {
            carry = 0;
        }
        *f = tmp + '0';
    }
    final[0] = carry + '0';

    // Remove leading zeros from result
    n = final.find_first_not_of("0");
    if (n != string::npos)
    {
        final = final.substr(n);
    }
  
    return final;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cpp_int a,b,c;
    //string Sa,Sb;
    cin>>a;
    cin>>b;
    cin>>c;
    if(c==1)
    {
        cout<<a;
    }
    else if(c==2)
    {
        cout<<b;
    }
    else
    {
        c=c-2;
        //Sa = to_string(a);
        //Sb = to_string(b);
        
        while(c)
        {
    		//string product = productFun(Sb,Sb);
            //string next_num = sum(Sa,product);
			//cout<<next_num<<endl;
			cpp_int next_num = a+(b*b);
			if(c==1)
            {
                cout<<next_num<<endl;
                //cout<<next_num.size();
                break;
            }
            //Sa=Sb;
            //Sb=next_num;
            a=b;
            b=next_num;
            c--;
        }
    }
    return 0;
}

