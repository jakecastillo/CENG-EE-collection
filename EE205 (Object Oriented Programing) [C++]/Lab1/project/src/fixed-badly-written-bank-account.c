#include <stdio.h>
#include <stdlib.h>

/*
 * A badly-written bank account program in C.
 *
 * - Can you pinpoint what makes this program bad?
 * - There is a bug in the program in the "show
 *   transaction" part of the program. Can you
 *   find and fix it?
 */
int main(int argc, char* argv[]) {
    fflush(stdout);
    int dn = 0;
    printf("Initial balance, dude ");
    fflush(stdout);
    struct {
        double b;
        double* pb;
        double d;
        double w;
    } a;
    scanf(" %lf", &a.b); 
    char c;
    c=0;
    a.d=0;
    a.w=0;
    while (!dn) {
        a.pb = &a.b;
        goto start_again;
        set_dn:
            dn = 0;
        start_again:
        printf("The actions, dude:\n"
               "d: deposit money, dude\n"
               "w: withdraw money, dude\n"
               "g: get balence, dude\n"
               "s: show transations, dude\n"
               "q: quit, dude\n");
        if (dn) break;
        printf("==========");
        printf("==========");
        printf("==========");
        printf("==========");
        printf("\nWhatcha want, dude ");
        fflush(stdout);
        scanf(" %c", &c);
        if (c == 'd') {
            a.pb = NULL;
            a.pb = &a.b;
            printf("how much money, dude ");
            fflush(stdout);
            scanf(" %lf", &a.d); *a.pb = a.b+a.d;
            printf("balance, dude ");
            printf("%lf\n", *a.pb);
            printf("deposited money, dude\n");
            fflush(stdout);
            goto set_dn;
            dn = 0;
        } else if (c == 'w') {
            printf("how much money, dude ");
            fflush(stdout);
            scanf(" %lf", &a.w); a.b = a.b-a.w;
            printf("balance, dude %lf\n", a.b);
            printf("withdrew money, dude\n");
            fflush(stdout);
            goto set_dn;
            dn = 0;
        } else if (c == 'g') {
            printf("balance, dude ");
            printf("%lf\n", a.b);
            fflush(stdout);
            dn = 1;
            goto set_dn;
            dn = 0;
        } else if (c == 's') {
            printf("last deposit, dude %lf\n", a.d);
            printf("last withdrawl, dude %lf\n", a.w);
            printf("balance, dude %lf\n", a.b);
            printf("showed transactions, dude\n");
            fflush(stdout);
            goto set_dn;
            dn = 0;
        } else if (c == 'q') {
            dn = 1;
        }
    }
    printf("ok bye, dude\n");
    fflush(stdout);
    return 0;
}
