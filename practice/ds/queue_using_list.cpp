#include <iostream>
using namespace std;

struct node {
    int val;
    struct node* next;
};

typedef struct node NODE;

void enqueue(NODE** head, int val);
int dequeue(NODE** head);
NODE* create_node(int val);
void display(NODE* head);

int main()
{
    NODE* head = NULL;
    enqueue(&head, 1);
    display(head);
    enqueue(&head, 2);
    enqueue(&head, 3);
    display(head);
    enqueue(&head, 4);
    display(head);

    dequeue(&head);
    display(head);
    dequeue(&head);
    dequeue(&head);
    display(head);
    dequeue(&head);
    display(head);
    dequeue(&head);
    display(head);

    return 0;
}

void enqueue(NODE** head, int val)
{
    if (*head == NULL) {
        *head = create_node(val);
    } else {
        NODE* new_node = create_node(val);
        NODE* cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

int dequeue(NODE** head)
{
    if (*head == NULL) {
        cout << "q empty" << endl;
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
