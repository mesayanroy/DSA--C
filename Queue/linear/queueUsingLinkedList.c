#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *ptr;//act as rear pointer
struct node *new_node;
struct node *head=NULL;//act as front pointer
struct node *end;
void create(int x)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=x;
}
void add_beg()//Enqueue
{
    int n;
    printf("Enter data : ");
    scanf("%d",&n);
    create(n);
    if(head==NULL)
    new_node->next=NULL;
    else
    new_node->next=head;
    head=new_node;
}
void delete_atlast()//Dequeue
{
    ptr=head;
    int i;
    for(ptr=head;ptr->next->next!=NULL;ptr=ptr->next);
    printf("%d is dequeued\n",ptr->next->data);
    free(ptr->next->next);
    ptr->next=NULL;
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("Enter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display\nEnter 4 to exit menu\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:add_beg();
                   break;
            case 2:delete_atlast();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("WRONG INPUT!!");
        }
    }
}