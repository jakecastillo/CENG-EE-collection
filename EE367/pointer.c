/*
 * Type your name here: Jake Castillo
 */

#include <stdlib.h>
#include <stdio.h>


/* Display an int array */
void display_int(int array[], int length) {

printf("Display integer array\n");
for (int i=0; i<length; i++) {
   printf("%d\n", array[i]);
}
printf("\n");
}

/* Display an int array using a pointer */
void display_int_ptr(int array[], int length) {

printf("Display integer array using a pointer\n");
for (int *p = array; p<array+length; p++) {
   printf("%d\n", *p);
}
printf("\n");
}

/* Display a char string */
void display_char(char string[], int length) {

printf("Display string\n");
for (int i=0; i<length; i++) {
   printf("%c", string[i]);
}
printf("\n");
}

/* Display a char string using a pointer */
void display_char_ptr(char string[], int length) {

printf("Display string using a pointer\n");
for (char *p = string; p<string+length; p++) {
   printf("%c", *p);
}
printf("\n");
}


void main() {

int  array[10] = {12, 34, 56, 78, 90, 21, 43, 65, 87, 90};
char string[12] ="Hello World\n";

display_int(array, 10);
display_int_ptr(array, 10);
display_char(string, 12);
display_char_ptr(string, 12);

}
