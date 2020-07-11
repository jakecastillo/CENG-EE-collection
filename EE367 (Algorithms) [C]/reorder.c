/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node {
    int val;
    struct Node *next;
};

void displayList(struct Node *head);
struct Node * destroyList(struct Node *head);
struct Node *createList(int startVal, int finishVal);

struct Node *reorderList(struct Node *head);

void main() 
{

struct Node *p = createList(3,13);

p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

p = createList(3,12);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

}

struct Node *reverse(struct Node *head)
{
  struct Node *node = head;
  int length = 0;
  while(node != NULL) {
    node = node->next;
    length++;
  }

  if (length == 1)
    return head;
  
  node = head->next;
  struct Node *nextNode = node->next;
  struct Node *temp = NULL;
  head->next = NULL;
  node->next = head;

  while (nextNode != NULL) {
    temp = nextNode->next;
    nextNode->next = node;
    node = nextNode;
    nextNode = temp;
  }

  return node;
}
struct Node *reorderList(struct Node *head){
    struct Node *node = head;
    int length = 0;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    if (length == 1 || length == 2)
        return head;

    double reposn;

    if (length % 2 == 0)
        reposn = (length / 2) - 1;
    else
        reposn = floor(length / 2);
    
    struct Node *repos = head;
    struct Node *prevrepos;

    for (int i = 0; i < length - reposn; i++) {
        prevrepos = repos;

        repos = repos->next;

        if (i == length - reposn - 1) {
            prevrepos->next = NULL;
        }
    }
    repos = reverse(repos);
    node = head;
    struct Node *nextNode = node->next;
    struct Node *nextrepos;

    for (int i = 0; i < reposn; i++) {
        node->next = repos;
        nextrepos = repos->next;
        repos->next = nextNode;
        repos = nextrepos;
        node = nextNode;
        nextNode = nextNode->next;
    }

    return head;
}

void displayList(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

struct Node * destroyList(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return NULL;
}

struct Node *createList(int startVal, int finishVal)
{
struct Node *head = NULL;  /* Head of the list */
struct Node *last = NULL;  /* Last node in the list */
for (int i=startVal; i<=finishVal; i++) {
    /* Create node */
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->val = i;
    p->next = NULL;
    if (i == startVal) {
        head = p;
    }
    else {
	last->next = p;
    }
    last = p;
}
return head;
}

