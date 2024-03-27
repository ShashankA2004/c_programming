#include<stdio.h>
#define SIZE 20

typedef struct Stack
{
    int top;
    int data[SIZE];
}*stack;

stack initial()
{
   stack ptr;
   ptr=(stack*)malloc(sizeof(struct Stack));
   if(ptr==NULL)
   {
       printf("Memory not allocated\n");

   }
   ptr->top=-1;
   return ptr;
}

int isEmpty(stack ptr)
{
    return (ptr->top==-1);
}

int isFull(stack ptr)
{
    return (ptr->top==SIZE-1);
}

stack PUSH(stack ptr,int item)
{
    if(isFull(ptr))
    {
        printf("Overflow!!\n");
        return;
    }
    else
    {
        ptr->top++;
        ptr->data[ptr->top]=item;
        return ptr;
    }

}

int POP(stack ptr)
{
   if(isEmpty(ptr))
   {
       printf("Stack underflow!!");
       return;
   }
   else
   {
       ptr->top--;
       return ptr->data[ptr->top+1];
   }
}

int peek(stack ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack empty\n");
        return;
    }
    else
    return(ptr->data[ptr->top]);
}

void display(stack ptr)
{
    int i;
    for(i=0;i<=ptr->top;i++)
    {
        printf("%d ",ptr->data[i]);
    }
    printf("\n");
}

int main()
{
    stack ptr=initial();
    int choice;
    int item;
    while(1)
    {
        printf("1:PUSH\n2:POP\n3:Display\n4:Peek\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter item to be pushed\n");
            scanf("%d",&item);
            ptr=PUSH(ptr,item);
        }
        else if(choice==2)
        {
            item=POP(ptr);
            printf("%d is popped\n",item);
        }
        else if(choice==3)
        {
            display(ptr);
        }
        else if(choice==4)
        {
            printf("%d\n",peek(ptr));
        }
        else
        {
            printf("Invalid!! Try again\n");
        }
    }

}


