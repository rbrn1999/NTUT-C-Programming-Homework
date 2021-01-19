//
//  hw007.c
//  
//
//  Created by 劉學逸 on 3/17/20.
//

#include <stdio.h>
#include <math.h>
int isPrime(int num){
    if(num<=1)
        return 0;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

void printPrime(int n){
    int counter = 0;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            counter++;
            if (!(counter % 3)) {
                printf("%d\n", i);
            }
        }
    }
    if(counter<3){
        printf("含括的質數未達三個\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printPrime(n);
}
