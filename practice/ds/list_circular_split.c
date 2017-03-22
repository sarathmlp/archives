#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

/* Function to print nodes in a given Circular linked list */
void printList(struct node *head)
{
    struct node *cur = head;
    if (head == NULL)
        return;

    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);

    printf("\n");
}

NODE* create_node(int val)
{
    NODE* nn = (NODE*) malloc (sizeof(NODE));
    nn->next = NULL;
    nn->data = val;
    return nn;
}

void append_node(NODE** head, int val)
{
    NODE *new_node;
    if (*head == NULL) {
        new_node = create_node(val);
        *head = new_node;
        new_node->next = new_node;
    } else {
        NODE *cur = *head;
        while (cur->next != *head) {
            cur = cur->next;
        }
        new_node = create_node(val);
        cur->next = new_node;
        new_node->next = *head;
    }
}

void push(struct node **head_ref, int data)
{
  struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *head_ref; 
  ptr1->data = data;  
  ptr1->next = *head_ref; 
   
  /* If linked list is not NULL then set the next of 
    last node */
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;        
    temp->next = ptr1; 
  }
  else
     ptr1->next = ptr1; /*For the first node */
 
  *head_ref = ptr1;     
} 

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(NODE *head, NODE **head1_ref, NODE **head2_ref)
{
    NODE *fastptr = head;
    NODE *slowptr = head;

    while (fastptr->next != head &&
           fastptr->next->next != head) {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }

    if (fastptr->next->next == head)
        fastptr = fastptr->next;

    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slowptr->next;

    fastptr->next = slowptr->next;
    slowptr->next = head;
}

void destroy_list(NODE* head)
{
    NODE *cur = head->next;
    NODE *tmp = NULL;

    while (cur != head) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free (head);
}

/* Driver program to test above functions */
int main()
{
  int list_size, i, T, n, val; 
   
  /* Initialize lists as empty */
  struct node *head = NULL;
  struct node *head1 = NULL;
  struct node *head2 = NULL;  

  scanf("%d", &T);

  while (T--) {
      scanf("%d", &n);
      for (i=0; i < n; i++) {
          scanf("%d", &val);
          append_node(&head,val);
      }
      splitList(head, &head1, &head2);
      printList(head1);
      printList(head2);
      destroy_list(head1);
      destroy_list(head2);
      head = NULL;
  }
 
  return 0;
} 
