#include<stdio.h>
#include<stdlib.h>
 
/* A Doubly Linked List node that will also be used as a tree node */
struct Node
{
    int data;
 
    // For tree, next pointer can be used as right subtree pointer
    struct Node* next;
 
    // For tree, prev pointer can be used as left subtree pointer
    struct Node* prev;
};
 
// A utility function to count nodes in a Linked List
int countNodes(struct Node *head);
 
struct Node* sortedListToBST(struct Node **head_ref, int n)
{
    if (n <= 0)
        return NULL;

    struct Node* left = sortedListToBST(head_ref, n/2);

    struct Node* root = *head_ref;
    root->prev = left;
    *head_ref = (*head_ref)->next;
    root->next = sortedListToBST(head_ref, (n - (n/2) - 1));

    return root;
}
/* UTILITY FUNCTIONS */
/* A utility function that returns count of nodes in a given Linked List */
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preOrder(node->prev);
    preOrder(node->next);
}
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 7->6->5->4->3->2->1 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("Given Linked List\n");
    printList(head);
 
    /* Convert List to BST */
    struct Node *root = sortedListToBST(&head, countNodes(head));
    printf("\n PreOrder Traversal of constructed BST \n ");
    preOrder(root);
 
    return 0;
}
