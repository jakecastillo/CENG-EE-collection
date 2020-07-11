#include <stdlib.h>
#include <stdio.h>

struct Node {
	int val;
	struct Node * next;
};

struct Node *createNode(int val);
void destroyNode(struct Node *p);
struct Node *createRandomList(int n);
void destroyList(struct Node *head);
void displayList(struct Node *head);
struct Node * mergesort(struct Node *head);
struct Node * merge(struct Node * left, struct Node * right);

void main()
{
struct Node *list = createRandomList(32);
printf("First unsorted:\n");
displayList(list);
list = mergesort(list);
printf("Mergesort:\n");
displayList(list);
destroyList(list);
printf("\n");

list = createRandomList(23);
printf("Second unsorted:\n");
displayList(list);
list = mergesort(list);
printf("Mergesort:\n");
displayList(list);
destroyList(list);
}

struct Node * mergesort(struct Node *head) 
{
if (head == NULL) return head;  /* Base case of empty list */
if (head->next == NULL) return head;  /* Base case of just one node */
struct Node * curr=head;
struct Node * mid=head;  /* Start of second list */
struct Node * prevmid;   
while (curr!=NULL) {
	curr = curr->next;
	prevmid = mid;
	mid = mid->next;;
	if (curr == NULL) break;
	curr = curr->next;
}
prevmid->next = NULL;  /* Terminate first list */

head = mergesort(head);
mid = mergesort(mid);
return merge(head, mid);
}

/* 
 * left -> sorted linked list 
 * right -> sorted linked list 
 * Return merged sorted linked lisst
 * It doesn't work!  Fix it!
 */

struct Node * merge(struct Node * left, struct Node * right)
{

struct Node * last = NULL;  
if (right == NULL) return left;
if (left == NULL) return right;

if (left->val <= right->val){
    last = left;
    last->next = merge(left->next, right);
}
else{
    last = right;
    last->next = merge(left, right->next);
}
return last;
}

struct Node *createNode(int val)
{
struct Node *p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->next = NULL;
return p;
}

void destroyNode(struct Node *p)
{
free(p);
}

struct Node *createRandomList(int n) 
{
srand48(1);
if (n <= 0) return NULL;
struct Node *head = createNode(lrand48()%1000);
struct Node *last = head;  /* Last node */
for (int i=1; i<n; i++) {
	last->next = createNode(lrand48()%1000);
	last = last->next;
}
return head;
}

void destroyList(struct Node *head)
{
struct Node *curr=head;
struct Node *p;
while (curr!=NULL) {
	p =curr;
	curr=curr->next;
	destroyNode(p);
}
}

void displayList(struct Node *head)
{
printf("List: ");
for (struct Node *curr=head; curr!=NULL; curr=curr->next) {
	printf("-> %d",curr->val);
}
printf("\n\n");
}

