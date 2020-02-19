#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

struct Node * createNode(char data);
struct Node * createTree(char encoding[], int *curr);
void preorder(struct Node * root);
void inorder(struct Node * root);
void postorder(struct Node * root);
struct Node * invert(struct Node * root);

void main()
{
char tree[] = "zrc//a//y//";

int curr = 0;
struct Node * root = createTree(tree, &curr);
printf("Initial Tree Encoding: %s\n", tree);
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

root = invert(root);
printf("\nInverted tree:\n");
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

return;
}

void swap(struct Node * root, struct Node * left, struct Node * right){
	root->left = right;
	root->right = left;
}

struct Node * invert(struct Node * root)
{
	if(root){
		struct Node* left = invert(root->left);
		struct Node* right = invert(root->right);
		swap(root, left, right);
	}
return root;
}

void preorder(struct Node * root){
	if (root==NULL) return;
	printf("%c", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node * root){
if (root==NULL) return;
	inorder(root->left);
	printf("%c", root->data);
	inorder(root->right);
}

void postorder(struct Node * root){
	if (root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}

struct Node * createNode(char data){
	struct Node *p = (struct Node *) malloc(sizeof(struct Node));
	p->left = NULL;
	p->right = NULL;
	p->data = data;
}

struct Node * createTree(char encoding[], int *curr){
	if (encoding[*curr] == '/') {
		return NULL;
	}
	struct Node *p = createNode(encoding[*curr]);
	(*curr)++;
	p->left = createTree(encoding, curr);
	(*curr)++;
	p->right = createTree(encoding, curr);

	return p;
}
