#include <stdio.h>

int main(){
    char input;
    int state = 0, out = 0;
    int i;
    for(i=0;i<5;i++){
        scanf(" %c", &input);
        // fflush(stdin);
        if(input == 'O'){
            out++;
        } else if(input == 'H') {
            state = 0;
        } else {
            int hit = input - '0';
            state = state << hit;
            state = state + (1<<(hit-1));
            state = state & 7;
        }
        if(out == 3){
            state = 0;
            out = 0;
            break;
        }
    }
    
    printf("%d\n%d\n%d\n", state&1, (state>>1)&1, (state>>2)&1);
    return 0;
}