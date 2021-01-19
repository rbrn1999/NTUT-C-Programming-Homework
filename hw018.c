#include <stdio.h>
#include <stdlib.h>


int main(){
    char gameStates[9][6];
    for (int i=0; i<9; i++)
        for (int j=0; j<5; j++)
            gameStates[i][j] = 0;
    
    int atBatCount;
    for (int i=0; i<9; i++) {
        scanf("%d", &atBatCount);
        for (int j=0; j<atBatCount; j++) {
            char space, hitState;
            scanf("%c%c", &space, &hitState);
            gameStates[i][j] = hitState;
        }
    }
    int inputOutCount;
    int inputHitter;
    scanf("%d%d", &inputOutCount, &inputHitter);
    int outs = 0;
    int outFlag = 0;
    int points = 0;
    int bases[7] = {-1,-1,-1,-1,-1,-1,-1};
    int hitterHome[9] = {0,0,0,0,0,0,0,0,0};
    for (int i=0; i<6; i++) {
        for (int j=0; j<9; j++) {
            switch(gameStates[j][i]){
                case '1':{
                    for (int k=3; k>=1; k--) {
                        bases[k] = bases[k-1];
                    }
                    bases[0] = j;
                    break;
                }
                case '2':{
                    for (int k=4; k>=2; k--) {
                        bases[k] = bases[k-2];
                    }
                    bases[1] = j;
                    bases[0] = -1;
                    break;
                }
                case '3':{
                    for (int k=5; k>=3; k--) {
                        bases[k] = bases[k-3];
                        bases[k-3] = -1;
                    }
                    bases[2] = j;
                    bases[1] = -1;
                    bases[0] = -1;
                    break;
                }
                case 'H':{
                    for (int k=6; k>=4; k--) {
                        bases[k] = bases[k-4];
                    }
                    bases[3] = j;
                    bases[2] = -1;
                    bases[1] = -1;
                    bases[0] = -1;
                    break;
                }
                case 'O':
                    outs++;
                    outFlag = 1;
                    break;
                default:
                    break;
            }
            for (int k=3; k<7; k++) {
                if (bases[k] != -1){
                    hitterHome[bases[k]]++;
                    points++;
                    bases[k] = -1;
                }
            }
            if (outFlag && outs%3 == 0) {
                for (int k=0; k<3; k++) {
                    bases[k] = -1;
                }
                outFlag = 0;
            }
            if (outs == inputOutCount){
                printf("%d\n", points);
                int hitCount = 0;
                int turns = i;
                if(j<inputHitter-1)
                    turns--;
                for (int k=0; k<=turns; k++) {
                    if(gameStates[inputHitter-1][k] != 'O')
                        hitCount++;
                }
                printf("%d,%d\n",hitCount,hitterHome[inputHitter-1]);
                exit(0);
            }
        }
    }
    return 0;
}
