#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
void charToArray(int size,int arr[],char* charArray[])
{
   for(int i=0;i<size;i++)
   {
      int temp=atoi(charArray[i]);
      arr[i]=temp;
   }
}
void printArray(int arr[], int size)
{
   printf("Array in reverse order");
   for(int i=size-1;i>=0;i--)
   {
      printf("%d",arr[i]);
   }
}
int main(int size,char *charArray[])
{
  int arr[size];
  charToArray(size,arr,charArray);
  printArray(arr,size);
  return 0;
}
