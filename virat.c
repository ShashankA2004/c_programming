#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define count 10;
struct node
{
  int data;
  struct node *left,*right;
};

struct node *newNode (int item)
{
  struct node *temp= (struct node *) malloc (sizeof (struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

void print2du(struct node *root,int space)
{
    if(root==NULL)
        return;
        space+=count;
        print2du(root->right,space);
        printf("\n");
        for(int i=count;i<space;i++)
            printf(" ");
            printf("%d\n",root->data);
            print2du(root->left,space);
}

void print2d(struct node *root,int space)
{
    print2d(root,0);
}

int main()
{
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);

     root->left->left->left=newnode(8);
     root->left->left->right=newnode(9);
     root->left->right->left=newnode(10);
     root->left->right->right=newnode(11);
     root->right->left->left=newnode(10);
     root->right->left->right=newnode(11);
     root->right->right->left=newnode(10);
     root->right->right->right=newnode(11);
}

