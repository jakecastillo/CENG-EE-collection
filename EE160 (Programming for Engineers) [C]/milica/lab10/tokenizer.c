#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main() {
	char str[] = "this, is the string - I want to parse";
	char delim[] = " ,-";   //delimiters are space comma and hyphen
				//put any delimiters you want
	char* token;

	for (token = strtok(str, delim); token; token = strtok(NULL, delim))
	{
	    printf("token=%s\n", token);
    	}
}
