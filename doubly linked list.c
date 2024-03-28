#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[30];
    int rn;
    int sem;
    char dept[30];
    struct node *next;
    struct node *prev;
};
struct node * addpos(struct node *,int);
struct node * deletepos(struct node *,int);
struct node * getnode();
void display(struct node *);
void DisplayAll(struct node *);
struct node * deletev(struct node *,char []);
main()
{
    int ch,pos;
    struct node *head=NULL;
    char n[30];
    while(1)
        {
        printf("Enter 1: To insert the node at specified position\nEnter 2: To delete the node at specified position\nEnter 3: To display\n4: To delete 1st occurance based on value\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the position\n");
                   scanf("%d",&pos);
                   head=addpos(head,pos);
                   break;
            case 2:printf("Enter the position\n");
                   scanf("%d",&pos);
                   if(head!=NULL)
                   {
                       head=deletepos(head,pos);
                   }
                   else
                   {
                     printf("List is empty\n");
                   }
                   break;
            case 3:if(head==NULL)
                   {
                     printf("List is empty\n");
                     break;
                   }
                    DisplayAll(head);
                    break;
            case 4:printf("Enter the name to be searched\n");
                   scanf("%s",n);
                   head=deletev(head,n);
                   break;

        }
    }
}
struct node * addpos(struct node *head,int pos)
{
     int i;
     struct node *cur=head,*newnode=getnode();
     if(head==NULL)
     {
         head=newnode;
         return head;
     }
     if(pos<=0)
     {
         newnode->next=head;
         newnode->prev=head->prev;
         head->prev->next=newnode;
         head->prev=newnode;
         head=newnode;
         return head;
     }
     for(i=0;i<pos-1 && cur->next!=head;i++)
     {
         cur=cur->next;
     }
     newnode->next=cur->next;
     newnode->prev=cur;
     cur->next=newnode;
     newnode->next->prev=newnode;
     return head;
}
struct node * getnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter name:");
    scanf("%s",newnode->name);
    printf("Enter roll number:");
    scanf("%d",&newnode->rn);
    printf("Enter semester:");
    scanf("%d",&newnode->sem);
    printf("Enter department:");
    scanf("%s",newnode->dept);
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}
struct node * deletepos(struct node *head,int pos)
{
    int i;
    struct node *cur=head,*p=NULL;
    if(head->next==head)
    {
        display(head);
        free(head);
        return NULL;
    }
    if(pos<=0)
    {
        head=head->next;
        head->prev=cur->prev;
        cur->prev->next=head;
        display(cur);
        free(cur);
        return head;
    }
    for(i=0;i<pos && cur->next!=head;i++)
    {
  cur=cur->next;
    }
    p->next=cur->next;
    cur->next->prev=p;
    display(cur);
    free(cur);
    return head;
}
void display(struct node *head)
{
    printf("NAME:%s\nROLL NO:%d\nSEM:%d\nDEPARTMENT:%s\n",head->name,head->rn,head->sem,head->dept);
}
void DisplayAll(struct node *head)
{
    struct node *cur=head;
    do
    {
       printf("NAME:%s\nROLL NO:%d\nSEM:%d\nDEPARTMENT:%s\n",cur->name,cur->rn,cur->sem,cur->dept);
       cur=cur->next;
    }while(cur!=head);
}
struct node * deletev(struct node *head,char n[])
{
    struct node *cur=head,*p=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    if(strcasecmp(head->name,n)==0)
    {
        head=head->next;
        head->prev=cur->prev;
        cur->prev->next=head;
        display(cur);
        free(cur);
        return head;
    }
    cur=head->next;
    p=head;
    while(p->next!=head)
    {
        if(strcasecmp(cur->name,n)==0)
        {
            p->next=cur->next;
            cur->next->prev=p;
            display(cur);
            free(cur);
                    return head;
        }
        p=cur;
        cur=cur->next;
    }
    return head;
};
