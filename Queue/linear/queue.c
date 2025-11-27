#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main()
{
    int arr[MAX],v=0,front=-1,rear=-1;
    char ch;
    while(1)
    {
        printf("Enter E/e for enqueue\n");
        printf("Enter D/d for dequeue\n");
        printf("Enter S/s for display\n");
        printf("Enter X/x for exit\n");
        fflush(stdin);
        scanf("%c",&ch);
        switch(ch)
        {
            case 'E':
                    case 'e':
                            if(rear == (MAX-1))
                                  printf("QUEUE is full\n");
                            else 
                            {
                                printf("Enter a number \n");
                                scanf("%d",&v);
                                if(front==-1)
                                {
                                    front+=1;
                                }
                                arr[++rear]=v;
                            }
                            break;
            case 'D':
                    case 'd':  
                            if(front==-1)
                                    printf("Queue is empty\n");
                            else
                            {
                                if(front==rear)
                                {
                                    printf("%d",arr[front]);
                                    front=-1;rear=-1;
                                }
                                else
                                {
                                    printf("%d",arr[front]);
                                    front++;
                                }
                            }
                            break;
            case 'S':
                    case 's':
                            if(front==-1)
                                printf("Queue is empty\n");
                            else
                            {
                                printf("displaying queue :\n");
                                for(int i=front;i<=rear;i++)
                                {
                                    printf("%d ",arr[i]);
                                }
                                printf("\n");                            }
                            break;
            case 'X':   
                    case 'x':exit(0);      
            default : printf("Wrong choice!!");            
        }
    }
}