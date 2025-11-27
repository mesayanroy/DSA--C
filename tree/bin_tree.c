#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}
struct node* create(int n)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=n;
    return new_node;
}
struct node* insert(struct node *current,int data)
{
    if(current==NULL)
    {
        return create(data);
    }
    if(data>current->data)
    current->right=insert(current->right,data);
    else
    current->left=insert(current->left,data);
    return current;
}
int main()
{
    int ch;
    while(1)
    {
        printf("Enter 1 to insert data\n");
        printf("Enter 2 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number : ");
                   scanf("%d",&ch);
                   root=insert(root,ch);
                   break;
            case 2:printf("Exiting....");
                   delay(1);
                   exit(0);
        }
    }
}