#include <stdio.h>

unsigned long long int S(int *arr, int left, int mid, int right){
    unsigned long long int count = 0;
    for (int i=left; i<= mid; i++) {
        for (int j=mid+1; j<=right; j++) {
            if (arr[i]>arr[j]) {
                count++;
            }
        }
    }
    return count;
}

unsigned long long int W(int *arr, int left, int right){
    int mid = (right + left) / 2;
    if (left < right) {
        return W(arr, left, mid) + W(arr, mid+1, right) + S(arr, left ,mid, right);
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int data[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }
    printf("%llu\n", W(data, 0, n-1));
}
