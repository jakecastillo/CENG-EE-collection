#include <stdlib.h>
#include <stdio.h>

#define LENGTH1 15
#define LENGTH2 15

struct node {
    int val;
    struct node * left;
    struct node * right;
};

int list1[LENGTH1] = {25,34,16,-1,80,-1,-1,-1,63,13,-1,-1,92,-1,-1};
int list2[LENGTH2] = {25,63,92,-1,-1,13,-1,-1,34,-1,16,80,-1,-1,-1};


struct node * create_node(int val);
void display_preorder(struct node * p);
void display_inorder(struct node * p);
struct node * create_tree(int list[], int length); 

void main()
{
struct node * tree = create_tree(list1, LENGTH1);
printf("Tree 1:\n");
printf("Preorder: ");
display_preorder(tree);
printf("\n");
printf("Inorder: ");
display_inorder(tree);
printf("\n");

struct node * tree2 = create_tree(list2, LENGTH2);
printf("Tree 2:\n");
printf("Preorder: ");
display_preorder(tree2);
printf("\n");
printf("Inorder: ");
display_inorder(tree2);
printf("\n");
}

/* Creates a tree from the encoded list */
struct node * create_tree(int list[], int length) 
{
return NULL;
}


/* Display values in a tree using preorder traversal */
void display_preorder(struct node * p)
{
if (p==NULL) return;
printf("%d ",p->val);
display_preorder(p->left);
display_preorder(p->right);
}

/* Display values in a tree using inorder traversal */
void display_inorder(struct node * p)
{
if (p==NULL) return;
display_inorder(p->left);
printf("%d ",p->val);
display_inorder(p->right);
}

/* Creates a node which has value 'va' and no children */
struct node * create_node(int val)
{
struct node * p = (struct node *) malloc(sizeof(struct node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

