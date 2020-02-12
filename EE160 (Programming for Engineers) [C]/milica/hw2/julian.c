//file: julian.c
//team: Team Jake
//login: jakecast
//date: 9/29/16

/*  Leap year function  */
int is_leap(int year){
    /*  Determine if leap year  */
    if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
        return 1;
    } else {
        return 0;
    }
}

/*  Number of days in a month function  */
int days_in_month(int month, int year){
  int leap_year;
  
    /*  Determine if leap year or not  */
    leap_year = is_leap(year);
    
    /*  Month 2 and leap year = 29 days  */
    if(month == 2 && leap_year == 1){
        return 29;
    }  
    
    /*  Month 2 and not leap year = 28 days  */
    if(month == 2 && leap_year ==0){
        return 28;
    }
    
    /*  Months 4, 6, 9, and 11 = 30 days  */
    if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    } else {
        return 31;      //Months 1,3,5,7,8,10,12 = 31 days
    }
}

/* Julian date function */ int julian_date(int day, int month, int year)
{ int month_days = 0; 
  int day_of_the_year = 0;
  int total_days; int sum;
	 month = month - 1;
	 while(month > 0) 
		{ 
		month_days = days_in_month(month, year);
		sum = sum + month_days;
		month = month - 1; 
		} 
		day_of_the_year = sum + day; 
		return day_of_the_year;
 }


