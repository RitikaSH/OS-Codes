#include<stdio.h>
int arr[50],bf[50];
int pageHit(int data,int size)
{
    for(int i=0; i<size; i++)
    {
        if(bf[i]==data)
            return 1;
    }
    return 0;
}
int ind=0,hit=0;
void fifo(int arr[],int n,int bf[],int size)
{
    for(int i=0; i<n; i++)
    {
        if(pageHit(arr[i],size)==1)
        {
            hit++;
        }
        else
        {
            bf[ind++]=arr[i];
        }
        if(ind==size)
        {
            ind=0;
        }
    }
    printf("Page Hit=%d",hit);
    printf("Page fault=%d",n-hit);
}

void main()
{
    int n,size;
    printf("enter the length of string:\n");
    scanf("%d",&n);
    

    printf("Enter the %d elements:",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("enter the size of buffer:\n");
    scanf("%d",&size);
    for(int i=0; i<size; i++)
    {
        bf[i]=9999;
    }
    
    fifo(arr,n,bf,size);

}