#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *prev=NULL;
struct node *ptr;
struct node *new_node;
void create()
{
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&new_node->data);
}
void add_beg()
{
    create();
    if(head==NULL)
    new_node->next=NULL;
    else
    new_node->next=head;
    head=new_node;
}
void reverse()
{
    struct node *next=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    head=prev;
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    int i;
    for(i=0;i<5;i++)
    add_beg();
    printf("Original list : ");
    display();
    printf("Reverse list : ");
    reverse();
    display();
}