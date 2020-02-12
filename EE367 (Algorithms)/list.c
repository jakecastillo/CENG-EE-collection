/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Username: Jakecast
// 2020-01-23
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void display_list(struct Node *head);
void destroy_list(struct Node *head);
struct Node *create_list(int startVal, int finishVal);

struct Node *reverse(struct Node *head);
struct Node *remove_Kth_from_end(struct Node *head, int k);

void main() 
{
struct Node *p = create_list(3,13);
printf("\nCreated a list:\n");
display_list(p);
p = reverse(p);
printf("Reversed the list:\n");
display_list(p);
destroy_list(p);

p = create_list(3,13);
printf("\nCreated a list:\n");
display_list(p);
p =remove_Kth_from_end(p, 5);
printf("Removed 5-th from end:\n");
display_list(p);
destroy_list(p);
}

struct Node *reverse(struct Node *head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

struct Node *remove_Kth_from_end(struct Node *head, int k)
{
  int r = 0;
  struct Node* pass=head;
  while(head != NULL){
      r++;
      head = head->next;
  }
  
  if(r==k){
      pass=pass->next;
      return pass;
  }
  
  head = pass;
  
  for(int i = 0; i <r-k-1;i++){
      head = head->next;
  }
  
  head->next = head->next->next;
  return pass;
}

void display_list(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

void destroy_list(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return;
}

struct Node *create_list(int startVal, int finishVal)
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