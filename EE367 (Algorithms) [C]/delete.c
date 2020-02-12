/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void display_list(struct Node *head);
struct Node * destroy_list(struct Node *head);
struct Node *create_list(int start_val, int finish_val);

struct Node *delete(struct Node *head, int value);

void main() 
{

struct Node *p = create_list(3,13);

p = create_list(3,13);
printf("\nCreated a list:\n");
display_list(p);
p = delete(p, 7);
printf("Deleted 7:\n");
display_list(p);
p = delete(p, 13);
printf("Deleted 13:\n");
display_list(p);


p = destroy_list(p);


}

struct Node *delete(struct Node *head, int value)
{
    if (head == NULL){
        return NULL;
    }
    
    if (head->val == value){
        auto next = head->next;
        free(head);
        return delete(next, value);
    } else{
        head->next = delete(head->next,value);
        return head;
    }
}


void display_list(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

struct Node * destroy_list(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return NULL;
}

struct Node *create_list(int start_val, int finish_val)
{
struct Node *head = NULL;  /* Head of the list */
struct Node *last = NULL;  /* Last node in the list */
for (int i=start_val; i<=finish_val; i++) {
    /* Create node */
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->val = i;
    p->next = NULL;
    if (i == start_val) {
        head = p;
    }
    else {
	last->next = p;
    }
    last = p;
}
return head;
}