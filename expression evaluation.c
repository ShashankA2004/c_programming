#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char e[30];
    int top;
};
void initstack(struct stack *);
void push(struct stack *,char );
char pop(struct stack *);
main()
{
    int r;
    char exp[30];
    printf("Enter a exp\n");
    scanf("%s",exp);
    r=balpar(exp);
    if(r==0)
    {
        printf("not balanced");
    }
    else
    {
         printf("balanced");
    }
}
int balpar(char exp[])
{
    int i;
    struct stack s;
    char ch;
    initstack(&s);
    for(i=0;exp[i];i++)
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
            {
                push(&s,exp[i]);
            }
            else if(exp[i]==']'||exp[i]==')'||exp[i]=='}')
            {
                ch=pop(&s);
                if(exp[i]==')'&&ch!='(')
                                      {
                                          return 0;
                                      }
                    if(exp[i]==']'&&ch!='[')
                       {
                           return 0;
                       }
                        if(exp[i]=='}'&&ch!='{')
                       {
                           return 0;
                       }
            }
    }
    if(isEmpty(&s))
    {
        return 1;
    }
    return 0;
}

void initstack(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,char ele)
{
    s->top++;
    s->e[s->top]=ele;
}
char pop(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    s->top--;
    return ele;
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
