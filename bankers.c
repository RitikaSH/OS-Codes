#include<stdio.h>
int required[10],need[10],allocate[10];
void main()
{
    int n, allocateCount=0,max=12;
    printf("ENter the no of processes:\n");
    scanf("%d",&n);
    printf("Enter the required resource:\n");
    for(int i=0; i<n; i++)
    {
    scanf("%d",&required[i]);
    }
    printf("Enter the allocated resource:\n");
    for(int i=0; i<n; i++)
    {
        printf("Allocated resource for process%d:",i+1);
       scanf("%d",&allocate[i]);
       allocateCount+=allocate[i];
       need[i]=required[i]-allocate[i];
    }
    int available=max-allocateCount,sequence=0,ind=0,ans[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(need[j]!=0)
            {
                if(need[j]>available)
                {
                    continue;
                }
                else
                {
                    sequence++;
                    ans[ind++]=j+1;
                    available+=allocate[j];
                    need[j]=0;
                }
            }
        }
    }
    if(sequence<n)
    {
        printf("\nUnsafe condition\n");
    }
    else
    {
        printf("\nSafe condition\n");
        for(int i=0; i<n; i++)
        {
            printf("\n p%d->",ans[i]);
        }
    }
}
