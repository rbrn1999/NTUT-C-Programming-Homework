#include <stdio.h>
#include <ctype.h>

double point(){
    char x, y;
    scanf(" %c%c", &x, &y);
    if(x=='1')
        return 10;
    else if((x>='2')&&(x<='9'))
        return (x-'0');
    else if(x == 'A')
        return 1;
    else
        return 0.5;
}

int main(){
    double  player = 0;
    double computer = 0;
    player += point();
    computer += point();
    char input;
    int flag1 = 1;
    int flag2 = 1;
    while (flag1||flag2) {
        if (flag1) {
            scanf(" %c", &input);
        }
        if (input == 'Y' || input == 'y') {
            player += point();
            if (player>10.5){
                player = 0;
                break;
            }
        } else {
            flag1 = 0;
        }
        if (flag2 && (computer<player || computer<=8)) {
            computer += point();
            if (computer>10.5){
                computer = 0;
                break;
            }
        } else {
            flag2 = 0;
        }
    }

    printf("%.1lf vs. %.1lf\n", player, computer);
    if (player == computer) {
        printf("It's a tie\n");
    } else if(player > computer) {
        printf("player wins\n");
    } else {
        printf("computer wins\n");
    }
    return 0;
}
