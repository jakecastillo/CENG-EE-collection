
/*	File:  romanutil.h
	by:    Tep Dobry
	date:  13 Mar 16
	Mod :  Jake Castillo
*/

/*  This file contains the  prototypes for utilities used in
	 converting roman numerals.
*/


int is_roman(char c);
/*  tests if c is a valid roman numeral, returns true or false  */

int convert_roman(char c);
/*  converts roman numeral c to its value, NULL if invalid  */

char toUpper(char);
/*  converts a character to upper case  */

int skipBlanks(void);
// skips over white space
