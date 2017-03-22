#include <stdio.h>
#include <stdlib.h>
 
struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};

void connectRec(struct node* root)
{
    if (root == NULL)
        return;

    if (root->left)
        root->left->nextRight = root->right;
    if (root->right)
        root->right->nextRight = (root->nextRight) ?
            root->nextRight->left : NULL;

    connectRec(root->left);
    connectRec(root->right);
}

void connect(struct node* root)
{
    root->nextRight = NULL;
    connectRec(root);
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \
    3     9
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right  = newnode(9);
  root->right->left  = newnode(7);
  root->right->right  = newnode(6);
 
  // Populates nextRight pointer in all nodes
  connect(root);
 
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->left->right->data,
        root->left->right->nextRight? root->left->right->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->right->left->data,
        root->right->left->nextRight? root->right->left->nextRight->data: -1);

  printf("nextRight of %d is %d \n", root->right->right->data,
        root->right->right->nextRight? root->right->right->nextRight->data: -1);
 
  return 0;
}
