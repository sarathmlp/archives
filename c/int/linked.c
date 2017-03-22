#include <stdio.h>
#include <stdlib.h>

struct list_item_s
{
    struct list_item_s *next;
    int value;
};

void append_value( struct list_item_s **head, int val )
{
    struct list_item_s *node, *cur;

    node = (struct list_item_s*) malloc(sizeof(struct list_item_s));
    if (node == NULL) {
        printf("Failed to allocate memory\n");
        abort();
    }
    node->value = val;
    node->next  = NULL;

    if (*head) {
        cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        /* append node to the list */
        cur->next = node;
    } else {
        /* first node in the list */
        *head = node;
    }
}

void delete_value( struct list_item_s **head, int val )
{
    struct list_item_s *cur, *prev;

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
            free(cur);
            printf("deleting %d\n", cur->value);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}

void printlist( struct list_item_s *head )
{
    struct list_item_s *ptr = head;
    
    printf("List: ");
    while(ptr) {
        printf("%d-", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    struct list_item_s *head = NULL;
    
    append_value(&head, 1);
    append_value(&head, 2);
    append_value(&head, 3);
    printlist(head);
    
    delete_value(&head, 2);
    printlist(head);
    
    delete_value(&head, 1);
    printlist(head);
    
    delete_value(&head, 3);
    printlist(head);
    
    return 0;
}
