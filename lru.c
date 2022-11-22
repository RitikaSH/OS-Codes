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

int indexRet(int start,int size,int n)
{
    int ans,j,ind=start-1;
    for(int i=0; i<size; i++)
    {
        for(j=start-1; j>=0; j--)
        {
            
            if(arr[j]==bf[i])
            {
                if(j<ind){
                ind=j;
                ans=i;
                }
                break;
            }//0 1 3 6 2 4 5 2 5 0 3 1 2 5 4 1 0
        }
        if(j==0)
            return i;
    }
    return ans;
}

int hit=0;
void fifo(int arr[],int n,int bf[],int size)
{
    for(int i=0; i<n; i++)
    {
        if(pageHit(arr[i],size)==1)
        {
            printf("for %d : page Hit\n",arr[i]);
            hit++;
        }
        else
        {
            if(i<size)
            {
                bf[i]=arr[i];
            }
            else
            {
           int ans=indexRet(i,size,n);
           printf("for %d : page fault %d\n",arr[i],bf[ans]); 
           bf[ans]=arr[i];
            }
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
