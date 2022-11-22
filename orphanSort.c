#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
// Quick Sort
int partition(int arr[],int l,int h)
{
    int pivot=arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[l];
    arr[l]=arr[j];
    arr[j]=temp;
    return j;
}
void quickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int pivot=partition(arr,l,h);
        quickSort(arr,l,pivot);
        quickSort(arr,pivot+1,h);
    }
}
//Merge Sort
void merge(int arr[],int l, int mid, int h)
{
    int i,j,k;
    int b[h-l+1];
   for(i=l,j=mid+1,k=l; i<=mid && j<=h; k++ )
   {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i++];
        }
        else
        {
            b[k]=arr[j++];
        }
       
    }
        while (j<=h)
        {
            b[k++]=arr[j++];
        }
        while(i<=mid)
        {
            b[k++]=arr[i++];
        }
    for(k=l; k<=h; k++)
    {
        arr[k]=b[k];
    }
}
void mergeSort(int arr[],int l, int h)
{
    if(l<h)
    {
    int mid=(l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
    }
    
}
int main()
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //Orphan state
    int pid;
    pid=fork();
    if(pid==0)
    {
        int stc=30;
        wait(&stc);
        printf("Child process with id %d\n",getpid());
        quickSort(arr,0,n);
        printf("Array After Sorting:\n");
        for(int i=1; i<=n; i++)
        {
             printf("%d\n",arr[i]);
        }
    }
    else
    {
        printf("Parent process with id %d\n",getpid());
        mergeSort(arr,0,n);
        printf("Array After Sorting:\n");
        for(int i=1; i<=n; i++)
        {
             printf("%d\n",arr[i]);
        }
    }
    return 0;
}