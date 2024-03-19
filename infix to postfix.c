#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char e[30];
    int top;
};
void convInfixToPostfix(char []);
int isOperand(char );
int isOperator(char );
int pre(char );
void initstack(struct stack *);
void push(struct stack *,int );
int pop(struct stack *);
int isEmpty(struct stack *);
int peek(struct stack *s);
main()
{
    char infix[30];
    printf("Enter a infix exp\n");
    scanf("%s",infix);
    convInfixToPostfix(infix);
}
void convInfixToPostfix(char infix[])
{
    struct stack s;
    initstack(&s);
    char postfix[30];
    int i=0,j=0;
    for(i=0;infix[i];i++)
    {
        if(isOperand(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(isOperator(infix[i]))
        {
            if(isEmpty(&s))
            {
                push(&s,infix[i]);
            }
            else if(pre(infix[i])>pre(peek(&s)))
            {
                push(&s,infix[i]);
            }
            else
            {
                while(!isEmpty(&s)&&pre(infix[i])<=pre(peek(&s)))
                      {
                          postfix[j]=pop(&s);
                            j++;
                      }
                push(&s,infix[i]);
            }
        }
        else if(infix[i]=='(')
        {
            push(&s,infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!isEmpty(&s)&&peek(&s)!='(')
            {
                postfix[j]=pop(&s);
                j++;
            }
            pop(&s);
        }
    }
    while(!isEmpty(&s))
    {
        postfix[j]=pop(&s);
        j++;
    }
    postfix[j]='\0';
    printf("Postfix=%s",postfix);
}
int isOperand(char ch)
{
    if(ch>='A'&&ch<='Z')
    {
        return 1;
    }
    else if(ch>='a'&&ch<='z')
    {
        return 1;
    }
    else if (ch>='0'&&ch<='9')
    {
        return 1;
    }
    return 0;
}
int isOperator(char  ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$')
    {
        return 1;
    }
    return 0;
}
int pre(char ch)
{
    if(ch=='+'||ch =='-')
    {
        return 1;
    }
    else if(ch=='*'||ch=='/')
            return 2;
    else if(ch=='$')
        return 3;
    return -1;
}
void initstack(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,int ele)
{
    s->top++;
    s->e[s->top]=ele;
}
int pop(struct stack *s)
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
int peek(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    return ele;
}
