#include <stdlib.h>
#include <stdio.h>

struct node {
   int val;
   struct node *left;
   struct node *right;
};

struct node * create_node(int val);
void destroy_tree(struct node * root);
int is_bst(struct node * root);

/* Creating trees */
struct node * create_tree1();
struct node * create_tree2();
struct node * create_tree3();
struct node * create_tree4();

/* Helper functions*/
int max_val(int a, int b); /* Returns max value */
int min_val(int a, int b); /* Returns min value */


void main()
{
struct node *root;
root = create_tree1();
printf("Tree 1 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree2();
printf("Tree 2 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree3();
printf("Tree 3 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree4();
printf("Tree 4 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

return;
}

void traverse(struct node * root, int * stack, int * top)
{
    if(!root) return;
    traverse(root->left, stack, top);
    stack[(*top)++] = root->val;
    traverse(root->right, stack, top);
}

int is_bst(struct node * root)
{
    int stack[10000];
    int top = 0;
    int i;

    traverse(root, stack, &top);

    for(i = 1; i < top; ++i)
    {
        if(stack[i] <= stack[i - 1]) return 0;
    }
    return 1;
}

struct node * create_node(int val)
{
struct node *p = (struct node *) malloc(sizeof(struct node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

void destroy_tree(struct node * root)
{
if (root==NULL) return;
destroy_tree(root->left);
destroy_tree(root->right);
free(root);
return;
}

struct node * create_tree1()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->right = create_node(30);
root->right->left = create_node(10);
root->right->right = create_node(34);
return root;
}

struct node * create_tree2()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->right = create_node(10);
root->left->right->left = create_node(7);
root->right = create_node(30);
root->right->left = create_node(22);
root->right->right = create_node(34);
return root;
}

struct node * create_tree3()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->right = create_node(30);
root->right->left = create_node(10);
root->right->left->left = create_node(8);
root->right->left->right = create_node(12);
root->right->right = create_node(34);
return root;
}

struct node * create_tree4()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->left = create_node(1);
root->left->right = create_node(10);
root->right = create_node(30);
return root;
}

int max_val(int a, int b)
{
if (a > b) return a;
else return b;
}

int min_val(int a, int b)
{
if (a > b) return b;
else return a;
}
