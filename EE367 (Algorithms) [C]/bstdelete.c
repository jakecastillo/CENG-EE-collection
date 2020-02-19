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
struct Node * delete(struct Node * root, char c);

void main()
{
char tree[] = "hca//d/fe///mk//rn/p///";

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

root = delete(root,'f');
root = delete(root,'c');
root = delete(root,'m');
printf("\nDeleted 'f', 'c', and then 'm'\n");
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

void swap(struct Node* root, struct Node* right){
	char temp = root->data;

	root->data = right->data;
	right->data = temp;
}

struct Node * delete(struct Node * root, char c)
{
	if (!root){
		return NULL;
	}

	if (root->data == c){
		if(!root->right){
			struct Node* left = root->left;
			root = NULL;
			free(root);
			return left;
		}

		else{
			struct Node* right = root->right;
			while(right->left){
				right = right->left;
			}
			swap(root, right);
			root->right = delete(root->right, c);
		}
	}

	else if(c < root->data){
		root->left = delete(root->left, c);
	}

	else if(c > root->data){
		root->right = delete(root->right, c);
	}

return root;
}

void preorder(struct Node * root)
{
if (root==NULL) return;
printf("%c", root->data);
preorder(root->left);
preorder(root->right);
}

void inorder(struct Node * root)
{
if (root==NULL) return;
inorder(root->left);
printf("%c", root->data);
inorder(root->right);
}

void postorder(struct Node * root)
{
if (root==NULL) return;
postorder(root->left);
postorder(root->right);
printf("%c", root->data);
}

struct Node * createNode(char data)
{
struct Node *p = (struct Node *) malloc(sizeof(struct Node));
p->left = NULL;
p->right = NULL;
p->data = data;
}

struct Node * createTree(char encoding[], int *curr)
{
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
