// my first program in C++
#include <iostream>


int main()
{
  std::cout << "Hello World!\n";
  int count = 4;
  int array[count] = {1,2,3,4};
  int diff[count-1];
  for(int i=1;i<count;i++)
  {
  	diff[i-1]=array[i]-array[i-1];
  }
  for (int i=0;i<count-1;i++)
  {
  	std::cout<<diff[i]<< " ";
  }
  (arr,left,right) = FindMaxSubArray(array,0,count-1);
}
