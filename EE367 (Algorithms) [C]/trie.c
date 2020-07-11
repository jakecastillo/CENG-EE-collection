#include <stdlib.h>
#include <stdio.h>


struct trie_node {
    int valid;      /* Indicates a valid word; false=0 and true=1 */
    char word[26];  /* Characters in the word */ 
    int length;     /* Length of the word */
    struct trie_node * child[26]; /* Children of the node */
};

void destroy_trie(struct trie_node * root);
struct trie_node * create_node();
struct trie_node * insert(struct trie_node * root, char word[], int length);
void auto_comp(struct trie_node *root, char word[], int length);

// Helper functions
void helper_print_word(struct trie_node *node, char word[], int length);
void helper_tranverse_nodes(struct trie_node *node, char word[], int length);

/* Helper functions */
int word_length(char * word); /* Find length of word terminated by '\0' */

void main()
{
char word1[] = "an";
char word2[] = "anger";
char word3[] = "angst";
char word4[] = "analogy";
char word5[] = "bed";
char word6[] = "bedlam";
char word7[] = "bee";
char word8[] = "beehive";
char word9[] = "been";

char test1[] = "a";
char test2[] = "cat";
char test3[] = "ang";
char test4[] = "bee";

struct trie_node * root;
root = insert(root, word1, word_length(word1));
root = insert(root, word2, word_length(word2));
root = insert(root, word3, word_length(word3));
root = insert(root, word4, word_length(word4));
root = insert(root, word5, word_length(word5));
root = insert(root, word6, word_length(word6));
root = insert(root, word7, word_length(word7));
root = insert(root, word8, word_length(word8));
root = insert(root, word9, word_length(word9));

printf("Auto-complete for '%s':\n", test1);
auto_comp(root, test1, word_length(test1));
printf("Auto-complete for '%s':\n", test2);
auto_comp(root, test2, word_length(test2));
printf("Auto-complete for '%s':\n", test3);
auto_comp(root, test3, word_length(test3));
printf("Auto-complete for '%s':\n", test4);
auto_comp(root, test4, word_length(test4));


}

void printWord(struct trie_node *node, char word[], int length){
    
    if(node->valid == 0) return;

    for(int i = 0; i < length; i++){
        if(node->word[i] != word[i]) return;
    }

    for(int i = 0; i < 26;i++){
        if(node->word[i] == '\0') break;
        printf("%c", node->word[i]);

    }
     printf("\n");
    return;
}

void auto_comp(struct trie_node *root, char word[], int length){
    
    if (!root) return;  
    printWord(root, word, length);

    for(int i =0; i < 26; i++){
        auto_comp(root->child[i], word, length);
    }
    return;
}

struct trie_node * insert(struct trie_node * root, char word[], int length)
{
struct trie_node * new_root = root;
if (root==NULL) {
    new_root = create_node();
}

/* Insert a blank node */
struct trie_node * current = new_root;
for (int i=0; i<length; i++) {
    int index = (int) (word[i] - 'a');
    if (current->child[index] == NULL) {
	current->child[index] = create_node(); 
    }
    current = current->child[index];
}
for (int i=0; i<length; i++) {
    current->word[i] = word[i];
}

/* Set values in the blank node */
current->length = length;
current->valid=1;
return new_root;
}

struct trie_node * create_node()
{
struct trie_node * p = (struct trie_node *) malloc(sizeof(struct trie_node));
p->valid = 0;
p->length = 0;
for (int i=0; i<26; i++) {
    p->child[i] = NULL;
}
return p;
}

void destroy_trie(struct trie_node * root)
{
if (root==NULL) return;
for (int i=0; i<26; i++) {
    destroy_trie(root->child[i]);
}
free(root);
}


int word_length(char * word)
{
int length;
for (length=0; word[length]!='\0'; length++);
return length;
}

