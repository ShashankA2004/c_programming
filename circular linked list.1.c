#include<stdio.h>
#include<stdlib.h>
struct song
{
    char song_n[30];
    char singer[30];
    char movie[50];
    int d;
    struct song *next;
};
struct song * add(struct song*,int);
struct song * delete_(struct song*,int);
void display(struct song *);
struct song * getnode();
void duration(struct song*);
void movie(struct song*,char[]);
struct song * d_singer(struct song *,char []);
struct song * merge(struct song *,struct song *);
struct song * dur(struct song *,int);
struct song * createlist(struct song *);
struct song * addnode(struct song *tail);
struct song * addbeg();
struct song * duration_(struct song *tail,int d1);
main()
{
    struct song *tail=NULL,*tail1=NULL,*New=NULL;
    int ch,pos;
      char m[50];
    while(1)
    {
        printf("\nENTER\n1:To add a song at specified position\n2:To delete a song from a specified position\n3:To display\n4:To calculate the duration of playlist\n5:To display songs of particular movie\n6:To delete all the songs of particular singer\n7:To calculate the duration of all songs\n8:To create new list and merge both the list\n9:To delete all the songs whose duration is more than specified duration\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the position\n");
                   scanf("%d",&pos);
                   tail=add(tail,pos);
                   break;
            case 2:if(tail==NULL)
                   {
                      printf("List is empty\n");
                   }
                   else
                   {
                      printf("Enter the position\n");
                      scanf("%d",&pos);
                      tail=delete_(tail,pos);
                   }
                   break;
            case 3:display(tail);
                   break;
            case 4:duration(tail);
                   break;
            case 5:printf("Enter the movie name\n");
                   scanf("%s",m);
                   movie(tail,m);
                   break;
            case 6:printf("Enter the singer name\n");
                   scanf("%s",m);
                   tail=d_singer(tail,m);
                   break;
            case 7:printf("Enter the duration\n");
                   scanf("%d",&pos);
                   tail=dur(tail,pos);
                   break;
            case 8:printf("Creating new list");
                   tail1 = createlist(tail1);
                   New = merge(tail,tail1);
                   printf("New list\n");
                   display(New);
                   break;
            case 9:scanf("%d",&pos);
                   tail=duration_(tail,pos);
                    break;
        }
    }
}
struct song * add(struct song *tail,int pos)
{
    struct song *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    if(pos<=0)
    {
        newnode->next=tail->next;
        tail->next=newnode;
        return tail;
    }
    struct song *cur=tail->next;
    int i;
    for(i=0;i<pos-1&&cur!=tail;i++)
    {
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    if(cur==tail)
    {
        tail=newnode;
    }
    return tail;
}
struct song * delete_(struct song *tail,int pos)
{
    struct song *cur=tail->next,*pre=NULL;
    int i;
    if(tail==cur)
    {
        printf("Deleted data information:");
        display(cur);
        free(cur);
        tail=NULL;
        return tail;
    }
    if(pos<=0)
    {
        tail->next=cur->next;
        printf("Deleted data information:");
        display(cur);
        free(cur);
        return tail;
         return tail;
    }
    for(i=0;i<pos && cur!=tail;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    printf("Deleted data information:");
    display(cur);
    if(cur==tail)
    {
        tail=pre;
    }
    free(cur);
    return tail;
}
void display(struct song *tail)
{
    if(tail==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    struct song *cur=tail->next;
    do
    {
        printf("\nSong :%s",cur->song_n);
        printf("\nMovie:%s",cur->movie);
        printf("\nSinger:%s",cur->singer);
        printf("\nDuration:%d",cur->d);
        cur=cur->next;
    }while(cur!=tail->next);
}
struct song* getnode()
{
    struct song *newnode=(struct song *)malloc(sizeof(struct song));
    printf("Enter the song name,movie,singer and duration in minutes and seconds\n");
    scanf("%s%s%s%d",newnode->song_n,newnode->movie,newnode->singer,&newnode->d);
    newnode->next=newnode;
}
void duration(struct song*tail)
{
    if(tail==NULL)
    {
       printf("List is empty\n");
        return 0;
    }
    struct song * cur=tail->next;
    int m=0;
    do
    {
        m=m+cur->d;
        cur=cur->next;
    }while(cur!=tail->next);
    printf("Total duration:%d",m);
}
void movie(struct song *tail,char m[])
{
    if(tail==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    struct song *cur=tail->next;
    do
    {
        if(strcasecmp(m,cur->movie)==0)
        {
            display_(cur);
        }
        cur=cur->next;
    }while(cur!=tail->next);
}
void display_(struct song *tail)
{
    struct song *cur=tail;
    printf("\nSong :%s",cur->song_n);
    printf("\nMovie:%s",cur->movie);
    printf("\nSinger:%s",cur->singer);
    printf("\nDuration:%d",cur->d);
}
struct song * d_singer(struct song *tail,char m[])
{
   if(tail==NULL)
   {
       printf("List is empty\n");
       return 0;
   }
   struct song *cur=tail->next,*pre=NULL;
   do
   {
       if(strcasecmp(cur->singer,m)==0)
       {
           if(pre!=NULL)
           {
               pre->next=cur->next;
           }
            else
           {
               tail->next=cur->next;
           }
           display_(cur);
           if(tail==cur)
           {
               tail=pre;
           }
           free(cur);
           return tail;
       }
       pre=cur;
       cur=cur->next;
    }while(cur!=tail->next);
}
struct song * dur(struct song *tail,int duration)
{
   if(tail==NULL)
   {
       printf("List is empty\n");
       return 0;
   }
   struct song * cur=tail->next,*pre=NULL;
   do
   {
       if(cur->d>duration)
       {
           if(pre!=NULL)
           {
               pre->next=cur->next;
           }
           else
           {
               tail->next=cur->next;
           }
           display_(cur);
           if(cur==tail)
           {
               tail=pre;
           }
           free(cur);
           return tail;
       }
       pre=cur;
       cur=cur->next;
   }while(cur!=tail->next);
}
struct song * createlist(struct song *tail)
{int n,i;
    char song_n[30];
    char singer[30];
    char movie[50];
    int d;
    printf("\nEnter the no.of node\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("List is empty\n");
        return 0;
    }
    printf("Enter element 1:");
    tail=addbeg();
    for(i=1;i<n;i++)
    {
        printf("Enter element %d",i+1);
        tail=addnode(tail);
    }
    return tail;
}
struct song * addnode(struct song *tail)
{
    struct song * newnode=(struct song *)malloc(sizeof(struct song));
    scanf("%s%s%s%d",newnode->song_n,newnode->singer,newnode->movie,&newnode->d);
    newnode->next = newnode;
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
    return tail;
}
struct song * addbeg()
{
    struct song *newnode=malloc(sizeof(struct song));
    scanf("%s%s%s%d",newnode->song_n,newnode->singer,newnode->movie,&newnode->d);
    newnode->next=newnode;
    return newnode;
}
struct song * merge(struct song *tail,struct song *tail1)
{
    struct song *pre=NULL;
    if(tail==NULL)
        return tail1;
    if(tail1==NULL)
        return tail;
    pre=tail->next;
       tail->next=tail1->next;
    tail1->next=pre;
    return tail1;
}
struct song * duration_(struct song *tail,int d1)
{
    if(tail==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    struct song *cur=tail->next;
    int i=0,j=0,k=0;
    int a[50];
    do
    {
        if(cur->d>d1)
        {
            a[i]=j;
            i++;
        }
        j++;
        cur=cur->next;
    }while(cur!=tail->next);
    for(k=0;k<i;k++)
    {
        printf("\n*%d*\n",a[k]);
    }
    for(k=0;k<i;k++)
    {
        tail=delete_(tail,a[k]);
    }
    return tail;
}
