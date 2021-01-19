#include <stdio.h>
#include <string.h>
#include <math.h>

char readQueue(char* str){
    char result = str[0];
    for (int i=0; i<strlen(str); i++) {
        str[i] = str[i+1];
    }
    return result;
}

int myFunc(int length, int arr[length][length], int curSize, char *input, int i, int j){
    switch (readQueue(input)) {
        case '0':
            return 0;
            break;
        case '1':
            for (int y = j; y < j + curSize; y++)
                for (int x = i; x < i + curSize; x++)
                    arr[y][x] = 1;           //printf("%d,%d\n", y, x);
            
            return pow(curSize, 2);
            break;
        case '2':{
            int topLeft     = myFunc(length, arr, curSize/2, input, i, j);
            int topRight    = myFunc(length, arr, curSize/2, input, i+curSize/2, j);
            int bottomLeft  = myFunc(length, arr, curSize/2, input, i, j+curSize/2);
            int bottomRight = myFunc(length, arr, curSize/2, input, i+curSize/2, j+curSize/2);
            return topLeft + topRight + bottomLeft + bottomRight;
            break;
        }
        default:
            return 0;
            break;
    }
}

int main(){
    char input[300];
    int length;
    scanf("%s", input);
    scanf("%d", &length);
    int arr[length][length];
    memset(arr, 0, sizeof(arr));
    int count =  myFunc(length, arr, length, input, 0, 0);
    for (int i=0; i<length; i++)
        for (int j=0; j<length; j++)
            if(arr[i][j])
                printf("%d,%d\n", i, j);
    if(!count)
        printf("all white\n");
}
