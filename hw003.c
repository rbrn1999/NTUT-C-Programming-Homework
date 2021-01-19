#include <stdio.h>

int main(){
    int month_1, month_2;
    int x, y;
    scanf("%d%d%d%d", &month_1, &month_2, &x, &y);

    double labor = y * 0.05;
    int temp = labor * 100;
    labor = (double)temp / 100.0;

    double tax = x * (month_1 + month_2) * 0.08;
    temp = tax * 100;
    tax = (double)temp / 100.0;

    double total = x * (month_1 + month_2) - tax - labor;
    printf("%.1lf\n%.1lf\n%.1lf\n", total, labor, tax);
    return 0;
}