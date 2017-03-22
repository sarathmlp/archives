#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to remove loop. Used by detectAndRemoveLoop() */
void removeLoop(struct node *, struct node *);
 
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct node *list)
{
    struct node *slowptr = list;
    struct node *fastptr = list;
    struct node *cur;
    int count = 0;

    while (fastptr != NULL && fastptr->next != NULL) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr) {
            /* loop detected */
            break;
        }
    }

    if (fastptr == NULL) {
        printf("no loop detected\n");
        return 1;
    }

    cur = slowptr;
    while (cur->next != slowptr) {
        count++;
        cur = cur->next;
    }

    cur = list;
    while (count--) {
        cur = cur->next;
    }

    while (cur->next != list) {
        cur = cur->next;
        list = list->next;
        printf("loop\n");
    }

    cur->next = NULL;

    return 0;
}
#if 0
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct node *list)
{
    struct node *slowptr = list;
    struct node *fastptr = list;

    while (fastptr != NULL && fastptr->next != NULL) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr) {
            /* loop detected */
            removeLoop(list, slowptr);
            return 1;
        }
    }
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct node *head, struct node *loopnode)
{
    struct node *ptr1 = head;
    struct node *ptr2;

    while (1) {
        ptr2 = loopnode;
        while (ptr2->next != loopnode && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }
        if (ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;

}
#endif
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
struct node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Drier program to test above function*/
int main()
{
    struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}
