//
//  hw008.c
//  
//
//  Created by 劉學逸 on 3/17/20.
//

#include <stdio.h>
void print_1(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for (int j=1; j<=i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    for(int i=n; i>0; i--){
        for (int j=i; j>0; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        for (int j=1; j<=i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void print_2(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for (int j=1; j<=i; j++) {
            printf("%d", j);
        }
        for (int j=i-1; j>0; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    for(int i=n-1; i>0; i--){
        for (int j=0; j<i-1; j++) {
            printf("_");
        }
        for (int j=n-i; j>0; j--) {
            printf("%d", j);
        }
        for (int j=2; j<=n-i; j++) {
            printf("%d", j);
        }
        for (int j=0; j<i-1; j++) {
            printf("_");
        }
        printf("\n");
    }
    for(int i=0; i<n-1; i++){
        for (int j=0; j<i; j++) {
            printf("_");
        }
        for (int j=n-(i+1); j>0; j--) {
            printf("%d", j);
        }
        for (int j=2; j<=n-(i+1); j++) {
            printf("%d", j);
        }
        for (int j=0; j<i; j++) {
            printf("_");
        }
        printf("\n");
    }
}

int main(){
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            print_1();
            break;
        case 2:
            print_2();
            break;
        default:
            break;
    }
}
