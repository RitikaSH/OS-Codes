/*
    Created By : Vikram Markali
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]) 
{ 
   int i,ele,a[argc];

   // Converting Constant strings into array of integers...
   for(i=0;i<argc;i++)		
	{
        a[i]=atoi(argv[i]);	
    }

    // after sorting...
        printf("\nAfter sorting:\t");
        for(i = argc-1; i>=0; i--)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
}