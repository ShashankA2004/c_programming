#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define count 10;
struct Node {
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct Node* insert(struct Node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a binary search tree and a key, this function deletes the key and returns the new root */
struct Node* deleteNode(struct Node* root, int k)
 {
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (k < root->key) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (k > root->key) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL) {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    struct Node* succParent = root;
    struct Node* succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->key = succ->key;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    free(succ);
    return root;
}

void print2du(struct Node *root,int space)
{
    if(root==NULL)
        return;
        space+=count;
        print2du(root->right,space);
        printf("\n");
        int i=count;
        while(i<space)
        {
            printf(" ");
            i++;
        }
            printf("%d\n",root->key);
            print2du(root->left,space);
}

void print2d(struct Node *root)
{
    print2du(root,0);
}

// Driver Code
int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Original BST: ");
    inorder(root);
    print2d(root);

    printf("\n\nDelete Node with single child: 70\n");
    root = deleteNode(root,50);
    printf("Modified BST tree after deleting single child Node:\n");
    inorder(root);

    print2d(root);
    return 0;
}
