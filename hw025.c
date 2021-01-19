#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define STR_N 300


int encode(char input[STR_N], int size, char wordList[size][STR_N]){
    int inputCount = 1;
    for(int i=0; i<strlen(input); i++){
            if(input[i] == ' ')
                inputCount++;
    }
    char inputList[inputCount][STR_N];
    
    strcpy(inputList[0], strtok(input, " "));
    for (int i=1; i<inputCount; i++) {
       strcpy(inputList[i], strtok(NULL, " "));
    }
    int result = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<inputCount; j++) {
            if (!strcmp(wordList[i], inputList[j])) {
                result += pow(2, i);
                break;
            }
        }
    }
    return result;
}

int main(){
    char s1[STR_N];
    fgets(s1, STR_N, stdin);
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == '\n' ) {
        s1[strlen(s1)-1] = '\0';
    }
    if (strlen(s1) > 0 && s1[strlen(s1)-1] == ' ' ) {
        s1[strlen(s1)-1] = '\0';
    }
    int n;
    scanf("%d", &n);
    getchar();
    char words[n][STR_N];
    for(int i=0; i<n; i++){
        fgets(words[i], STR_N, stdin);
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == '\n' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
        if (strlen(words[i]) > 0 && words[i][strlen(words[i])-1] == ' ' ) {
            words[i][strlen(words[i])-1] = '\0';
        }
    }
    
    int wordCount = 1;
    for(int i=0; i<strlen(s1); i++){
            if(s1[i] == ' ')
                wordCount++;
    }
    char wordList[wordCount][STR_N];
    
    strcpy(wordList[0], strtok(s1, " "));
    for (int i=1; i<wordCount; i++) {
       strcpy(wordList[i], strtok(NULL, " "));
    }
    int codes[n];
    for (int i=0; i<n; i++) {
        codes[i] = encode(words[i], wordCount, wordList);
    }
    int compensate = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if((codes[i]^codes[j]) == (pow(2, wordCount) - 1))
                compensate++;
        }
    }
    printf("%d\n", compensate);
}
