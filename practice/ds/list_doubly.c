#include <stdio.h>
#include <stdlib.h>

/* structure for DLL */
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} NODE;

/* function to create node */
NODE* create_node(int val)
{
    NODE *node = (NODE*) malloc (sizeof(NODE));
    node->data = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

/* function to add node at the front */
void push_node(NODE **head, int val)
{
    NODE *new_node;

    /* move the head ptr in call cases */
    if (*head == NULL) {
        *head = create_node(val);
        return;
    }

    new_node = create_node(val);
    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void reverse_list(NODE **head)
{
    NODE *cur = *head;
    NODE *next;

    while (cur != NULL) {
        next = cur->next;
        if (next == NULL)
            *head = cur;
        cur->next = cur->prev;
        cur->prev = next;
        cur = next;
    }
}

void deleteNode(NODE **head, int val)
{
    NODE *cur = *head;
    NODE *tmp = NULL;

    while (cur->next != NULL && cur->data != val)
        cur = cur->next;

    if (cur->next == NULL && cur->data != val) {
        printf("element not found\n");
        return;
    }

    tmp = cur;
    if (cur->prev == NULL)
        *head = (*head)->next;
    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(tmp);
}

void printList(NODE *head)
{
    if (head == NULL)
        printf("list is empty\n");

    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}


/* driver function */
int main()
{
    NODE *head = NULL;
    push_node(&head, 10);
    push_node(&head, 20);
    push_node(&head, 30);
    push_node(&head, 40);

    printList(head);
    reverse_list(&head);
    printList(head);
    deleteNode(&head, 40);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    deleteNode(&head, 20);
    printList(head);
    deleteNode(&head, 20);
    printList(head);
    deleteNode(&head, 30);
    printList(head);
    return (0);
}
