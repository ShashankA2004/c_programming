#include<stdio.h>
#include<stdlib.h>
struct book
{
    char name[20];
    float price;
    int yop;
    int n_pages;
    int n_authors;
    char na_authors;
    struct book*next;
};
struct node *getnode();
struct book * add_pos(struct book *,int);
struct book * delete_pos(struct book *,int);
void display(struct node *book);
main()
{
    struct book *head=NULL;
    int ch,n,pos,count=0;
    while(1)
    {
        printf("enter 1 to add at beg 2 add at end\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter position\n");
                   scanf("%d",&pos);
                   head=add_pos(head,pos);
                   break;
            case 2:printf("enter position\n");
                   scanf("%d",&pos);
                   delete_pos(head,pos);
                   break;

            case 3:display(head);
                   break;
        }
    }

}
struct node *getnode()
{
    struct book *nw=(struct book*)malloc(sizeof(struct book));
    printf("enter details as name,cost,pages");
    scanf("%s%f%d",nw->name,&nw->price,&nw->n_pages);
    nw->next=NULL;
    return nw;

}
struct book * add_pos(struct book *head,int pos)
{
    int i;
    struct book *nw=getnode();
    struct book *cur=head;
    if(head==NULL||pos<=0)
    {
        nw->next=head;
        head=nw;
        return head;
    }
    for(i=0;i<pos-1&&cur->next!=NULL;i++)
    {
       cur=cur->next;
    }
     nw->next=cur->next;
        cur->next=nw;
        return head;

};

struct book * delete_pos(struct book *head,int pos)
{
    int i;
    struct book *cur=head;
    struct book *p=NULL;
    if(pos<=0||head==NULL)
    {
        head=head->next;
        printf("%s%f%d",cur->name,cur->price,cur->n_pages);
        free(cur);
        return head;
    }
    for(i=0;i<pos&&cur->next!=NULL;i++)
    {
        p=cur;
        cur=cur->next;

    }
    p->next=cur->next;
    printf("%s%f%d",cur->name,cur->price,cur->n_pages);
    free(cur);
    return head;
    }

void display(struct node *head)
{
    struct book *cur=head;
    while(cur!=NULL)
    {
        printf("%s\t%f\t%d\n",cur->name,cur->price,cur->n_pages);
        cur=cur->next;
    }
}

