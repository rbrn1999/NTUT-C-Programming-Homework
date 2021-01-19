//
//  main.c
//  c_playground
//
//  Created by 劉學逸 on 3/23/20.
//  Copyright © 2020 劉學逸. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int binaryToDec(int num){
    int e = 0;
    int result = 0;
    while (num>0) {
        result += (num % 10) * pow(2,e);
        num /= 10;
        e++;
    }
    return result;
}
int decToBinary(int num){
    int e = 0;
    int result = 0;
    while (num>0) {
        result += (num % 2) * pow(10,e);
        num /= 2;
        e++;
    }
    return result;
}

int C(int m){
    int respondCount = 0;
    while (!(m == 0) && !(m == 1)) {
        if (m%2)
            m = (m+1)/2;
        else
            m /= 2;
        respondCount++;
    }
    return respondCount;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int mode = 0;
    while(!mode){
        int input;
        scanf("%d", &input);
        printf("%04d\n", decToBinary(C(binaryToDec(input))));
        scanf("%d", &mode);
    }
    return 0;
}
