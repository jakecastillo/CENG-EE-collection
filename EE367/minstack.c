#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
};

typedef 
   struct Node *
Min_Stack;

Min_Stack create_minstack()
{
return NULL;
}

Min_Stack destroy_minstack(Min_Stack s)
{
struct Node *p = s;
while (p!=NULL) {
    struct Node *temp = p;
    p=p->next;
    free(temp);
}
}

int get_top(Min_Stack stack)
{
if (stack==NULL) {
    return -1;
}
return stack->val;
}

int get_min(Min_Stack stack)
{
  struct Node* node = stack;
  int min = node->val;

  while (node != NULL) {
    if (node->val < min) {
      min = node->val;
    }

    node = node->next;
  }

  return min;
}


int is_empty(Min_Stack stack)
{
if (stack==NULL) {
    return 1;
}
return 0;
}

Min_Stack pop(Min_Stack stack)
{
if (is_empty(stack)) {
    return NULL;
}
struct Node * p = stack->next;
free(stack);
return p;
}

Min_Stack push(Min_Stack stack, int val)
{
struct Node *p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->next = stack;
return p;
}

void main()
{
Min_Stack s = create_minstack();
s = push(s, 13);
printf("Push 13\n");
s = push(s, 15);
printf("Push 15\n");
s = push(s, 11);
printf("Push 11\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = push(s, 20);
printf("Push 20\n");
s = push(s, 10);
printf("Push 10\n");
s = push(s, 9);
printf("Push 9\n");
s = push(s, 17);
printf("Push 17\n");
s = push(s, 18);
printf("Push 18\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
s = pop(s);
printf("Pop\n");
printf("Top = %d, Min=%d\n",get_top(s),get_min(s));
destroy_minstack(s);

return;
}
