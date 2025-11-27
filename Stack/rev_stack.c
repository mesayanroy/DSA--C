#include<stdio.h>
#include<string.h>
#define MAX 100
char stk[MAX];int top=-1;
void push(char ptr)
{
    stk[++top]=ptr;
}
int pop()
{
    return stk[top--];
}
int main()
{
    char str[MAX];int i;
    printf("Enter name : ");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    printf("String before reverse : ");
    puts(str);
    printf("String after reverse : ");
    for(i=0;i<strlen(str);i++)
    {
        str[i]=pop();
    }
    puts(str);
}