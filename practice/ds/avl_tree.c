// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    printf("node %d inserted\n", node->key);
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    printf("Right rotate\n");
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    printf("%d->right = %d\n", (x != NULL) ? x->key : 0, (y != NULL) ? y->key: 0) ;
    x->right = y;
    printf("%d->left = %d\n", (y != NULL) ? y->key : 0, (T2 != NULL) ? T2->key: 0) ;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    printf("returning %d\n\n", x->key);
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    printf("Left rotate\n");
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    printf("%d->left = %d\n", (y != NULL) ? y->key : 0, (x != NULL) ? x->key: 0) ;
    y->left = x;
    printf("%d->right = %d\n", (x != NULL) ? x->key : 0, (T2 != NULL) ? T2->key: 0) ;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    printf("returning %d\n\n", y->key);
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    printf("current node %d, key %d\n", node->key, key);

    if (key < node->key) {
        printf("going left\n");
        node->left  = insert(node->left, key);
    }
    else if (key > node->key) {
        printf("going right\n");
        node->right = insert(node->right, key);
    }
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    printf("%d\'s height %d\n", node->key, node->height);
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    printf("balance %d\n", balance);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        printf("key %d, node->left->key %d\n",
               key, node->left->key);
        return rightRotate(node);
    }
 
    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        printf("key %d, node->right->key %d\n",
               key, node->right->key);
        return leftRotate(node);
    }
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        printf("key %d, node->left->key %d\n",
               key, node->left->key);
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        printf("key %d, node->right->key %d\n",
               key, node->right->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    printf("returning %d\n\n", node->key);
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  struct Node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Preorder ");
  preOrder(root);
  printf("\n");
 
  return 0;
}
