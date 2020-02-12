/*      File : driver1.c       *
 *       *      By   : Jake Castillo    *
 *        *      login: jakecast           *
 *         *      team : Hawaiians        *
 *          *      Date : 14 Apr 15         */

#include<stdio.h>
#include "trig.h"

main(){
  /*  Declare variables  */
    float radians;
      double angle;
        
            /*  Ask user for first angle in radians  */
                printf("Enter an angle in radians (EOF to quit): ");
                    
                        /*  While there are more angles  */
                            while(scanf("%f", &radians) != EOF){
                                    
                                                                                /*  Calculations  */
                                                    angle = cos_angle(radians);
                                                            
                                                                    /*  Print result  */
                                                                            printf("The cos is %f\n", angle);
                                                                                    
                                                                                            /*  Ask user for another angle in radians  */
                                                                                                    printf("Enter an angle in radians (EOF to quit): ");
                                                                                                        }
                                                                                                            
                                                                                                                /*  Clean up screen  */
                                                                                                                    printf("\n");
                                                                                                                        
                                                                                                                        }
