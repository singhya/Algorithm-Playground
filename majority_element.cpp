#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    int N = nums.size();
    vector<int> result(0);
    if(N==0)
        return result;
    int first_count = 0;
    int second_count = 0;
    int first_candidate = 0;
    int second_candidate = 1;
	for(int i=0;i<N;i++)
    {
       	if(first_candidate==nums[i])
        {
            first_count++;
        }
        else if(second_candidate ==nums[i])
        {
        	second_count++;
		}
        else if(first_count==0)
        {
            first_candidate = nums[i];
            first_count = 1;
        }
        else if(second_count == 0)
        {
        	second_candidate = nums[i];
        	second_count = 1;
		}
        else
        {
        	first_count--;
        	second_count--;
		}
    }
    first_count = 0;
    second_count = 0;
    for(int i=0; i<N; i++)
    {
    	if(first_candidate == nums[i])
    	{
    		first_count++;
		}
		else if(second_candidate == nums[i])
		{
			second_count++;
		}
	}
	if(first_count>N/3)
	{
		result.push_back(first_candidate);
	}
	if(second_count>N/3)
	{
		result.push_back(second_candidate);
	}
	return result;
}
    int main() {
	
	// your code here
	
		vector<int> a = {1,1,1,2,3,4,5,6};
	    vector<int> r  = majorityElement(a);
	    cout<<"-------------"<<endl;
		for(vector<int>::iterator i=r.begin(); i!=r.end();i++)
		{
			cout<<(*i)<<endl;
		}
	
	return 0;
}
