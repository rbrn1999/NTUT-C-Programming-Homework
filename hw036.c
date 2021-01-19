#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _data{
    char name[50];
    int age;
    int year;
    int month;
    int day;
    struct _data *next;
} data;

void push(data **head, data *data) {
    data->next = *head;
    *head = data;
}

data* pop(data **head) {
    if (!*head) {
        return NULL;
    }
    data *result = *head;
    *head = (*head)->next;
    result->next = NULL;
    return result;
}

data* readData() {
    data *newData = (data *) malloc(sizeof(data));
    char *input;
    input = (char *) malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    if(input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
    if(input[strlen(input)-1] == ' ')
        input[strlen(input)-1] = '\0';
    while (input[0] != '"')
        input++;
    strcpy(newData->name, strtok(input, "\""));
    input = strtok(NULL, "\"");
    sscanf(input, "%d%d%d%d", &newData->age, &newData->year, &newData->month, &newData->day);
    newData->next = NULL;
    return newData;
}

int main(){
    int flag = 1;
    data *head = NULL;
    while (flag) {
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1:{
                data *d = readData();
                push(&head, d);
                break;
            }
            case 2:{
                data *d = pop(&head);
                int input;
                scanf("%d", &input);
                char c = getchar();
                while(c != EOF && c != '\n')
                    c = getchar();
                if (!d) {
                    printf("The Stack is empty\n");
                    break;
                }
                switch (input) {
                    case 1:
                        puts(d->name);
                        break;
                    case 2:
                        printf("%d\n", d->age);
                        break;
                    case 3:
                        printf("%d_%d_%d\n", d->year, d->month, d->day);
                        break;
                    default:
                        break;
                }
                break;
            }
            case 3:
                flag = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
