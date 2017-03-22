// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;
};

struct node* newnode(int key)
{
    struct node* newnode = NULL;
    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;

    return newnode;
}
 
struct node* insert(struct node* root, int data)
{
    if (root == NULL) {
        root = newnode(data);
        return root;
    }
    if (data < root->key) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert (root->right, data);
    }
    // return root;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d-", root->key);
        inorder(root->right);
    }
}

struct node* minVal(struct node* root)
{
    while (root->left) {
        root = root->left;
    }

    return root;
}

struct node* deleteNode(struct node* root, int val)
{
    if (root == NULL) {
        return NULL;
    }

    if (val < root->key) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->key) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL) {
            struct node *tmp = root->right;
            free (root);
            return tmp;
        } else if (root->right == NULL ) {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }

        struct node* tmp = minVal(root->right);
        root->key = tmp->key;
        root->right = deleteNode(root->right, tmp->key);
    }
    return root;
}

 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}
