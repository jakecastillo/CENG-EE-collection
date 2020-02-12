
#include <stdio.h> 

#define SIZE 10
#define M 3
int  identity(int m[ ][M], int N) ;

int main() {

	FILE *ifp, *ofp;

	ifp = fopen("input.txt", "r");	//open file for reading
	//if file cannot be opened, report error
	if (ifp == NULL) {		
		fprintf(stderr, "Can't open input file in.txt\n");
		return -1;
	}

	int a[SIZE][M];		//make SIZE sufficiently large 
	int N;
	int i = 0;
	int j = 0;
	int num_rows = 0;

	//read from file, store in matrix
	while (fscanf(ifp, "%d ", &a[i][j]) != EOF) {
		j++;
		if (j == M) { i++; j = 0; num_rows++;}

	}
	//at this point, we counted all rows
	N = num_rows;   	//It must be that N <= SIZE

	//print the matrix you read in
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}





	//close the file
	fclose (ifp); 
}


int  identity(int m[ ][M], int N) {


	return 0;
}
