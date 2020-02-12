#include <stdlib.h>

#include <stdio.h>

#define MAXLENGTH 100		/* Max length of a string */

int one_away (char str1[], char str2[]);
int str_length (char str[], int max_length);

char str[] = "pale";
char strA[] = "ple";
char strB[] = "pales";
char strC[] = "bale";
char strD[] = "bake";


void
main ()
{
  printf ("'%s' and '%s' have result %d\n", str, strA, one_away (str, strA));
  printf ("'%s' and '%s' have result %d\n", str, strB, one_away (str, strB));
  printf ("'%s' and '%s' have result %d\n", str, strC, one_away (str, strC));
  printf ("'%s' and '%s' have result %d\n", str, strD, one_away (str, strD));
}

int
str_length (char str[], int max_length)
{
  int length;
  for (length = 0; (str[length] != '\0') && (length < max_length); length++);
  return length;
}

int
one_away (char str1[], char str2[])
{

  int len1 = str_length (str1, MAXLENGTH);	//Length of string 1
  int len2 = str_length (str2, MAXLENGTH);	//Length of string 2
  int charDiff = 0;		//Character difference
  int lenDiff = len1 - len2;	//Difference of the two lengths

  if (abs (lenDiff) > 1)	//If the difference of the length is greater than 1
    return 0;			//Then the strings are not one away
  else if (lenDiff < 0)
    {				//Only insert
      for (int i = 0; i < len1; i++)
	{			//Itterates through and checks how many characters are different
	  if (str1[i] != str2[i + charDiff])
	    {
	      charDiff++;

	    }
	  if (charDiff > 1)	//If the characters are more than one off
	    return 0;		//Then the strings are not one away
	}
      return 1;			//Otherwise the strings are one away
    }
  else if (lenDiff > 0)
    {				//Only delete
      for (int i = 0; i < len2; i++)
	{
	  if (str1[i + charDiff] != str2[i])
	    {
	      charDiff++;
	    }
	  if (charDiff > 1)
	    return 0;
	}
      return 1;
    }
  else if (lenDiff == 0)
    {				//Only replace
      for (int i = 0; i < len1; i++)
	{
	  if (str1[i] != str2[i])
	    {
	      charDiff++;
	    }
	  if (charDiff > 1)
	    return 0;
	}
      return 1;
    }
}
