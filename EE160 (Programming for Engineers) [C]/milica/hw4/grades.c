/* grades.c
 *  * Minami Morita, Fernanda Hennig, Jake Castillo
 *   * Team Jake
 *    *   */

int extractgrades(FILE *ifp)
{
}

char assignletter(int grade)
{       
        if (grade>=90) 
                return A;
        else if (grade>=80)
                return B;
        else if (grade>=70)
                return C;
        else if (grade>=60)
                return D;
        else    
                return F;
}

double average(int grade[])
{       
        int tempsum=0;
        for(int i=0; i<grade.length; i++)

                tempsum=tempsum+grade[i];

        double average=tempsum/i;
        return average;
}

int min(int grade[])
{
        int min=INFINITY;
        for(int i=0; i<grade.length; i++)
                if(min>grade[i])
                        min=grade[i];

        return min;
}

int max(int grade[])
{
        int max=-INFINITY;
        for(int i=0; i<grade.length; i++)
                if(max<grade[i])
                        max=grade[i];

        return max;
}

double stddev(int grade[])
{
        int temp=0;
        int sum=0;
        int avg= average(grade);
        for(int i=0; i<grade.length; i++)
        {
                temp=grade[i]-avg;
                sum=pow(temp,2);
        }

        double stddev=sum/sqrt(i);
        return stddev;
}

int total(int grade[])
{
        int sum=0;
        for(int i=0; i<grade.length; i++)
	{
                sum=sum+grade[i];
	}
        return sum;
}

int extractcolumn(int grade[][MAXSIZE], int c, int temparray[])
{
	for(r=0, r<grade.length, r++)
	{
	temparray[r]=grade[r][assignmentcounter]
	}
	return temparray[r]
}

int printgrades()
{
}
