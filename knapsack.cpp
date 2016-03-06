# include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
void knapsack(int n, float weight[], float profit[], float id[], float capacity) {
   float x[n], tp = 0;
   int i, j, u;
   u = capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
   	cout<<u<<endl;
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   tp = tp + (x[i] * profit[i]);
   printf("\nThe result vector is: ");
   for (i = 0; i < n; i++)
   {
      if(x[i] ==1)
      {
      	cout<<id[i];
      	cout<<",";
      }
	  else if(x[i] !=0)
	  {
	  	cout<<id[i];
      	cout<<"*,";
      	
	  }
}

 cout<<endl;
   printf("\nMaximum profit is: %f", tp);
 
}
 
int main() {
   int num =33;
   float capacity = 140;
   float a[num*3] = {1,4,29, 2,2,14, 3,8,36, 4,6,53, 5,9,23, 6,5,51, 7,8,53, 8,9,19, 9,10,51, 10,1,25, 11,10,25, 12,6,49, 13,5,10, 14,6,41, 15,2,8, 16,6,26, 17,5,17, 18,6,14, 19,10,7, 20,6,35, 21,3,31, 22,2,21, 23,3,41, 24,9,46, 25,9,16, 26,9,36, 27,9,38, 28,3,60, 29,9,26, 30,7,41, 31,1,56, 32,8,47, 33,18,52};
   float weight[num], profit[num], id[num];
	for(int t=0;t<num*3;t++)
	{
		if(t%3==0)
		{
			id[t/3] = a[t];
		}
		else if((t-1)%3==0)
		{
			profit[t/3] = a[t];
		}
		else
		{
			weight[t/3] = a[t];
		}
		
	   }  
	   for(int i=0;i<2;i++)
	   {
	   	cout<<weight[i];
	   	cout<<" ";
	   	cout<<profit[i];
		} 
   int i, j;
   float ratio[num], temp;
 
   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
            
            temp = id[j];
            id[j] = id[i];
            id[i] = temp;
         }
      }
   }
   
   for(i=0;i<num;i++)
   {
   	cout<< ratio[i]<<" ";
   }
 
   knapsack(num, weight, profit, id, capacity);
   return(0);
}
