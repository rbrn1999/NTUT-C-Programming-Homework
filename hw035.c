#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _term {
    int coefficient;
    int exp;
    struct _term *next;
} term;


void createTerm(term *term) {
    term->coefficient = 0;
    term->exp = -1;
    term->next = NULL;
}

term* readTerms() {
    char input[1000], *terms[500];
    fgets(input, 100, stdin);
    if(input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    if(input[strlen(input)-1] == ' ') {
        input[strlen(input)-1] = '\0';
    }
    char *temp = strtok(input, " ");
    int i=0;
    while(temp != NULL) {
        terms[i] = temp;
        temp = strtok(NULL, " ");
        i++;
    }
    int termCount = i;
    term *cur = (term *) malloc(sizeof(term));
    createTerm(cur);
    cur->exp = termCount-1;
    cur->coefficient = atoi(terms[0]);
    term *head = cur;
    for(int i=1; i<termCount; i++) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->coefficient = atoi(terms[i]);
        nextTerm->exp = (termCount - 1) - i;
        cur->next = nextTerm;
        cur = cur->next;
    }
    return head;
}

void freeList(term *head) {
    term *cur = head->next;
    term *prev = head;
    while(cur) {
        free(prev);
        prev = cur;
        cur = cur->next;
    }
    free(prev);
}

void printTerms(term* num) {
    while(num->coefficient == 0 && num->exp > 0) {
        num = num->next;
    }
    while(num) {
        printf("%d ", num->coefficient);
        num = num->next;
    }
    printf("\n");
}

term* addTerms(term* lhs, term* rhs) {
    term *head = (term *) malloc(sizeof(term));
    createTerm(head);
    term *cur = head;
    if(lhs->exp>rhs->exp) {
        head->exp = lhs->exp;
    } else {
        head->exp = rhs->exp;
    }
    
    if(lhs && cur->exp == lhs->exp) {
        cur->coefficient += lhs->coefficient;
        lhs = lhs->next;
    }
    if(rhs && cur->exp == rhs->exp) {
        cur->coefficient += rhs->coefficient;
        rhs = rhs->next;
    }
    while(lhs || rhs) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->exp = cur->exp - 1;
        cur->next = nextTerm;
        cur = nextTerm;
        if (lhs && cur->exp == lhs->exp) {
            cur->coefficient += lhs->coefficient;
            lhs = lhs->next;
        }
        if (rhs && cur->exp == rhs->exp) {
            cur->coefficient += rhs->coefficient;
            rhs = rhs->next;
        }
    }
    return head;
}
term* substractTerms(term* lhs, term* rhs) {
    term *head = (term *) malloc(sizeof(term));
    createTerm(head);
    term *cur = head;
    if(lhs->exp>rhs->exp) {
        head->exp = lhs->exp;
    } else {
        head->exp = rhs->exp;
    }
    
    if(lhs && cur->exp == lhs->exp) {
        cur->coefficient += lhs->coefficient;
        lhs = lhs->next;
    }
    if(rhs && cur->exp == rhs->exp) {
        cur->coefficient -= rhs->coefficient;
        rhs = rhs->next;
    }
    while(lhs || rhs) {
        term *nextTerm = (term *) malloc(sizeof(term));
        createTerm(nextTerm);
        nextTerm->exp = cur->exp - 1;
        cur->next = nextTerm;
        cur = nextTerm;
        if (lhs && cur->exp == lhs->exp) {
            cur->coefficient += lhs->coefficient;
            lhs = lhs->next;
        }
        if (rhs && cur->exp == rhs->exp) {
            cur->coefficient -= rhs->coefficient;
            rhs = rhs->next;
        }
    }
    return head;
}

term* multiplyTerms(term *lhs, term *rhs) {
    term *result = (term *) malloc(sizeof(term));
    createTerm(result);
    result->exp = 0;
    while(rhs) {
        term *temp = (term *) malloc(sizeof(term));
        term *cur = temp;
        term *lhsPtr = lhs;
        cur->exp = lhsPtr->exp + rhs->exp;
        cur->coefficient = lhsPtr->coefficient * rhs->coefficient;
        lhsPtr = lhsPtr->next;
        while (lhsPtr) {
            term *nextTerm = (term *) malloc(sizeof(term));
            createTerm(nextTerm);
            nextTerm->exp = lhsPtr->exp + rhs->exp;
            nextTerm->coefficient = lhsPtr->coefficient * rhs->coefficient;
            cur->next = nextTerm;
            cur = cur->next;
            lhsPtr = lhsPtr->next;
        }
        result = addTerms(result, temp);
        freeList(temp);
        rhs = rhs->next;
    }
    return result;
}

int main() {
    term *num1 = readTerms();
    term *num2 = readTerms();
    printTerms(addTerms(num1, num2));
    printTerms(substractTerms(num1, num2));
    printTerms(multiplyTerms(num1, num2));
}
