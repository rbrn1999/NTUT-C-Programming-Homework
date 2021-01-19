#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 10000


void print(int *result){
    int flag = 1;
    for (int i=MAX-1; i>=0; i--) {
        if (flag) {
            if (*(result+i)) {
                flag = 0;
                printf("%d", *(result+i));
            }
            continue;
        }
        printf("%d", *(result+i));
    }
    if(flag)
        printf("0");
    
    printf("\n");
}
int* add(int *num1, int size1, int *num2, int size2){
    int *result = calloc(MAX, sizeof(int));
    for (int i=0; i<size1; i++) {
        *(result+i) = *(num1+i);
    }
    for (int i=size1; i<MAX; i++) {
        *(result+i) = 0;
    }
    for (int i=0; i<size2; i++) {
        *(result+i) += *(num2+i);
        if (*(result+i)>9) {
            *(result+i+1) += *(result+i)/10;
            *(result+i) %= 10;
        }
    }
    return result;
}
int compare(int *num1, int size1, int *num2, int size2){
    if (size1>size2)
        return 1;
    if (size1<size2)
        return -1;
    for(int i=size1; i>=0; i--){
        if (*(num1+i) > *(num2+i))
            return 1;
        if (*(num1+i) < *(num2+i))
            return -1;
    }
    return 0;
    
}
void printSub(int *num1, int size1, int *num2, int size2){
    int sign = 0;
    if (compare(num1, size1, num2, size2)<0) {
        sign = 1;
        int *temp = num1;
        num1 = num2;
        num2 = temp;
        int tmp = size1;
        size1 = size2;
        size2 = tmp;
    }
    int result[MAX];
    for (int i=0; i<size1; i++) {
        result[i] = *(num1+i);
    }
    for (int i=size1; i<MAX; i++) {
        result[i] = 0;
    }
    for (int i=0; i<size2; i++) {
        result[i] -= *(num2+i);
        if (result[i]<0) {
            result[i+1] -= 1;
            result[i] += 10;
        }
    }
    for (int i=size2; i<size1; i++) {
        if (result[i]<0) {
            result[i+1] -= 1;
            result[i] += 10;
        }
    }
    if (sign)
        printf("-");
    print(result);
}

int* mul(int *num1, int size1, int *num2, int size2){
    int *result = (int*)malloc(sizeof(int)*MAX);
    int temp[size1+size2];
    for (int i=0; i<MAX; i++)
        *(result+i) = 0;
    for (int i=0; i<size2; i++) {
        for (int k=0; k<size1+size2; k++)
            temp[k] = 0;
        for (int j=0; j<size1; j++) {
            temp[i+j] += *(num1+j) * *(num2+i);
            temp[i+j+1] += temp[i+j] / 10;
            temp[i+j] %= 10;
        }
        result = add(result, MAX, temp, size1+size2);
    }
    return result;
}

int main(){
    int mode;
    scanf("%d", &mode);
    char input[MAX];
    scanf("%s", input);
    int size1 = (int)strlen(input);
    int num1[size1];
    for (int i=0; i<size1; i++) {
        num1[size1-1-i] = input[i] - '0';
    }
    scanf("%s", input);
    int size2 = (int)strlen(input);
    int num2[size2];
    for (int i=0; i<size2; i++) {
        num2[size2-1-i] = input[i] - '0';
    }
    switch (mode) {
        case 1:
            print(add(num1, size1, num2, size2));
            break;
        case 2:
            printSub(num1, size1, num2, size2);
            break;
        case 3:
            print(mul(num1, size1, num2, size2));
            break;
        default:
            break;
    }
    return 0;
}
