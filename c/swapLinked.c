/* This program swaps the nodes of linked list rather
   than swapping the field from the nodes.*/

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct node
{
    int data;
    struct node *next;
};

/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node **head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y) return;

    // Search for x (keep track of prevX and CurrX
    struct node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y (keep track of prevY and CurrY
    struct node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY; 

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;

    // Swap next pointers
    //struct node *temp = currY->next;
    //currY->next = currX->next;
    //currX->next = temp;
    struct node *temp = currX;
    currX->next = currY->next;
    currY->next = temp;
}

/* Function to add a node at the begining of List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

void reverse(struct node** head)
{
    struct node *prev, *cur, *tmp;
    
    prev = NULL;
    cur = *head;
    tmp = cur->next;

    while (cur->next != NULL) {
        cur->next = prev;
        prev = cur;
        cur = tmp;
        tmp = tmp->next;
    }
    cur->next = prev;
    *head = cur;
}

void reverse_rec(struct node** head, struct node* cur, struct node* prev,
                 struct node* tmp)
{
    if (cur->next == NULL) {
        cur->next = prev;
        *head = cur;
        return;
    }
    cur->next = prev;
    reverse_rec(head, tmp, cur, tmp->next);
}

/* Druver program to test above function */
int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
       1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("Linked list before calling swapNodes(): ");
    printList(start);

    swapNodes(&start, 3, 4);

    printf("Linked list after calling swapNodes(): ");
    printList(start);

    reverse(&start);
    printList(start);

    reverse_rec(&start, start, NULL, start->next);
    printList(start);
    return 0;
}

