/*
Given an array of integers (both positive and negative), write a program to find the maximum sum of a contiguous subarray using Kadane’s Algorithm.
Example Input 1:
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Expected Output: 6
Explanation: The subarray [4, -1, 2, 1] has the maximum sum 6.
Example Input 2:
arr = [1, 2, 3, 4, 5]
Expected Output: 15 */
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int max_sum=INT_MIN;
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int Max_subarray(int *arr,int n)
{
    int i,s=0;
    for(i=0;i<n;i++)
    {
        s+=arr[i];
        max_sum=max(s,max_sum);
        if(s<0)
        s=0;
    }
    return max_sum;
}
int main()
{
    int *ptr,n1,ans,i;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d",&n1);
    ptr=(int*)calloc(n1,sizeof(int));
    printf("Enter the array elements :\n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&ptr[i]);
    }
    ans=Max_subarray(ptr,n1);
    printf("The maximum subarray is : %d",ans);
}
/*
output

Enter the number of elements you want to enter : 8
Enter the array elements :
-2
-3
4
-1
-2
1
5
-3
The maximum subarray is : 7
*/