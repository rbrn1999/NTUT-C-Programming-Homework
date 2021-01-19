#include <stdio.h>

void printSquareArr(int size, int arr[size][size]){
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // width and height of 2-d array
    int size;
    // transform pattern
    int mode;
    scanf("%d%d", &size, &mode);
    //initialize array
    int arr[size][size];
    int output[size][size];
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            arr[i][j] = i*size + j + 1;
            output[i][j] = 0;
        }
    }
    switch (mode) {
        case 1:{
            printSquareArr(size, arr);
            break;
        }
        case 2:{
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    output[j][(size-1)-i] = arr[i][j];
                }
            }
            printSquareArr(size, output);
            break;
        }
        case 3:{
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    output[i][j] = arr[j][(size-1)-i];
                }
            }
            printSquareArr(size, output);
            break;
        }
        case 4:{
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    output[(size-1)-i][j] = arr[i][j];
                }
            }
            printSquareArr(size, output);
            break;
        }
            
        default:
            break;
    }
}
