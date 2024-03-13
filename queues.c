#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int e[100];
    int front;
    int rear;
};
void initQ(struct queue *q);
void enqueue(struct queue *q,int,int );
int isFull(struct queue *q,int );
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
int size(struct queue *q);
int getFront(struct queue *q);
void display(struct queue *q);
main()
{
    int s,n;
    struct queue q;
    int ch,data;
    initQ(&q);
    printf("enter the valve of n \n");
    scanf("%d",&n);
    while(1)
    {
        printf("1:Enqueue");
        printf("2:Dequeue");
        printf("3;Size");
        printf("4:Get Front");
        printf("5:display");
        printf("6:Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if(isFull(&q,n))
                            {
                                printf("queue is full\n");
                            }
                            else
                            {
                                printf("Enter the value\n");
                                scanf("%d",&data);
                                enqueue(&q,data,n);
                            }
                            break;
            case 2:if(isEmpty(&q))
                            {
                                    printf("q is empty\n");
                            }
                            else
                            {
                                data=dequeue(&q);
                                printf("\n%d",data);
                            }
                            break;
            case 3:
                                if(isEmpty(&q))
                                {
                                    s=0;
                                }
                                else
                                    s=size(&q);
                                printf("Size=%d",s);
                                break;

                case 4: if(isEmpty(&q))
                                {
                                        printf("Q is Empty\n");
                                }
                                else
                                {
                                    data=getFront(&q);
                                    printf("&d",data);
                                }
                                break;
                case 5:
                    if(isEmpty(&q))
                    {
                        printf("Q is empty\n");
                    }
                    else
                        display(&q);
                        break;
                case 6:exit(0);
        }
    }
}
void initQ(struct queue *q)
{
    q->front=0;
    q->rear=-1;
}
void enqueue(struct queue *q,int data,int n)
{
    int i=0;
    for(i=0;i<1;i++)
    {
    q->rear++;
    q->e[i][q->rear]=data;
    }
}
int isFull(struct queue *q ,int n)
{
    int size=n-1;
    if(q->rear==size)
        return 1;
        return 0;
}
int dequeue(struct queue *q)
{
    int d;
    d=q->e[q->front];
    q->front++;
    return d;
}
int isEmpty(struct queue *q)
{
    if(q->rear < q->front)
    {
        return 1;
    }
    return 0;
}
int size(struct queue *q)
{
    return q->rear-q->front+1;
}
int getFront(struct queue *q)
{
    return q->e[q->front];
}
void display(struct queue *q)
{
    int i,j=0;
    for(i=q->front;j,i<=q->rear;i++,j++)
    {
        printf("%d\n",q->e[j][j]);
    }
}
