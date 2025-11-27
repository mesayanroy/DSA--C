#include<stdio.h>
#include<string.h>
#define MAX 100
char expr[MAX],bracket[MAX];int top=-1;
void push(char x)
{
    bracket[++top]=x;
}
char pop()
{
    return bracket[top--];
}
int check(char open,char close)
{
    return(open=='(' && close==')')||(open=='{' && close=='}')||(open=='[' && close==']');
}
int balanced()
{
    int i;char open;
    for(i=0;i<strlen(expr);i++)
    {
        if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
        push(expr[i]);
        else if(expr[i]==')'||expr[i]=='}'||expr[i]==']')
        {
            open=pop();
            if(!check(open,expr[i]))
            return 0;
        }
    }
    return (top==-1);
}
int main()
{
    printf("Enter expression : ");
    gets(expr);
    if(balanced())
    printf("Valid!");
    else
    printf("Not valid");
}