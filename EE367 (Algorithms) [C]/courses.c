#include <stdlib.h>
#include <stdio.h>

enum bool {true, false};

/* You are to modify this function */
enum bool canFinish(int numCourses, int ** prereq, int prereqRowSize);

/* The next four functions create different prerequisite pairs */
int ** createCourses1(int *numCourses, int * prereqRowSize);
int ** createCourses2(int *numCourses, int * prereqRowSize);
int ** createCourses3(int *numCourses, int * prereqRowSize);
int ** createCourses4(int *numCourses, int * prereqRowSize);

void displayOutcome(int numCourses, int ** prereq, int prereqRowSize);
void destroyCourses(int ** prereq, int prereqRowSize);

void main()
{
int prereqRowSize;
int numCourses;

printf("Curriculum 1:\n");
int ** prereq = createCourses1(&numCourses, &prereqRowSize);
displayOutcome(numCourses, prereq, prereqRowSize);
destroyCourses(prereq, prereqRowSize);

printf("Curriculum 2:\n");
prereq = createCourses2(&numCourses, &prereqRowSize);
displayOutcome(numCourses, prereq, prereqRowSize);
destroyCourses(prereq, prereqRowSize);

printf("Curriculum 3:\n");
prereq = createCourses3(&numCourses, &prereqRowSize);
displayOutcome(numCourses, prereq, prereqRowSize);
destroyCourses(prereq, prereqRowSize);

printf("Curriculum 4:\n");
prereq = createCourses4(&numCourses, &prereqRowSize);
displayOutcome(numCourses, prereq, prereqRowSize);
destroyCourses(prereq, prereqRowSize);
}

enum bool canFinish(int numCourses, int ** prereq, int prereqRowSize)
{
int *check=(int*)calloc(numCourses,sizeof(int));
    int *flag=(int*)calloc(prereqRowSize,sizeof(int));
    int i=0;
    int j=0;
    while(i < prereqRowSize) {
        check[prereq[i][0]]++;
        i++;
    }
    while(j==0)
    {
        j=1;
        for(i=0;i<prereqRowSize;i++)
        {
            if(flag[i]==0)
            {
                if(check[prereq[i][1]]==0)
                {
                    flag[i]=1;
                    check[prereq[i][0]]--;
                    j=0;
                }
            }            
        }
    }
    for(i=0;i<prereqRowSize;i++)
    {
        if(flag[i]==0)
            return false;
    }
    return true;
}

void displayOutcome(int numCourses, int ** prereq, int prereqRowSize)
{
enum bool result = canFinish(numCourses, prereq, prereqRowSize);
if (result == true) printf("Curriculum is valid");
else printf("Curriculum is invalid");
printf("\n\n");
}

void displayPrereq(int ** prereq, int prereqRowSize)
{
printf("Prerequisites: \n");
for (int i=0; i<prereqRowSize; i++) {
	printf("%d -> %d\n", prereq[i][0], prereq[i][1]);
}
}

int ** createPrereqPairs(int prereqRowSize)
{
int ** prereq = (int **) malloc((prereqRowSize)*sizeof(int *));
for (int i=0; i<prereqRowSize; i++) {
	prereq[i] = (int *) malloc(2*sizeof(int));
}
return prereq;
}

int ** createCourses1(int *numCourses, int * prereqRowSize)
{
*numCourses = 2;
*prereqRowSize = 1;
printf("numCourses = %d, prereqRowSize = %d\n", *numCourses, *prereqRowSize);

int ** prereq = createPrereqPairs(*prereqRowSize);
prereq[0][0] = 1; prereq[0][1] = 0; 

displayPrereq(prereq, *prereqRowSize);
return prereq;
}

int ** createCourses2(int *numCourses, int * prereqRowSize)
{
*numCourses = 2;
*prereqRowSize = 2;
printf("numCourses = %d, prereqRowSize = %d\n", *numCourses, *prereqRowSize);

int ** prereq = createPrereqPairs(*prereqRowSize);
prereq[0][0] = 1; prereq[0][1] = 0; 
prereq[1][0] = 0; prereq[1][1] = 1; 

displayPrereq(prereq, *prereqRowSize);
return prereq;
}

int ** createCourses3(int *numCourses, int * prereqRowSize)
{
*numCourses = 6;
*prereqRowSize = 8;
printf("numCourses = %d, prereqRowSize = %d\n", *numCourses, *prereqRowSize);

int ** prereq = createPrereqPairs(*prereqRowSize);
prereq[0][0] = 0; prereq[0][1] = 1; 
prereq[1][0] = 0; prereq[1][1] = 2; 
prereq[2][0] = 3; prereq[2][1] = 2; 
prereq[3][0] = 3; prereq[3][1] = 4; 
prereq[4][0] = 3; prereq[4][1] = 5; 
prereq[5][0] = 4; prereq[5][1] = 2; 
prereq[6][0] = 4; prereq[6][1] = 5; 
prereq[7][0] = 4; prereq[7][1] = 1; 
displayPrereq(prereq, *prereqRowSize);

return prereq;
}

int ** createCourses4(int *numCourses, int * prereqRowSize)
{
*numCourses = 6;
*prereqRowSize = 7;
printf("numCourses = %d, prereqRowSize = %d\n", *numCourses, *prereqRowSize);

int ** prereq = createPrereqPairs(*prereqRowSize);
prereq[0][0] = 0; prereq[0][1] = 1; 
prereq[1][0] = 0; prereq[1][1] = 2; 
prereq[2][0] = 2; prereq[2][1] = 1; 
prereq[3][0] = 3; prereq[3][1] = 4; 
prereq[4][0] = 4; prereq[4][1] = 2; 
prereq[5][0] = 4; prereq[5][1] = 5; 
prereq[6][0] = 5; prereq[6][1] = 3; 
displayPrereq(prereq, *prereqRowSize);

return prereq;
}

void destroyCourses(int ** prereq, int prereqRowSize)
{
for (int i=0; i<prereqRowSize; i++) {
	free(prereq[i]);
}
free(prereq);
}