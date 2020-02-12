#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("tokenize.txt", "r");
    if (fp == NULL)
	return -1;

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s\n", line);

    
    char delim[] = " , -, ,\n ";
    char* token;

    for(token = strtok(line, delim); token; token = strtok(NULL, delim)){
		printf("Token=%s\n", token);
		}	

    	}	

    fclose(fp);
    if (line)
        free(line);
    return 0;
}
