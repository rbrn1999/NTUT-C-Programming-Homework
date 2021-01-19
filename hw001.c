#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c; //ax^2 + bx + c
    scanf("%lf%lf%lf",&a,&b,&c);
    double x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a) ;
    double x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a) ;
    printf("%.1lf\n",x1);
    printf("%.1lf\n",x2);
    return 0;
}