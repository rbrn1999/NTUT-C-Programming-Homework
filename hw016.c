#include <stdio.h>
#include <string.h>

int isSet(int* arr, int size){
//    printf("[");
    for (int i=0; i<size; i++) {
//        printf("%d,", *(arr+i));
        for (int j=i+1; j<size; j++) {
            if (*(arr+i)==*(arr+j)) {
//                printf("... repeated\n");
                return 0;
            }
        }
    }
//    printf("]\n");
    return 1;
}
int myFunc(int* arr, int size, int m){
    int counter = 0;
    for (int i=0; i<size-(m-1); i++) {
        if (isSet(arr+i, m))
            counter++;
    }
    return counter;
}

int main(){
    char input[100];
    int m;
    scanf("%s", input);
    scanf("%d", &m);
    int size = strlen(input);
    int arr[size];
    for (int i=0; i<size; i++) {
        arr[i] = input[i] - '0';
    }
    printf("%d\n",myFunc(arr, size, m));
}
