#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct info
{
    long int roll;
    char name[100];
    int eng;
    int math;
    int marks;
}stu;
stu arr[MAX];
int top=-1;
void push(stu p)
{
    if(top==MAX-1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        arr[++top]=p;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is popped\n",arr[top--].roll);
    }
}
void sort()
{
    int i,j,temp;
    for(i=0;i<MAX-1;i++)
    {
        for(j=0;j<MAX-1-i;j++)
        {
            if(arr[j].marks>arr[j+1].marks)
            {
                temp=arr[j].marks;
                arr[j].marks=arr[j+1].marks;
                arr[j+1].marks=temp;
            }
        }
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Student information :\n");
        for(i=top;i>=0;i--)
        {
            printf("Name : ");
            puts(arr[i].name);
            printf("\n");
            printf("Roll no. : %ld\n",arr[i].roll);
            printf("Maths marks : %d\n",arr[i].math);
            printf("English marks : %d\n",arr[i].eng);
        }
    }
}
void total_marks(stu mar)
{
    int sum=0;
        mar.marks=mar.eng+mar.math;
}
void peek()
{
    if(top==-1)
    printf("Stack underflow\n");
    else
    printf("Top element name %s\n",arr[top].name);
}
int main()
{
    stu s;
    int ch;
    while(1)
    {
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter 4 for sort\n");
        printf("Enter 5 for pick\n");
        printf("Enter 6 exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter roll no. : ");
                   scanf("%ld",&s.roll);
                   printf("Enter name : ");
                   fflush(stdin);
                   gets(s.name);
                   printf("Enter maths marks : ");
                   scanf("%d",&s.math);
                   printf("Enter english marks : ");
                   scanf("%d",&s.eng);
                   push(s);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:sort();
                   break;
            case 5:peek();
                   break;
            case 6:exit(0);
                   break;
            default:printf("WRONG CHOICE!!");
                      break;
        }
    }
}