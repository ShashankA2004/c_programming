#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int e[30];
    int top;
};
int evapostfix(char[]);
void initstack(struct stack *);
int isoperand(char );
void push(struct stack *,int );
int pop(struct stack *);
main()
{
    char postfix[30];
    int r;
    printf("Enter postfix\n");
    scanf("%s",postfix);
    r=evapostfix(postfix);
    printf("Result=%d",r);
}
int evapostfix(char postfix[30])
{
    int k;
    struct stack s;
    initstack(&s);
    int i,op1,op2,r;
    for(i=0;postfix[i];i++)
    {
        if(isoperand(postfix[i]))
        {
            push(&s,postfix[i]-48);
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            switch(postfix[i])
            {
                case '+':r=op1+op2;
                          push(&s,r);
                          break;
                case '-':r=op1-op2;
                          push(&s,r);
                          break;
                case '*':r=op1*op2;
                          push(&s,r);
                          break;
                case '/':r=op1/op2;
                          push(&s,r);
                          break;
                case '$':r=pow(op1,op2);
                          push(&s,r);
                          break;

            }
        }
    }
    k=pop(&s);
     return k;

}


int isoperand(char ch)
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
void init(struct stack *s)
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
void initstack(struct stack *s)
{
	s->top=-1;
}

