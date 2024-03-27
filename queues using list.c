#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int e;
    float price;
    char name[20];
    struct queue *next;

};
struct queue* getnode()
{
    struct queue *nw=(struct queue*)malloc(sizeof(struct queue));
    printf("enter details as e and price\n");
    scanf("%d%f%s",&nw->e,&nw->price,&nw->name);
    nw->next=NULL;
    return nw;

}
struct queue* add_pos(struct queue *head)
{
    int i;
    struct queue *nw=getnode();
    struct queue *cur=head;
    if(head==NULL)
    {
        head=nw;
        return head;
    }
    else
    {   nw->next=head;
        head=nw;
        return head;
    }

};

void display(struct queue *head)
{
    struct queue *cur=head;
    while(cur!=NULL)
    {
        printf("%d\t%f\t%s",cur->e,cur->price,cur->name);
        cur=cur->next;
        printf("\n");
    }
}

struct queue * delete_pos(struct queue *head)
{
    int i;
    struct queue *cur=head;
    struct queue *p=NULL;
    if(cur->next==NULL)
    {
        printf("%d\t%f\t%s",cur->e,cur->price,cur->name);
        return head;

    }
    for(i=0;cur->next!=NULL;i++)
    {
        printf("\n\njust\n\n");
        p=cur;
        cur=cur->next;

    }
    p->next=NULL;
    printf("%d\t%f\t%s",cur->e,cur->price,cur->name);
    free(cur);
    return head;
    }

main()
{
    int ch;
    struct queue *head=NULL;
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
            case 1:head=add_pos(head);
                   break;
            case 2:head=delete_pos(head);
                   break;
            case 3:display(head);
                   break;
        }
    }
}
