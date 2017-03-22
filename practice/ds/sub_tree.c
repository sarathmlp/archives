#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the given data
   and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}

bool areIdentical(struct node* T, struct node* S)
{
    if (T == NULL && S == NULL)
        return true;

    if (T == NULL || S == NULL)
        return false;

    return T->data == S->data && areIdentical(T->left, S->left) &&
        areIdentical(T->right, S->right);
}

bool isSubtree(struct node*  T, struct node* S )
{
    if (T == NULL || S == NULL)
        return false;

    if (areIdentical(T,S))
        return true;

    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
 
/* Driver program to test above function */
int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
 
    getchar();
    return 0;
}
