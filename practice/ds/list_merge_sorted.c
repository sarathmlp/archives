/* C/C++ program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

void modeNode(struct node** dest, struct node** src)
{
    *dest = *src;
    *src = (*src)->next;
    (*dest)->next = NULL;
}

#if 0
struct node* SortedMerge(struct node *a, struct node *b)
{
    struct node dummy;
    dummy.next = NULL;

    struct node *tail = &dummy;

    while (1) {
        if (a == NULL) {
            tail->next = b;
            break;
        }
        if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data) {
            modeNode(&(tail->next), &a);
        } else {
            modeNode(&(tail->next), &b);
        }
        tail = tail->next;
    }
    return dummy.next;
}

struct node* SortedMerge(struct node *a, struct node *b)
{
    struct node *result = NULL;
    struct node **tail = &result;

    while (1) {
        if (a == NULL) {
            *tail = b;
            break;
        }
        if (b == NULL) {
            *tail = a;
            break;
        }
        if (a->data <= b->data) {
            modeNode(tail, &a);
        } else {
            modeNode(tail, &b);
        }
        tail = &((*tail)->next);
    }
    return result;
}
#endif 
struct node* SortedMerge(struct node* a, struct node* b) 
{
    struct node* result = NULL;

    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    } else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

/* Function to insert a node at the beginging of the
   linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL) {
        if (node->next == NULL) {
            printf("%d", node->data);
        } else {
            printf("%d->", node->data);
        }
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;

    /* Let us create two sorted linked lists to test
       the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    printList(a);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    printList(b);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
