#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left, *right;
};

struct node *newNode (int item)
{
  struct node *temp= (struct node *) malloc (sizeof (struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder (struct node *root)
{
  if (root != NULL)
    {
      inorder (root->left);
      printf ("%d ", root->data);
      inorder (root->right);
    }
}

void postorder (struct node *root)
{
  if (root != NULL)
    {
      postorder (root->left);
      postorder (root->right);
      printf ("%d ", root->data);
    }
}


// Here we print the inorder recursively
void preorder (struct node *root)
{
  if (root != NULL)
    {
      printf ("%d ", root->data);
      preorder (root->left);
      preorder (root->right);
    }
}

struct node *insert (struct node *node, int data)
{

  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else if (data > node->data)
    node->right = insert (node->right, data);

  return node;
}

int main ()
{
  struct node *root = NULL;
  root = insert (root, 9);
  insert (root, 7);
  insert (root, 50);
  insert (root, 8);
  insert (root, 14);
  insert (root, 55);
  insert (root, 16);

  printf ("The postorder is :\n");
  preorder (root);

  printf ("\n\n\nThe postorder is :\n");
  postorder (root);

  printf ("\n\n\nThe inorder is :\n");
  inorder (root);


  return 0;
}

