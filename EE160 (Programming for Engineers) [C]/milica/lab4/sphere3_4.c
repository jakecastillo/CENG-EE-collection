#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *ifp, *ofp;
   double data, result1, result2;

   ifp = fopen("in.txt", "r");			//open file for reading

   //if file cannot be opened, report error
   if (ifp == NULL) {		
     fprintf(stderr, "Can't open input file in.txt\n");
     exit(1);
   }


    ofp = fopen("out.txt", "w");			//open file for writing
    //if file cannot be opened, report error
    if (ofp == NULL) {
      fprintf(stderr, "Can't open output file out.txt\n");
      exit(1);
    }
//
//        // FSCANF WILL BE FORMATTED DEPENDING ON THE FORMAT OF YOUR INPUT FILE
//        // FPRINTF WILL BE FORMATTED THE WAY YOU WANT YOUR OUTPUT FILE
//        //The example below assumes your input file has 1 column of data, of double data type
//        // And then you write your data and result into output file. 
//
//
     printf("DATA\t  RESULT1\t  RESULT2\n");
	fprintf(ofp, "DATA\t  RESULT1\t  RESULT2\n");	
     while (fscanf(ifp, "%lf ", &data) != EOF) {
//
//        /* OR, you can use this while loop:
//        while (!feof(ifp)) {
//        	if (fscanf(ifp, "%lf  ", &data1) != 1)	//read 1 double number from file
//        			break;
//        			*/
  		//printf("read in %.2f \n", data1);
        					

     		// do whatever you want to do… for example, add 10 to the input data
		result1 = data + 10;
		result2 = data - 10;
       		
       		//print it to screen if you want to see what it does
        	printf("%.2f \t  %.2f \t  %.2f\n", data, result1, result2);	

		//print into file
        	fprintf(ofp, "%.2f \t  %.2f \t  %.2f\n", data, result1, result2);	//write 3 columns
	}

	//close the files
       	fclose (ifp); 
       	fclose (ofp); 

	return 0;
}
//
