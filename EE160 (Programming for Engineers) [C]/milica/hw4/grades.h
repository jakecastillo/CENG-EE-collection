/*grades.h
 *  * Minami Morita, Fernanda Hennig, Jake Castillo
 *   * Team Jake
 *    *  */
#define MAXSIZE 9999
int extractgrades(FILE *ifp);

char assignletter(int grade[]);

double average(int grade[]);

int min(int grade[]);

int max(int grade[]);

double stddev(int grade[]);

int total(int grade[]);

int temparray(int grade[][MAXSIZE], int c, int temparray[]);

int printgrades();
