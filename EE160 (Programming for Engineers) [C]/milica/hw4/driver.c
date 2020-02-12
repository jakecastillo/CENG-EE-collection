/*driver.c
 *  * Minami Morita, Fernanda Hennig, Jake Castillo
 *   * Team Jake */

#include <stdio.h>
#include "grades.h"
#include<stdlib.h>
#include<string.h>


int main()
{
        FILE *ifp, *ofp;
        char * line = NULL;
        size_t len=0;
        ssize_t read;

        ifp=fopen("input.txt","r");

        if (ifp==NULL)
        {
                fprintf(stderr, "Can't open input file input.txt");
                return -1;
        }

        int studentcounter=0;
        int assignmentcounter=0;

        while((read=getline(&line, &len, ifp)) != -1)
        {
                studentcounter++;
        }

        char delim[]=" ";
        char* token; 
                
        for(token=strtok(line,delim); token; token=strtok(NULL,delim))
        { 
                printf("assignmentcounter=%i Token=%s \n", assignmentcounter, token);
                assignmentcounter++;
        }
                
        assignmentcounter=assignmentcounter-3; /*because first two columns are for names and one more because it goes through the loop one extra time */

        printf("studentcounter check=%i \n",studentcounter); 
        printf("assignmentcounter check %i \n", assignmentcounter);

        rewind(ifp);

        int grades[studentcounter][assignmentcounter];
        char students[studentcounter][MAXNAME];

        for(int k=0; k<studentcounter;k++)
        {
                for(int i=0, int m=0; i<assignmentcounter;i++)
                        if(i==0||i==1)
                        {
                                if(fscanf("%s",&studentsFN[i])!=EOF){
				}
                                else{
                                        return -1;
				}
                        }
				if(fscanf("%s", &studentsLS[i])!=EOF){
				}
				else{
					return -1;
				}
                        else
                        {
                                if(fscanf("%i",&grade)!=EOF)
                                {
                                        if(grade>=0)
                                        {
                                                grades[k][m]=grade;
                                                m++;
                                        }
                                        else
                                                printf("error: negative grade");
                                }
                                else
                                        return-1;
                        }
        }
	
	

        int[]studentavg=new int[studentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentavg[i]=average(grades[][i]);
        }

        int[]studentmin=new int[studentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentmin[i]=min(grades[][i]);
        }

        int[]studentmax=new int[studentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentmax[i]=max(grades[][i]);
        }

        int[]studentstd=new int[studentcounter];

        for(int i=0; i<studentcounter;i++)
        {
                studentstd[i]=stddev(grades[][i]);
        }

        int[]studenttotal=new int[studentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studenttotal[i]=total(grades[][i]);
        }

        int[]assignmentavg=new int[assignmentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentavg[i]=average(grades[i][]);
        }

        int[]assignmentmin=new int[assignmentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentmin[i]=min(grades[i][]);
        }

        int[]assignmentmax=new int[assignmentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentavg[i]=max(grades[i][]);
        }

        int[]assignmentstd=new int[assignmentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studentstd[i]=stddev(grades[i][]);
        }

        int[]assignmenttotal=new int[assignmentcounter];
        for(int i=0; i<studentcounter;i++)
        {
                studenttotal[i]=total(grades[i][]);
        }

        fclose(ifp);
        fclose(ofp);
}
