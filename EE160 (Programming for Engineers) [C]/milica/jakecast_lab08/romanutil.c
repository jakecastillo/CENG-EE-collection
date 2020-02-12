
/*	File:  roman.c
	by:    Tep Dobry
	date:  13 Mar 16
	mod :  Jake Castillo
*/

/*  This file contains the functions used to read and convert a number
	in roman numerals.
*/

#include <stdio.h>
#include "roman.h"
#include "romanutil.h"
#include "tfdef.h"
#include "chrutil.h"


int is_roman(char c)
/*  This function is given a character and returns true if it is
	a valid roman numeral, flase otherwise.  */
{  
	/*  convert digit to upper  */
	c = toUpper(c);
	/*  test the digit  */
	switch(c)
	{  case 'M':
	   case 'D':
	   case 'C':
	   case 'L':
	   case 'X':
	   case 'V':
	   case 'I':  return TRUE;
	   default :  return FALSE;
	}
}



int convert_roman(char c)
/*  This function is given a roman numeral and returns its value.
	NULL is returned if the character is not valid  */
{  int digit;

	/*  convert digit to upper  */
	c = toUpper(c);
	/*  convert the digit  */
	switch(c)
	{  case 'M':
		digit = M;
		break;
	   case 'D':
		digit = D;
		break;
	   case 'C':
		digit = C;
		break;
	   case 'L':
		digit = L;
		break;
	   case 'X':
		digit = X;
		break;
	   case 'V':
		digit = V;
		break;
	   case 'I':  
		digit = I;
		break;
	   default :  
		digit = (int)NULL;
	}

	/*  and return its value  */
	return digit;
}


char toUpper(char c)
{
	if(IS_LOWER(c)) return c - 'a' + 'A';
	return c;
}

int skipBlanks(void)
{
  int c;

        c = getchar();
        while (c == ' ' || c == '\t')
                c = getchar();
        return c;
}

