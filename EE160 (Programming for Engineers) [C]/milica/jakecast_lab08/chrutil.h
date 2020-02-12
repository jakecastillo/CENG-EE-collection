/* File: chrutil.h */
/*   This file contains various  macros and prototypes for character processing */

#define   ERROR     -2

#define   IS_DIGIT(c)   ((c) >= '0' && (c) <= '9')
#define   IS_LOWER(c)   ((c) >= 'a' && (c) <= 'z')
#define   IS_UPPER(c)   ((c) >= 'A' && (c) <= 'Z')
#define   IS_WHITE_SPACE(c)   ((c) == ' ' || (c) == '\t' || (c) == '\n')
#define   IS_PRINT(c)   ((c) >= 32 && (c) < 127)

#define  LOWER     0
#define  UPPER     1
#define  DIGIT     2
#define  PUNCT     3
#define  SPACE     4
#define  CONTROL   5
#define  SPECIAL   6


int dig_to_int(char ch);
char int_to_dig(int n);
char uppercase(char ch);
int getint();

int delimitp(char c);
int whitep(char c);
int punctp(char c);
int vowelp(char c);
int letterp(char c);
int illegal(char c);      /* Tests if c is legal. */


