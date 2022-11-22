#include<stdio.h>
#include<stdlib.h>

int main()
{
    int RQ[50],n,totalHM=0,head=0,count=0;
    printf("Enter the no of request:");
    scanf("%d",&n);
    printf("Enter Request sequence:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&RQ[i]);
    }

    printf("Enter head Position: ");
    scanf("%d",&head);

    while(count!=n)
    {
        int min=9999,d,index;
        for(int i=0; i<n; i++)
        {
            d=abs(RQ[i]-head);
            if(min>d)
            {
                min=d;
                index=i;
            }
        }
        totalHM+=min;
        head=RQ[index];
        RQ[index]=1000;
        count++;
    }
    printf("Total Head Moment is: %d",totalHM);
    return 0;
}