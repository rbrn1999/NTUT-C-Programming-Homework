#include <stdio.h>
#include <string.h>
#include <limits.h>

struct Word{
    char value[100];
    int count;
};

int main(){
    char A[1000], P[100], Q[100];
    fgets(A, 1000, stdin);
    if (strlen(A) > 0 && A[strlen(A) - 1] == '\n')
        A[strlen(A) - 1] = '\0';
    
    fgets(P, 100, stdin);
    fgets(Q, 100, stdin);
    if (strlen(P) > 0 && P[strlen(P) - 1] == '\n')
        P[strlen(P) - 1] = '\0';
    if (strlen(P) > 0 && P[strlen(P) - 1] == ' ')
        P[strlen(P) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == '\n')
        Q[strlen(Q) - 1] = '\0';
    if (strlen(Q) > 0 && Q[strlen(Q) - 1] == ' ')
        Q[strlen(Q) - 1] = '\0';
    
    int wordCount = 1;
    for (int i=0; i<strlen(A); i++)
        if(A[i] == ' ')
            wordCount++;
    char A_arr[wordCount][100];
    char temp[wordCount][100];
    char *token = strtok(A, " ");
    int i = 0;
    while( token != NULL ) {
        strcpy(A_arr[i], token);
        strcpy(temp[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s", Q);
        else
            printf("%s", temp[i]);
        printf(" ");
    }
    printf("\n");
    
    for(int i=0; i<wordCount; i++){
        if (!strcmp(temp[i],P))
            printf("%s %s", Q, P);
        else
            printf("%s", temp[i]);
        printf(" ");
    }
    printf("\n");
    
    for(int i=0; i<wordCount; i++){
        if (strcmp(temp[i],P)){
            printf("%s", temp[i]);
            printf(" ");
        }
    }
    printf("\n");
    
    struct Word sortedWords[wordCount];
    
    for(int i=0; i<wordCount; i++){
        struct Word word = {.value = "", .count = -1};
        sortedWords[i] = word;
    }
    int unique = 0;
    int length = wordCount;
    int k = 0; //i: index for sortedWords k: index for temp[]
    for(int i=0; k<length; i++, k++){
        int duplicate = 0;
        for (int j=0; j<unique; j++) {
            if (!strcmp(sortedWords[j].value, temp[k])) {
                duplicate = 1;
                sortedWords[j].count++;
                i--;
                break;
            }
        }
        if (!duplicate) {
            strcpy(sortedWords[i].value, temp[k]);
            sortedWords[i].count = 1;
            unique++;
        }
    }
    for (int i=0; i<unique; i++) {
        int largest = i;
        for (int j=i+1; j<unique; j++) {
            if (sortedWords[largest].count < sortedWords[j].count || (sortedWords[largest].count == sortedWords[j].count && strcmp(sortedWords[largest].value, sortedWords[j].value)>0)) {
                largest = j;
            }
        }
        struct Word temp = sortedWords[i];
        sortedWords[i] = sortedWords[largest];
        sortedWords[largest] = temp;
        printf("%s : %d\n", sortedWords[i].value, sortedWords[i].count);
    }
}
