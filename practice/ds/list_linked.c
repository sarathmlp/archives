#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* create_node(int val);
void display_list(NODE* head);
void append(NODE** head, int val);
void destroy_list(NODE* head);
int length(NODE* head);
void swap_nodes(NODE** head, int first, int second);
void delete_node(int val, NODE** head);
void insert_node(int pos, int val, NODE** head);
void print_middle(NODE* head);
void reverse_list(NODE** head);
void reverse_rec(NODE** head, NODE* cur, NODE* prev, NODE* tmp);

int main()
{
    NODE* head = NULL;
    append(&head, 1);
    display_list(head);
    print_middle(head);
    append(&head, 2);
    display_list(head);
    print_middle(head);
    append(&head, 3);
    print_middle(head);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    display_list(head);
    print_middle(head);
    append(&head, 7);
    display_list(head);
    print_middle(head);

    printf("length: %d\n", length(head));
    swap_nodes(&head, 3, 4);
    display_list(head);
    swap_nodes(&head, 1, 6);
    display_list(head);
    swap_nodes(&head, 1, 6);
    display_list(head);
    swap_nodes(&head, 5, 6);
    display_list(head);
    swap_nodes(&head, 2, 1);
    display_list(head);

    delete_node(2, &head);
    display_list(head);

    delete_node(4, &head);
    display_list(head);

    delete_node(5, &head);
    display_list(head);

    insert_node(1, 88, &head);
    display_list(head);

    insert_node(3, 22, &head);
    display_list(head);

    insert_node(5, 55, &head);
    display_list(head);

    insert_node(7, 99, &head);
    display_list(head);

    insert_node(9, 99, &head);
    display_list(head);

    delete_node(88, &head);
    display_list(head);

    delete_node(55, &head);
    display_list(head);

    reverse_list(&head);
    display_list(head);

    reverse_rec(&head, head, NULL, NULL);
    display_list(head);

    destroy_list(head);

    return 0;
}

void append(NODE** head, int val)
{
    if (*head == NULL) {
        *head = create_node(val);
    } else {
        NODE* cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = create_node(val);
    }
}

NODE* create_node(int val)
{
    NODE* nn = (NODE*) malloc (sizeof(NODE));
    nn->next = NULL;
    nn->data = val;
    return nn;
}

void display_list(NODE* head)
{
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

void destroy_list(NODE* head)
{
    while (head != NULL) {
        NODE* cur = head;
        head = head->next;
        free(cur);
    }
}

int length(NODE* head)
{
    if (head == NULL) {
        return 0;
    }

    return 1 + length(head->next);
}

void swap_nodes(NODE** head, int first, int second)
{
    NODE *prevX = NULL, *curX = *head;
    NODE *prevY = NULL, *curY = *head;
    NODE *tmp;

    /* get the first node */
    while (curX != NULL && first != curX->data) {
        prevX = curX;
        curX = curX->next;
    }

    /* get the second node */
    while (curY != NULL && second != curY->data) {
        prevY = curY;
        curY = curY->next;
    }

    if (prevX == NULL) {
        *head = curY;
        prevY->next = curX;
        tmp = curY->next;
        curY->next = curX->next;
        curX->next = tmp;

        return;
    }

    if (prevY == NULL) {
        // both of these will work
        *head = curX;
        prevX->next = curY;
        tmp = curY->next;
        curY->next = curX->next;
        curX->next = tmp;
        return;
#if 0
        *head = curX;
        prevX->next = curY;
        tmp = curX->next;
        curX->next = curY->next;
        curY->next = tmp;
        return;
#endif
    }

    prevX->next = curY;
    prevY->next = curX;
    tmp = curY->next;
    curY->next = curX->next;
    curX->next = tmp;
}

void delete_node(int val, NODE** head)
{
    NODE *cur = *head;
    NODE *prev = NULL;

    while (cur != NULL && cur->data != val)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        printf("data not found\n");
        return;
    }
    if (prev == NULL) {
        *head = cur->next;
        free(cur);
        return;
    }
    prev->next = cur->next;
    free(cur);
}

void insert_node(int pos, int val, NODE** head)
{
    NODE *prev = NULL;
    NODE *cur = *head;
    NODE *new_node;
    int count = 1;

    if (pos <= 0) {
        printf("Invalid pos\n");
    }

    if (pos == 1)
    {
        new_node = create_node(val);
        new_node->next = *head;
        *head = new_node;
        return;
    }

    while (cur != NULL && count != pos) {
        count++;
        prev = cur;
        cur = cur->next;
    }

    if (pos > count) {
        printf("invalid pos\n");
        return;
    }

    new_node = create_node(val);
    prev->next = new_node;
    new_node->next = cur;
}

void print_middle(NODE* head)
{
    NODE* slow_ptr = head;
    NODE* fast_ptr = head;

    if (head == NULL) {
        printf("List is empty");
        return;
    }
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    printf("Mid element is %d\n", slow_ptr->data);
}

void reverse_list(NODE** head)
{
    NODE *cur = *head;
    NODE *prev = NULL;
    NODE *tmp = NULL;

    while (cur != NULL) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    *head = prev;
}

void reverse_rec(NODE** head, NODE* cur, NODE* prev, NODE* tmp)
{
    if (cur == NULL) {
        *head = prev;
        return;
    }
    tmp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmp;

    return reverse_rec(head, cur, prev, tmp);
}
