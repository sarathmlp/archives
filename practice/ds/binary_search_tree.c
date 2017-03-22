#include <stdio.h>
#include <stdlib.h>

/* structure of binary tree */
typedef struct node {
    int key;
    struct node* left;
    struct node* right;
}NODE;

/* function to create a new node */
NODE* createNode(int key)
{
    NODE* new_node = 
        (NODE*) malloc (sizeof(NODE));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

/* 
 * function to insert into binary search tree
 */
NODE* insert(NODE* node, int key)
{
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

/* to find the inorder successor */
NODE* findInSucc(NODE* node)
{
    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

/* to find the inorder predecessor */
NODE* findInPred(NODE* node)
{
    while (node->right != NULL) {
        node = node->right;
    }

    return node;
}

/* to delete a give node */
NODE* delete(NODE* node, int key)
{
    /* couldn't find the node to delete */
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
    /* node to delete is in left subtree */
        node->left = delete(node->left, key);
    } else if (key > node->key) {
    /* node to delete is in left subtree */
        node->right = delete(node->right, key);
    } else  {
        /* found the key */
        if (node->left == NULL) {
            NODE* tmp = node->right;
            free(node);
            return tmp;
        } else if (node->right == NULL) {
            NODE* tmp = node->left;
            free(node);
            return tmp;
        }

        /* node has two childern */
        NODE* tmp = findInSucc(node->right);
        node->key = tmp->key;
        node->right = delete(node->right, tmp->key);
    }
    return node;
}

NODE* search(NODE* node, int key)
{
    // Base Cases: node is null or key is present at node
    if (node == NULL || node->key == key)
        return node;

    // Key is smaller than node's key
    if (key < node->key)
        return (search(node->left, key));

    // Key is greater than node's key
    return (search(node->right, key));
}

void inorder_succ_pred(NODE* node, NODE** pred, NODE** succ, int key)
{
    NODE* tmp;

    if (node == NULL) {
        return;
    }

    if (key < node->key) {
        *succ = node;
        inorder_succ_pred(node->left, pred, succ, key);
    } else if (key > node->key) {
        *pred = node;
        inorder_succ_pred(node->right, pred, succ, key);
    } else {
        if (node->left != NULL) {
            tmp = findInPred(node->left);
            *pred = tmp;
        }
        if (node->right != NULL) {
            tmp = findInSucc(node->right);
            *succ = tmp;
        }
        return;
    }
}

/* function to do in-order traversal */
void inorder(NODE* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

/* driver function to test */
int main()
{
    NODE* pred = NULL;
    NODE* succ = NULL;

    NODE* root = insert(NULL, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 80);
    insert(root, 60);

    inorder(root);
    inorder_succ_pred(root, &pred, &succ, 45);
    if (pred) 
        printf("\npred %d\n", pred->key);
    if (succ)
        printf("\nsucc %d\n", succ->key);

	printf("\nDelete 20\n");
    root = delete(root, 20);
    inorder(root);
 
    printf("\nDelete 30\n");
    root = delete(root, 30);
    inorder(root);
 
    printf("\nDelete 50\n");
    root = delete(root, 50);
    inorder(root);

    return 0;
}
