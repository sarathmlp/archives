#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
    int data;
    struct node *next;
};

/* function to insert a new_node in a list in sorted way.
   Note that this function expects a pointer to head node
   as this can modify the head of the input linked list */
/* Function to print nodes in a given linked list */
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* cur = *head_ref;

    if (cur == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    if (new_node->data < cur->data) {
        while (cur->next != *head_ref) {
            cur = cur->next;
        }
        cur->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    while (cur->next != *head_ref &&
           new_node->data > cur->next->data) {
        cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
}

void printList(struct node *start)
{
    struct node *temp;

    if(start != NULL)
    {
        temp = start;
        printf("\n");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;

    /* start with empty linked list */
    struct node *start = NULL;
    struct node *temp;

    /* Create linked list from the array arr[].
       Created linked list will be 1->2->11->12->56->90 */
    for (i = 0; i< 6; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        sortedInsert(&start, temp);
    }

    printList(start);

    return 0;
}
