#include <stdio.h>
#include <math.h>

int main(){
    int i;
    scanf("%d", &i);
    switch (i) {
        case 1:{
            int num;
            int e = 0;
            int b_out = 0;
            scanf("%d", &num);
            while (num>0) {
                b_out += (num%2)*pow(10, e);
                num /= 2;
                e++;
            }
            printf("%d\n", b_out);
            break;
        }
        case 2:{
            long int num;
            int e = 0;
            int d_out = 0;
            scanf("%ld", &num);
            while (num>0) {
                d_out += (num%10)*pow(2, e);
                num /= 10;
                e++;
            }
            printf("%d\n", d_out);
            break;
        }
        case 3:{
            int base_from;
            int base_to;
            int num;
            int result = 0;
            int e = 0;
            int d_out = 0;
            scanf("%d%d%d", &base_from, &base_to, &num);
            while (num>0) {
                d_out += (num%10)*pow(base_from, e);
                num /= 10;
                e++;
            }
            
            e = 0;
            while (d_out>0) {
                result += (d_out%base_to)*pow(10, e);
                d_out /= base_to;
                e++;
            }
            printf("%d\n", result);
            break;
        default:
            break;
        }
    }
    
}
