// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node *new_node = (struct node*)
        malloc(sizeof(struct node));

    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int findHeight(struct node *root)
{
    int lh, rh;

    if (root == NULL) {
        return 0;
    }

    lh = findHeight(root->left); /* line (1) */
    rh = findHeight(root->right); /* line (2) */

    return  MAX(lh, rh) + 1; /* line (3) */
}

/* 
 * driver function to test above code
 */
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);

    printf("%d\n", findHeight(root));

    return (0);
}
