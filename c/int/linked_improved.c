#include <stdio.h>
#include <stdlib.h>

struct list_item_s
{
    struct list_item_s *next;
    int value;
};

/* avoid using struct list_item_s all the time */
typedef struct list_item_s NODE;

NODE* create_node (int val)
{
    NODE  *node;

    node = (NODE*) malloc(sizeof(NODE));
    if (node == NULL) {
        printf("Allocatin failed\n");
        abort();
    }
    node->value = val;
    node->next  = NULL;
    
    return node;
}

void append_value (NODE **head, int val )
{
    NODE *new_node, *cur;

    new_node = create_node(val);

    if (*head) {
        cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        /* append to the list */
        cur->next = new_node;
    } else {
        /* first node in the list */
        *head = new_node;
    }
}

void delete_value (NODE **head, int val )
{
    NODE *cur, *prev;

    if (*head == NULL) {
        printf("cannot delete empty list\n");
    } 

    cur =  prev = *head;
    while (cur != NULL) {
        if (cur->value == val) {
            /* if the value is at head node, move the head*/
            if (cur == *head) {
                *head = cur->next;
            }
            prev->next = cur->next;
            printf("deleting %d\n", cur->value);
            free(cur);
            cur = prev->next;
            continue;
            // break;
        }
        prev = cur;
        cur = cur->next;
    }
}

void printlist (NODE *head)
{
    NODE *ptr = head;
    
    printf("List: %s", (head == NULL)? "empty":"");
    while (ptr) {
        printf("%d-", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void search(NODE** head, int val)
{
    NODE *cur;
    cur = *head;
    int count = 0;

    while (cur != NULL) {
        if (cur->value == val) {
            count++;
            printf("%d found %d time%s\n", 
                   val, count, count==1 ? "":"s");
        }
        cur = cur->next;
    }
}

void insert_pos(NODE** head, int val, int pos)
{
    NODE *cur, *prev, *new_node;
    int count = 0;

    if ((pos < 1) || (*head == NULL && pos != 1)) {
        printf("Invalid position\n");
        return;
    }
    if  (*head == NULL) {
        append_value(head, val);
        return;
    }
    /* handle boundary case */
    if (pos == 1) {
        new_node = create_node(val);
        new_node->next = *head;
        *head = new_node;
        return;
    }

    cur = prev = *head;
    while (cur != NULL) {
        count++;
        if (count == pos) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    /* handle boundary case */
    if (pos > (count+1)) {
        printf("Invalid position\n");
        return;
    }
    new_node = create_node(val);
    prev->next = new_node;
    new_node->next = cur;
}

void delete_pos(NODE** head, int pos)
{
    NODE *cur, *prev, *new_node;
    int count = 0;

    if ((pos < 1) || *head == NULL) {
        printf("Invalid position\n");
        return;
    }

    /* handle boundary case */
    if (pos == 1) {
        cur = *head;
        *head = (*head)->next;
        printf("Deleting at pos %d\n", pos);
        free(cur);
        return;
    }

    cur = prev = *head;
    while (cur != NULL) {
        count++;
        if (count == pos) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    /* handle boundary case */
    if (pos > count) {
        printf("Invalid position %d\n", pos);
        return;
    }
    prev->next = cur->next;
    printf("deleting at pos %d\n", pos);
    free(cur);
}

int main(int argc, char *argv[])
{
    NODE *head = NULL;
    
    insert_pos(&head, 99, 1);
    printlist(head);
    append_value(&head, 1);
    printlist(head);
    insert_pos(&head, 77, 2);
    insert_pos(&head, 66, 4);
    printlist(head);
    append_value(&head, 2);
    append_value(&head, 2);
    append_value(&head, 3);
    insert_pos(&head, 88, 1);
    printlist(head);
    
    search(&head, 2);

    delete_value(&head, 2);
    printlist(head);
    
    delete_value(&head, 1);
    printlist(head);
    
    delete_value(&head, 3);
    printlist(head);

    delete_pos(&head, 1);
    printlist(head);
    
    delete_pos(&head, 2);
    printlist(head);
    delete_pos(&head, 4);
    printlist(head);
    delete_pos(&head, 3);
    printlist(head);
    delete_pos(&head, 1);
    printlist(head);
    delete_pos(&head, 1);
    printlist(head);
    delete_pos(&head, 1);
    printlist(head);
    return 0;
}
