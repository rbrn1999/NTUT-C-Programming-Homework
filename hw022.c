#include <stdio.h>

int horiVer(int arr[10][10], int i, int j){
    int left = 0, right = 0, top = 0, bottom = 0;
    int flag = 1;
    int temp = j - 1;
    while (temp>=0 && temp<9 && flag) {
        if(arr[i][temp]){
            left++;
            temp--;
        } else {
            flag = 0;
        }
    }
    
    flag = 1;
    temp = j + 1;
    while (temp>0 && temp<=9 && flag) {
        if(arr[i][temp]){
            right++;
            temp++;
        } else {
            flag = 0;
        }
    }
    flag = 1;
    temp = i - 1;
    while (temp>=0 && temp<9 && flag) {
        if(arr[temp][j]){
            top++;
            temp--;
        } else {
            flag = 0;
        }
    }
    flag = 1;
    temp = i + 1;
    while (temp>0 && temp<=9 && flag) {
        if(arr[temp][j]){
            bottom++;
            temp++;
        } else {
            flag = 0;
        }
    }
    return (left + right >= 4 || top + bottom >= 4) ? 1 : 0;
}

int diagonal(int arr[10][10], int i, int j){
    int tl, tr, bl, br;
    tl = tr = bl = br = 0;
    int flag = 1;
    int temp_i = i - 1;
    int temp_j = j - 1;
    while (temp_i>=0 && temp_i<9 && temp_j>=0 && temp_j<9 && flag) {
        if(arr[temp_i][temp_j]){
            tl++;
            temp_i--;
            temp_j--;
        } else {
            flag = 0;
        }
    }
    temp_i = i - 1;
    temp_j = j + 1;
    flag = 1;
    while (temp_i>=0 && temp_i<9 && temp_j>0 && temp_j<=9 && flag) {
        if(arr[temp_i][temp_j]){
            tr++;
            temp_i--;
            temp_j++;
        } else {
            flag = 0;
        }
    }
    temp_i = i + 1;
    temp_j = j - 1;
    flag = 1;
    while (temp_i>0 && temp_i<=9 && temp_j>=0 && temp_j<9 && flag) {
        if(arr[temp_i][temp_j]){
            bl++;
            temp_i++;
            temp_j--;
        } else {
            flag = 0;
        }
    }
    temp_i = i + 1;
    temp_j = j + 1;
    flag = 1;
    while (temp_i>0 && temp_i<=9 && temp_j>0 && temp_j<=9 && flag) {
        if(arr[temp_i][temp_j]){
            br++;
            temp_i++;
            temp_j++;
        } else {
            flag = 0;
        }
    }

    return (tl + br >= 4 || tr + bl >= 4) ? 1 : 0;
}

int main(){
    //initalize chesses
    int arr[10][10];
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            scanf("%d", &arr[i][j]);
    
    int hasSuccessAttempt = 0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (arr[i][j]==0 && (horiVer(arr, i, j) || diagonal(arr, i, j))) {
                printf("%d %d\n", i, j);
                hasSuccessAttempt = 1;
            }
        }
    }
    if(!hasSuccessAttempt)
        printf("impractical attempt!\n");
    
    return 0;
}
