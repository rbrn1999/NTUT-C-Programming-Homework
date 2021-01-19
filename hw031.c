#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct _node {
    int day_cost;
    int childrenCount;
    int parentCount;
    struct _node **parents;
} node;

void setNode(node* node, int cost, int count) {
    node->day_cost = cost;
    node->childrenCount = count;
}

void initNode(node* node) {
    node->parents = (struct _node **) malloc(N * sizeof(struct _node*));
    node->parentCount = 0;
}

int findLargest(int *arr, int n) {
    int result = 0;
    for (int i=0; i<n; i++)
        if (arr[i] > result)
            result = arr[i];
   
    return result;
}

int findCost(node* node) {
    int parentCost[node->parentCount];
    for (int i=0; i<node->parentCount; i++) {
        parentCost[i] = findCost(node->parents[i]);
    }
    return node->day_cost + findLargest(parentCost, node->parentCount);
}

int main() {
    int sets;
    scanf("%d", &sets);
    for(int i=0; i<sets; i++) {
        int nodeCount;
        scanf("%d", &nodeCount);
        node nodes[nodeCount];
         for (int i=0; i<nodeCount; i++) {
             initNode(&nodes[i]);
         }
        for (int i=0; i<nodeCount; i++) {
            int cost, childrenCount;
            scanf("%d%d", &cost, &childrenCount);
            setNode(&nodes[i], cost, childrenCount);
            for (int j=0; j<childrenCount; j++) {
                int input; //Node number: 1,2,3...
                scanf("%d", &input);
                nodes[input-1].parents[nodes[input-1].parentCount++] = &nodes[i];
            }
        }
        printf("%d\n", findCost(&nodes[nodeCount-1]));
    }
}
