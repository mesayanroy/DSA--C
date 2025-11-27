//Bubble sort
#include<stdio.h>
int main()
{
    int arr[5],i,j,t;
    printf("Enter array elements :\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("before sorting :\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    printf("\nAfter using bubble sorting :\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}