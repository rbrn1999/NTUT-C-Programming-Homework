//
//  hw005.c
//  
//
//  Created by 劉學逸 on 3/9/20.
//

#include <stdio.h>
#include <ctype.h>

double point(){
    char input;
    scanf(" %c", &input);
    fflush(stdin);
    if(isdigit(input)){
        if(input == '1'){
            scanf("%*d");
            return 10;
        }
        return input - '0';
    } else if (input == 'A'){
        return 1;
    } else {
        return 0.5;
    }
}

int main(){
    double A = point() + point() + point();
    double B = point() + point() + point();
    
    if(A>10.5)
        A = 0;
    if(B>10.5)
        B=0;
    
    printf("%.1lf\n%.1lf\n",A ,B);
    
    if(A>B){
        printf("A贏\n");
    } else if(B>A){
        printf("B贏\n");
    } else {
        printf("平手\n");
    }
    return 0;
}
