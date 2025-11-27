#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
struct node *new_node;
struct node *ptr;
void create()
{
    new_node=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new_node->data);
}
void push()
{
    create();
    if(top==NULL)
    new_node->next=NULL;
    else
    new_node->next=top;
    top=new_node;
}
int pop()
{
    int var;
    ptr=top;
    top=ptr->next;
    var=ptr->data;
    free(ptr);
    return var;
}
void display()
{
    ptr=top;
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
        printf("\nEnter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 4 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:printf("%d popped succesfully\n",pop());
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("INVALID\n");
                    break;
        }
    }
}