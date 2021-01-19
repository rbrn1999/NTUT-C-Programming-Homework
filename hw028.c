#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

double f1(double x, double a){
    return sqrt(a - pow(x, 2));
}
double f2(double x, double a){
    return (a * pow(x, 3) + 7 * x) / sqrt(a+x);
}

double myFunc(double (*function)(double x, double a), double a, double p, double q, unsigned long long n){
    double h = (q-p)/n;
    double result = 0;
    double x = p+h;
    result = fabs(function(p, a)) + fabs(function(q, a));
    for(int i=1; i<n; i++){
        result += 2 * fabs(function(x, a));
        x += h;
    }
    result *= fabs(h) / 2;
    return result;
}

int main(){
    int continueFlag = 1;
    while (continueFlag) {
        double a, p ,q, prev, cur, err;
        cur = INT_MAX;
        int mode;
        unsigned long long n = 1;
        double (*function)(double, double);
        scanf("%d", &mode);
        
        
        switch (mode) {
            case 0:
                function = NULL;
                continueFlag = 0;
                break;
            case 1:
                function = f1;
                break;
            case 2:
                function = f2;
                break;
            default:
                function = NULL;
                break;
        }
        if (!continueFlag)
            break;
        
        scanf("%lf%lf%lf%lf", &a, &p, &q, &err);
        err = pow(10, err * (-1));
        
        do {
            prev = cur;
            cur = myFunc(function, a, p, q, n);
            n *= 2;
        } while (fabs(cur - prev) > err);
        
        printf("%.12lf\n", cur);
    }
    return 0;
}
