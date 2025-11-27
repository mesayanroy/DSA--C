#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX],front=-1,rear=-1;
void enqueue(int *ptr)
{
    if(front==(rear+1)%MAX)
    printf("Queue is full!\n");
    else
    {
        if(front==-1)
        front=0;
        rear=(rear+1)%MAX;
        arr[rear]=*ptr;
        printf("%d enqueued\n",arr[rear]);
    }
}
int dequeue()
{
    int var;
    if(front==-1)
        return -1;
    else{

    var=arr[front];
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;

    return var;
    }
}
void display()
{
    if(front==-1)
    printf("Queue is empty!\n");
    else
    {
    for(int i=front;i!=rear;i=(i+1)%MAX)
    {
        printf("%d ",arr[i]);
    }
    printf("%d",arr[rear]);
    printf("\n");
    }
}
int main()
{
    int ch,n,ans;
    while(1)
    {
    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter element to enqueue :\n");
               scanf("%d",&n);
               enqueue(&n);
               break;
        case 2:ans=dequeue();
                if(ans==-1)
                    printf("\nQueue is empty");
                else{
                    printf("\n%d is dequeued!\n",ans);
                }
               break;
        case 3:display();
               break;
        case 4:exit(0);
               break;
        default:printf("Invalid input!\n");
                break;
    }
    }
}   