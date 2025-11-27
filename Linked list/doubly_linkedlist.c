#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *new_node;
struct node *ptr;
struct node *head=NULL;
void create(int n)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=n;
}
void add_beg()
{
    int n;
    printf("Enter data : ");
    scanf("%d",&n);
    create(n);
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->prev=NULL;
    }
    else
    {
        new_node->next=head;
        new_node->prev=NULL;
    }
    head=new_node;
}
void addatlast()
{
    int n;
    printf("Enter data : ");
    scanf("%d",&n);
    create(n);
    for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->next=NULL;
}
void display()
{
    int s;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
int count()
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        c++;
    }
    return c;
}
void insertatany()
{
    int n,s;
    printf("Insert position to add node : ");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("NO NODE PRESENT!\n");
        printf("Add a first node\n");
        add_beg();
    }
    else if(n>count())
    {
        printf("Not enough node present!!\n");
    }
    else if(n==count())
    {
        addatlast();
    }
    else if(n==1)
    {
        add_beg();
    }
    else{
        printf("Enter data : ");
        scanf("%d",&s);
        create(s);
        ptr=head;
        for(int i=1;i<s-1;i++)
        {
            ptr=ptr->next;
        }
        new_node->next=ptr->next;
        new_node->prev=ptr;
        ptr->next=new_node;
        new_node->next->prev=new_node;
    }
}
int main()
{
    int ch;
    while(1)
    {
    printf("Enter 1 to add at beginning\nEnter 2 to add at last\nEnter 3 to display\nEnter 4 to add at any pos\nEnter 5 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:add_beg();
               break;
        case 2:addatlast();
               break;
        case 3:display();
               break;
        case 4:insertatany();
               break;
        case 5:exit(0);
        default:printf("ERROR\n");
    }
    }
}