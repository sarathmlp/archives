#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>

std::stack<int> st;

/* structure of binary tree */
typedef struct node {
    int key;
    struct node* left;
    struct node* right;
}Node;

/* function to create a new node */
Node* createNode(int key)
{
    Node* new_node = 
        (Node*) malloc (sizeof(Node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

/* 
 * function to insert into binary search tree
 */
Node* insert(Node* node, int key)
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

void push(Node* root)
{
    if (root == NULL)
        return;

    push(root->left);
    st.push(root->key);
    push(root->right);
}

int kth_smallest(Node* root, int k)
{
    int i;
    int ret;

    push(root);

    for (i=st.size(); i > k; i--) {
        ret = st.top();
        std::cout << "pop" << ret << std::endl;
        st.pop();
    }

    return ret;
}

/* function to do in-order traversal */
void inorder(Node* root)
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
    Node* pred = NULL;
    Node* succ = NULL;

    Node* root = insert(NULL, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 80);
    insert(root, 60);

    inorder(root);
    printf("\n");

    printf("4 %d\n", kth_smallest(root,4));
    return 0;
}
