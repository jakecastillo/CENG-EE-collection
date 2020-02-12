/*      File : cars.c           *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 2/4/15                 */

/*  A program to compute the cost of a new Porsche   */

#include <stdio.h>

main()
{  /*  program constants   */
  float discount_rate = 0.12;
  float luxury_tax_base = 30000.00;
  float luxury_tax_rate = 0.10;
  float sales_tax_rate = 0.0417;

  float  sticker_price;            /* sticker price of the car */
  float discount_price;           /* discounted price of item */
  float taxes;                    /* tax is luxury tax + sales tax */
  float final_cost;               /* cost including sales tax */

        /*  Get sticker price  */
        printf("Enter sticker price: ");
        scanf("%f", &sticker_price);

        /*  Compute discount price  */
        discount_price = sticker_price - (sticker_price * discount_rate);

        /*  Compute taxes  */
        taxes = (discount_price - luxury_tax_base) * luxury_tax_rate +
                 (discount_price * sales_tax_rate);

        /*  Compute final cost  */
        final_cost = discount_price + taxes;

        /* Output results  */
        printf("Sticker price:\t\t\t\t\t%8.2f\n", sticker_price);
        printf("Price after %.1f%% discount:\t\t\t%8.2f\n",
               discount_rate * 100, discount_price);
        printf("Taxes (luxury and sales):\t\t\t%8.2f\n", taxes);
        printf("Total cost:\t\t\t\t\t%8.2f\n", final_cost);

}
