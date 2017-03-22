#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int maxVal(struct node* node)
{
    int leftMax;
    int rightMax;

    if (node == NULL)
        return 0;

    leftMax = maxVal(node->left);
    rightMax = maxVal(node->right);

    if (leftMax == 0 && rightMax == 0)
        return node->data;
    else
        return (leftMax > rightMax) ? leftMax : rightMax;
}

int isBST(struct node* node)
{
  if (node == NULL) 
    return 1; 
     
  /* false if left is > than node */
  if (node->left != NULL && maxVal(node->left) > node->data) 
    return 0; 
     
  /* false if right is < than node */
  if (node->right != NULL && maxVal(node->right) < node->data) 
    return 0; 
   
  /* false if, recursively, the left or right is not a BST */
  int ret1 = isBST(node->left); /* line (1) */
  int ret2 = isBST(node->right); /* line (2) */

  if (!ret1 || !ret2) 
    return 0; 
     
  /* passing all that, it's a BST */
  return 1; 
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3); 

    printf("%d\n", maxVal(root));

    if(isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");

    return 0;
}  
