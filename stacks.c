


#include<stdio.h>
struct stack
{
	int e[5];
	int top;
};
void init(struct stack *s);
int isFull(struct stack *s);
int isEmpty(struct stack *s);
void push(struct stack *s,int ele);
int pop(struct stack *s);
int peak(struct stack *s);
void display(struct stack *s);
int size(struct stack *s);
main()
{
    int si;
	struct stack s;
	int ch,ele;
	init(&s);
	while(1)
	{
		printf("1 to push\n 2 to pop 3 to peak 4 to dis 5 to size 6 to exit");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:if(isFull(&s))
                        {
                                printf("Stack is full\n");
                        }
                        else
                        {
                        printf("Enter a element to push\n");
                        scanf("%d",&ele);
                        push(&s,ele);
                        }
                        break;
            case 2:
                if(isEmpty(&s))
                {
                    printf("Stack is Empty\n");

                }
                else
                {
                   ele=pop(&s);
                    printf("\npop=%d\n",ele);
                }
                    break;isFull(&s);
            case 3:if(isEmpty(&s))
                            {
                                    printf("Stack is empty\n");
                            }
                            else
                            {
                                ele=peak(&s);
                                printf("Peak element is %d",ele);
                            }
                            break;
                case 4:display(&s);
                                break;
                case 5:si=size(&s);
                                printf("Size=%d",si);
                                break;
	}
}
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
int isFull(struct stack *s)
{
    if(s->top==4)
    {
        return 1;
    }
    else
        return 0;
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
int peak(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    return ele;
}
void display(struct stack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {
        printf("%d\n",s->e[i]);
    }
}
int size(struct stack *s)
{
    return (s->top+1);
}
