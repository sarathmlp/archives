#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
  int data;
  struct node* next;
};
 
int getIntesectionNode(struct node* list1, struct node* list2)
{
    int cnt1 = 0, cnt2 = 0;
    int delta;
    struct node* cur = list1;

    while (cur != NULL) {
        cnt1++;
        cur = cur->next;
    }

    cur = list2;
    while (cur != NULL) {
        cnt2++;
        cur = cur->next;
    }

    printf("%d, %d\n", cnt1, cnt2);

    if (cnt1 > cnt2) {
        delta = cnt1 - cnt2;
        while (delta > 0) {
            list1 = list1->next;
            delta--;
        }
    } else {
        delta = cnt2 - cnt1;
        while (delta > 0) {
            list2 = list2->next;
            delta--;
        }
    }

    while (list1 != NULL) {
        if (list1 == list2) {
            break;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 != NULL) {
        printf("intersection point is %d\n", list1->data);
    } else  {
        printf("no intersection point\n");
    }

    return 1;
}

int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  getIntesectionNode(head1, head2);
 
}
