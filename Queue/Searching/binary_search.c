//binary search
#include<stdio.h>
void main()
{
    int arr[5],i,k,min,beg,end,mid;
    printf("Enter array elements in ascending order:");
    scanf("%d",&arr[0]);
    for(i=1;i<5;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<arr[i-1])
        {
            printf("Invalid input");
            i--;
        }
    }
    printf("\nDisplaying unsorted array:");
    for(i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter search element:");
    scanf("%d",&k);
    beg=0;
    end=4;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(k<arr[mid])
        {
            end=mid-1;
        }
        else if(k>arr[mid])
        {
            beg=mid+1;
        }
        else{
            printf("found at position %d",(mid+1));
            break;
        }
    }
    if(beg>end){
        printf("not found");
    }
}