#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#define MAX 20
int a[1000];

void quik_sort(int low,int high)
{
   int i,j,pivot,temp;
   if(low<high)
   {
   pivot=low;
   i=low;
   j=high;
   while(i<j)
   {
      while(a[i]<=a[pivot] && i<high)
      {
        i++;
      }
      while(a[j]>a[pivot])
      {
         j--; 
      }
      if(i<j)
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
      
    }
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    
    quick_sort(low,j-1);
    quick_sort(j+1,high)
    
    }
  }
  
  int main()
  {
  
