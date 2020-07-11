#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000
#define NONCHAR '\0'

struct Stack {
	char * val;
	int size;
	int sp; /* Stack pointer */
};

struct Stack * createStack(int size);
void destroyStack(struct Stack *s);

char peek(struct Stack *stack);
void push(struct Stack *stack, char newval);
char pop(struct Stack *stack);
enum Bool isEmpty(struct Stack *stack);
void displayOutcome(char str[]);

enum Bool {false, true};
enum Bool isValid(char * str);

void main()
{
displayOutcome("()[]");
displayOutcome("(()[])");
displayOutcome("([)[])");
displayOutcome("([]]()");
displayOutcome("(([])[])");
displayOutcome("(([])[]");
}

/* Modfiy this function */
enum Bool isValid(char * str)
{
    int len = strlen(str);
    if(len%2) return false;
    
    int limit = len/2;
    char *stack = malloc(limit);
    int idx = 0;
    
    for(int i=0; i<len; ++i){
        char cur = str[i];
        if(cur=='(' || cur=='{' || cur=='['){
            if(idx == limit) return false;
            stack[idx++] = cur;
        }else{
            if(idx == 0) return false;
            if(cur == '}' && stack[idx-1] == '{' || cur == ']' && stack[idx-1] == '[' || cur == ')' && stack[idx-1] == '('){
                idx--;
            }else{
                return false;
            }
        }
    }
    
    free(stack);
    return idx==0;
}


void displayOutcome(char str[])
{
printf("String %s is",str);
if (isValid(str) == true) {
	printf(" valid\n");
}
else {
	printf(" invalid\n");
}

}


struct Stack * createStack(int size)
{
struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
stack->size = size;
stack->sp = -1;
stack->val = (char *) malloc(size*sizeof(char));
}

void destroyStack(struct Stack *stack)
{
free(stack->val);
free(stack);
}

char peek(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	return stack->val[stack->sp];
}
}

void push(struct Stack *stack, char newval)
{
if (stack->sp < stack->size) {
	stack->sp++;
	stack->val[stack->sp] = newval;
}
}

char pop(struct Stack *stack)
{
if (stack->sp < 0) {
	return NONCHAR;
}
else {
	char c = stack->val[stack->sp];
	stack->sp--;
	return c;
}
}

enum Bool isEmpty(struct Stack *stack)
{
if (stack->sp < 0) return true;
else return false;
}