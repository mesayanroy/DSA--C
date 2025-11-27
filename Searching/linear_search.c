#include<stdio.h>
int main()
{
    int s,i,pos,arr[10],c=0;
    printf("Enter array :\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search :\n");
    scanf("%d",&s);
    for(i=0;i<10;i++)
    {
        if(arr[i]==s)
        {
            printf("Element found at position : %d",i);
            c++;
            break;
        }
    }
    if(c==0)
        printf("Element not found!"):
    return 0;
}