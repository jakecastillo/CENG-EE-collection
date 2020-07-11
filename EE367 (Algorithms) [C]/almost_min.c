#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
    int value;
    struct node * left;
    struct node * right;
};

struct node * insert_value(struct node * root, int value);
void delete_tree(struct node * root);
int almost_min(struct node * root);
void display_inorder(struct node * root);
void display_preorder(struct node * root);

void main()
{
struct node * root = NULL;
int result;

printf("Tree 1:\n");
root = insert_value(root, 20);
root = insert_value(root, 30);
printf("In-order: "); display_inorder(root); printf("\n");
printf("Pre-order: "); display_preorder(root); printf("\n");
result = almost_min(root);
printf("Almost min: %d\n\n", result);

printf("Tree 2:\n");
root = insert_value(root, 25);
printf("In-order: "); display_inorder(root); printf("\n");
printf("Pre-order: "); display_preorder(root); printf("\n");
result = almost_min(root);
printf("Almost min: %d\n\n", result);

printf("Tree 3:\n");
root = insert_value(root, 5);
printf("In-order: "); display_inorder(root); printf("\n");
printf("Pre-order: "); display_preorder(root); printf("\n");
result = almost_min(root);
printf("Almost min: %d\n\n", result);

printf("Tree 4:\n");
root = insert_value(root, 10);
root = insert_value(root, 8);
root = insert_value(root, 15);
printf("In-order: "); display_inorder(root); printf("\n");
printf("Pre-order: "); display_preorder(root); printf("\n");
result = almost_min(root);
printf("Almost min: %d\n\n", result);

delete_tree(root);
}

void helper (struct node* root, int*array){
    if(root != NULL) {
      helper(root->left,array);
      if((array[root->value])==0){
          (array[root->value]) = 1;
      }
      helper(root->right,array);
   }
}

int findmin (int* array){
    int index = 0;
    for(int i=0;i<1000;i++){
        if(array[i]!=0){
            index++;
        }
        if(index==2){
            return i;
        }
    }
    return -1;
}

int almost_min(struct node * root)
{
    int secondmin = -1;
    int array[1000];
    memset(array, 0, 1000);
    helper(root,array);
    secondmin = findmin(array);
    return secondmin;
}

struct node * insert_value(struct node * root, int value)
{
if (root==NULL) {
    struct node * p = (struct node *) malloc(sizeof(struct node));
    p->value = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}
if (value < root->value) {
    root->left = insert_value(root->left, value);
}
else {
    root->right = insert_value(root->right, value);
}
return root;
}

void delete_tree(struct node * root)
{
if (root==NULL) return;
delete_tree(root->left);
delete_tree(root->right);
free(root);
return;
}

void display_inorder(struct node * root)
{
if (root==NULL) return;
display_inorder(root->left);
printf(" %d", root->value);
display_inorder(root->right);
return;
}

void display_preorder(struct node * root)
{
if (root==NULL) return;
printf(" %d", root->value);
display_preorder(root->left);
display_preorder(root->right);
return;
}