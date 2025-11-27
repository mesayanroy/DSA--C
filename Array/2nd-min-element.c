#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,n;
    printf("Enter the number of element you want to input\n");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    int i;
    printf("Enter array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    int min=ptr[0],min2,max=ptr[0];
    for(i=1;i<n;i++)
    {
        if(min>ptr[i])
        min=ptr[i];
        if(ptr[i]>max)
        max=ptr[i];
    }
    for(i=1;i<n;i++)
    {
        if(ptr[i]>min && ptr[i]<max && ptr[i]!=min)
        {
            min2=ptr[i];
        }
    }
    printf("Minimum number in the array : %d\n",min);
    printf("Second minimum number in the array : %d %d",min2);
}
/*Output
Enter the number of element you want to input
10
Enter array elements :
24
20
27
35
48
87
154
55
14
88
Minimum number in the array : 14
Second minimum number in the array : 20
*/