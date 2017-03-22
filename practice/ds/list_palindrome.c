/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
struct node
{
    char data;
    struct node* next;
};

int compare(struct node *left, struct node* right)
{
    while (left != NULL && right != NULL) {
        if (left->data == right->data) {
            left = left->next;
            right = right->next;
        } else {
            return (0);
        }
    }
    if (left == NULL && right == NULL)
        return 1;
    else
        return 0;
}

void reverse(struct node** head)
{
    struct node *cur = *head;
    struct node *prev = NULL;
    struct node *tmp = NULL;

    while (cur != NULL) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    *head = prev;
}

/* Function to check if given linked list is
   palindrome or not */
bool isPalindrome(struct node *head)
{
    struct node* slowptr = head;
    struct node *prev_slow = NULL;
    struct node* fastptr = head;
    struct node *mid_node = NULL;
    struct node* second_half = head;
    int res;

    if (head == NULL || head->next == NULL)
        return 0;

    while (fastptr != NULL && fastptr->next != NULL) {
        prev_slow = slowptr;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    if (fastptr != NULL) { /* means we have odd nodes */
        mid_node = slowptr;
        slowptr = slowptr->next;
    }

    second_half = slowptr;
    prev_slow->next = NULL;
    reverse(&second_half);
    res = compare(head, second_half);
    reverse(&second_half);

    if (mid_node == NULL) {
        prev_slow->next = second_half;
    } else {
        prev_slow->next = mid_node;
        mid_node->next = second_half;
    }

    return res;
}

#if 0
bool isPalindromeUtil(struct node** left, struct node* right)
{
    bool isp, isp1;
    if (right == NULL)
        return true;

    isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;
    isp1 = (*left)->data == right->data;
    *left = (*left)->next;
    return isp1;
}


bool isPalindrome(struct node *head)
{
    return isPalindromeUtil(&head, head);
}
#endif

/* Push a node to linked list. Note that this function
   changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}

// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        push(&head, str[i]);
        printList(head);
        isPalindrome(head)? printf("palindrome\n") : 
            printf("not palindrome\n");
    }

    return 0;
}
