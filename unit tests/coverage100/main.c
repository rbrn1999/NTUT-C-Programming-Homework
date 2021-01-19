#include <stdio.h>
#include <math.h>
#include <assert.h>
double computeBMI(int kg, int cm) {
    double BMI = 0.0, M = cm/100.0;
    if (kg<=0 || M<=0)
        return -1;
    BMI = round(100*kg/(M*M))/100;
    return BMI;
}
int main() {
    int kg = 52, cm = 155;
    double expectedResult = 21.64f;
    double result = computeBMI(kg, cm);
    assert(fabs(result-expectedResult)<0.0001);
    kg = -1;
    cm = -1;
    expectedResult = -1;
    result = computeBMI(kg, cm);
    printf("Hi\n");
    return 0;
}
