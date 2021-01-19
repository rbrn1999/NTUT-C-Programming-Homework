//
//  hw006.c
//  
//
//  Created by 劉學逸 on 3/10/20.
//

#include <stdio.h>

int main(){
    int cources[3][4] = {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    
    for(int i=0; i<3; i++){
        int hours;
        scanf("%d%d", &cources[i][0], &hours);
        for(int j=1; j<=hours; j++){
            scanf("%d",&cources[i][j]);
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[0][i] == cources[1][j] && cources[0][i]){
                printf("%d and %d conflict on %d\n", cources[0][0], cources[1][0], cources[0][i]);
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[0][i] == cources[2][j] && cources[0][i]){
                printf("%d and %d conflict on %d\n", cources[0][0], cources[2][0], cources[0][i]);
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(cources[1][i] == cources[2][j] && cources[1][i]){
                printf("%d and %d conflict on %d\n", cources[1][0], cources[2][0], cources[1][i]);
            }
        }
    }
}
