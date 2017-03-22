// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

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

void print_preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ",root->key);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(struct node *root)
{
    if (root == NULL)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ",root->key);
}

void print_inorder(struct node *root)
{
    if (root == NULL)
        return;

    print_inorder(root->left);
    printf("%d ",root->key);
    print_inorder(root->right);
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

    print_preorder(root);
    printf("\n");
    print_inorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");

    return (0);
}
