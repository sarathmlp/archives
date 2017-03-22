#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* function prototypes */
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node** source,
          struct node** frontRef, struct node** backRef);
 
void MergeSort(struct node** head)
{
    struct node* a;
    struct node* b;

    if (*head == NULL || (*head)->next == NULL)
        return;

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *head = SortedMerge(a, b);
}

void FrontBackSplit(struct node** head, struct node** a,
                    struct node** b)
{
    struct node* slow_ptr = *head;
    struct node* fast_ptr = (*head)->next;

    if (*head == NULL || (*head)->next == NULL) {
        *a = *head;
        *b = NULL;
    } else {

        while (fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr != NULL) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
        }
        *a = *head;
        *b = slow_ptr->next;
        slow_ptr->next = NULL;
    }
}

struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node* res = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->data < b->data) {
        res = a;
        res->next = SortedMerge(a->next, b);
    } else {
        res = b;
        res->next = SortedMerge(a, b->next);
    }

    return res;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Function to insert a node at the beginging of the linked list */
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

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* res = NULL;
    struct node* a = NULL;

    /* Let us create a unsorted linked lists to test the functions
       Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5); 
    push(&a, 20);
    push(&a, 3);
    push(&a, 2); 

    /* Sort the above created Linked List */
    MergeSort(&a);

    printf("\n Sorted Linked List is: \n");
    printList(a);           

    return 0;
}
