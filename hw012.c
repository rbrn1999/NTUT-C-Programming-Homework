#include <stdio.h>
#include <string.h>
#include <math.h>

void  /*const char**/ G(int n, int k){
    if (n == 1) {
        printf("%d\n", k);
//        char k_str[50];
//        snprintf(k_str, 50, "%d", k);
//        return k_str;
    } else if (k<pow(2, n-1)){
        printf("0");
        G(n-1, k);
//        return strcat("0", G(n-1, k));
    } else if(k>=pow(2, n-1)){
        printf("1");
        G(n-1, pow(2,n)-1-k);
//        return strcat("1", G(n-1, pow(n, 2)-1-k));
    }
//    return "error";
}

int main(){
    int flag = 0;
    while (!flag) {
        int n, k;
        scanf("%d%d", &n, &k);
        G(n, k);
//        printf("%s", G(n, k));
        scanf("%d", &flag);
    }
}
