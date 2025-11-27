//Selection sort
#include<stdio.h>
int main()
{
    int arr[5],i,j,t=0,min;
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
    printf("\n");
    for(i=0;i<4;i++)
    {
        min=i;
        for(j=i+1;j<=4;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }
    printf("\nAfter using selection sorting :\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}