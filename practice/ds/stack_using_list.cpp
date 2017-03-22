#include <iostream>
using namespace std;

struct node {
    int val;
    struct node* next;
};

typedef struct node NODE;

void push(NODE** head, int val);
int pop(NODE** head);
NODE* create_node(int val);
void display(NODE* head);

int main()
{
    NODE* head = NULL;
    push(&head, 1);
    display(head);
    push(&head, 2);
    push(&head, 3);
    display(head);
    push(&head, 4);
    display(head);

    pop(&head);
    display(head);
    pop(&head);
    pop(&head);
    display(head);
    pop(&head);
    display(head);
    pop(&head);
    display(head);

    return 0;
}

void push(NODE** head, int val)
{
    if (*head == NULL) {
        *head = create_node(val);
    } else {
        NODE* new_node = create_node(val);
        new_node->next = *head;
        *head = new_node;
    }
}

int pop(NODE** head)
{
    if (*head == NULL) {
        cout << "stack empty" << endl;
        return -1;
    }
    NODE* tmp = (*head)->next;
    int val = (*head)->val;
    free(*head);
    *head = tmp;
    return val;
}

NODE* create_node(int val)
{
    NODE* new_node = (NODE*) malloc (sizeof(NODE));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void display(NODE* head)
{
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}
