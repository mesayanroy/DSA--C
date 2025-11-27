#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,max=10;
void enqueue(int *ptr)
{
    int v;
    if(max-1==rear)
    printf("Queue is full!\n");
    else
    {
        printf("Enter element to insert :\n");
        scanf("%d",&v);
        if(front==-1)
        {
            front++;
        }
        ptr[++rear]=v;
    }
}
void dequeue(int *prr)
{
    if(front==-1)
    printf("Queue is empty!");
    if(front==rear)
    {
    printf("%d ",prr[front]);
    front=-1;
    rear=-1;
    }
    else
    {
        printf("%d",prr[front]);
        front++;
    }
}
void display(int *pr)
{
    if(front==-1)
    printf("Queue is empty\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",pr[i]);
    }
    printf("\n");
}
int main()
{
    char ch;int arr[max];
    while(1)
    {
        printf("Enter I/i for enqueue\n");
        printf("Enter D/d for dequeue\n");
        printf("Enter S/s for display\n");
        printf("Enter X/x for exit\n");
        fflush(stdin);
        scanf("%c",&ch);
        switch(ch)
        {
            case 'I':
            case 'i':enqueue(&arr[0]);
                    break;
            case 'D':
            case 'd':dequeue(&arr[0]);
                     break;
            case 'S':
            case 's':display(&arr[0]);
                     break;
            case 'X':
            case 'x':exit(0);
                     break;
            default:printf("Wrong input!!\n");
                    break;    
        }
    }
}