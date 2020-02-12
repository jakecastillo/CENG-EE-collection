
#include <stdio.h> 

#define SIZE 100

int search(int a[], int N, int v, int result[]);

int main() {

    FILE *ifp, *ofp;

    ifp = fopen("in.txt", "r");	//open file for reading
    //if file cannot be opened, report error
    if (ifp == NULL) {		
	fprintf(stderr, "Can't open input file in.txt\n");
	return -1;
    }

    int a[SIZE];		//make SIZE sufficiently large 
    int N, v, s;
    int i = 0;

    //read from file, store in matrix
    while (fscanf(ifp, "%d ", &a[i]) != EOF) {
	i++;
    }
    //at this point, we counted all rows
    N = i;   	//It must be that N <= SIZE

    int result[N];

    printf("Enter number to search for: "); //user enters v
    scanf("%d", &v);
    s = search(a, N, v, result);//search the array
    //print the array you read in
    printf("numbers: ");
    for (i = 0; i < N; i++) {
	printf("%d\t", a[i]);
    }
    printf("\n");
    printf("index = %d\n", s);
    printf("results: ");
    for (i = 0; i < s; i++) {
	printf("%d \t", result[i]);
    }
    printf("\n");
    //close the file
    fclose (ifp); 
}

int search(int a[], int N, int v, int result[]){
    int i, counts=0;
    for( i = 0; i < N; i++){
	if(a[i] == v){
	    result[counts] = i;
	    counts++;
	}
    }
    return counts;
}

