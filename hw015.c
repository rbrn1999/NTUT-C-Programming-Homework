#include <stdio.h>
#include <math.h>
#include <string.h>

int gcd(int n1, int n2) {
    if (n2)
        return abs(gcd(n2, n1 % n2));
    else
        return abs(n1);
}

int* parseFraction(char* num){
    int *result = calloc(2,sizeof(int));
    *(result) = atoi(num);
    while (*num != '/') {
        num = num + 1;
    }
    num = num + 1;
    *(result+1) = atoi(num);
    //reduction of fraction
    int gc_d = gcd(*result, *(result+1));
    *result /= gc_d;
    *(result+1) /= gc_d;
    return result;
}

int* addition(int* num1, int* num2){
    int *result = calloc(2,sizeof(int));
    int gc_d = gcd(*(num1+1), *(num2+1));
    *num1 *= abs((*(num2+1)/gc_d));
    *num2 *= abs((*(num1+1)/gc_d));
    *(num1+1) = *(num2+1) = *(num1+1) * *(num2+1) / gc_d;
    *result = *num1 + *num2;
    *(result+1) = *(num1+1);
    gc_d = gcd(*result, *(result+1));
    *result /= gc_d;
    *(result+1) /= gc_d;
    return result;
}

int* multiply(int* num1, int* num2){
    int *result = calloc(2,sizeof(int));
    *result = *num1 * *num2;
    *(result+1) = *(num1+1) * *(num2+1);
    int gc_d = gcd(*result, *(result+1));
    
    *result /= gc_d;
    *(result+1) /= gc_d;
    return result;
}

void printResult(int* result){
    if(*(result+1) == 0)
        printf("ERROR\n");
    else if(*result == 0)
        printf("0\n");
    else if(abs(*result) < abs(*(result+1)))
        printf("%d/%d\n", *result, *(result+1));
    else{
        int num = *result / *(result+1);
        *result %= *(result+1);
        *result = abs(*result);
        if(*result == 0)
            printf("%d\n", num);
        else
            printf("%d(%d/%d)\n", num, *result, *(result+1));
    }
}

int main() {
    int continueFlag = 1;
    while (continueFlag) {
        char s1[10], s2[10];
        scanf("%s", s1);
        scanf("%s", s2);
        int* num1 = parseFraction(s1);
        int* num2 = parseFraction(s2);
//        printf("%s\n%s\n%d/%d\n%d/%d\n", s1, s2, *num1, *(num1+1), *num2, *(num2+1));
        int* result = calloc(2,sizeof(int));;
        char op;
        scanf(" %c", &op);
        switch (op) {
            case '+':{
                result = addition(num1, num2);
                break;
            }
            case '-':{
                *(num2) *= -1;
                result = addition(num1, num2);
                *(num2) *= -1;
                break;
            }
            case '*':{
                result = multiply(num1, num2);
                break;
            }
            case '/':{
                int temp = *num2;
                *num2 = *(num2+1);
                *(num2+1) = temp;
                if (*(num2+1) < 0){
                    *num2 *= -1;
                    *(num2+1) *= -1;
                }
                result = multiply(num1, num2);
                break;
            }
            default:
                break;
        }
        printResult(result);
        char flag;
        scanf(" %c", &flag);
        if (flag != 'y')
            continueFlag = 0;
    }
    return 0;
}
