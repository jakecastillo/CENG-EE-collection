/*      File : maxmin.c
        By   : Jake Castillo
        login: jakecast
        team : Hawaiians
        Date : 2/25/15                 */

float min(float n1, float n2){
  float minimum;
  
    if(n1 < n2){
        minimum = n1; //first value is less than
    } else {
        minimum = n2; //second value is less than
    }
    return minimum;
}

float max(float n1, float n2){
  float maximum;
    
    if(n1 > n2){
        maximum = n1; //first value is more than
    } else {
        maximum = n2; //second value is more than
    }

    return maximum;
}
