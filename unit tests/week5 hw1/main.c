#include <stdio.h>
#include <math.h>
#include <assert.h>
double computeBMI(int kg, int height) {
    double BMI = 0.0, M = height/100.0;
    if (kg<=0 || height<=0)
        return 0;
    BMI = round(100*kg/(M*M))/100;
    if (BMI <18.5)
        return -1;
    if (BMI >24)
        return -2;
    return BMI;
}

int main(){
    int kg = 52, height = 155;
//    double except = 21.64f
    double result = computeBMI(kg, height);
    kg = 0; height = 1;
    result = computeBMI(kg, height);
    kg = 1; height = 0;
    result = computeBMI(kg, height);
    kg = 300; height = 160;
    result = computeBMI(kg, height);
    kg = 40; height = 170;
    result = computeBMI(kg, height);
    
    return 0;
}
