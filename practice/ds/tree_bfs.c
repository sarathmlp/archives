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

int height(struct node *root)
{
    int lh;
    int rh;

    if (root == NULL) {
        return 0;
    } else {

        lh = height(root->left);
        rh = height(root->right);

        if (lh > rh)
            return (lh+1);
        else
            return (rh+1);
    }

}

void printGivenLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1) {
    // else {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

/* 
 * printLevelOrder - to go through each levels
 */
void printLevelOrder(struct node *root)
{
    int i;
    int h;
    
    h = height(root);
    for (i=1; i<=h; i++) {
        printGivenLevel(root, i);
    }
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

    printLevelOrder(root);
    printf("\n");

    return (0);
}
