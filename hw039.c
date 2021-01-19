#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int value;
    struct _node* left;
    struct _node* right;
} node;

typedef struct {
    node* root;
} bTree;

node* newNode(int value) {
    node *nNode = (node *)malloc(sizeof(node));
    nNode->left = NULL;
    nNode->right = NULL;
    nNode->value = value;
    return nNode;
}

void insert(bTree *tree, int value) {
    node *nNode = newNode(value);
    if(!tree->root)
        tree->root = nNode;
    else {
        int flag = 0;
        node* cur = tree->root;
        node* prev = cur;
        while (cur) {
            prev = cur;
            if(value>cur->value){
                cur = cur->right;
                flag = 1;
            } else {
                cur = cur->left;
                flag = 0;
            }
        }
        if(flag)
            prev->right = nNode;
        else
            prev->left = nNode;
    }
}

void delete(bTree *tree, int value) {
    if (tree->root) {
        int flag = 0;
        node* target = tree->root;
        node* prev = target;
        while (target && (target->value != value)) {
            if(value>target->value){
                prev = target;
                target = target->right;
                flag = 1;
            } else {
                prev = target;
                target = target->left;
                flag = 0;
            }
        }
        if (target && (target->value == value)) {
            if (target->left == NULL && target->right == NULL) {
                if(flag)
                    prev->right = NULL;
                else
                    prev->left = NULL;
                if(target == tree->root)
                    tree->root = NULL;
                
                free(target);
            } else {
                node *replacer;
                node* lReplacer = target->left;
                while (lReplacer && lReplacer->right) {
                    lReplacer = lReplacer->right;
                }
                node* rReplacer = target->right;
                while (rReplacer && rReplacer->left) {
                    rReplacer = rReplacer->left;
                }
                if (!lReplacer || (lReplacer->left && !rReplacer->right)) {
                    replacer = rReplacer;
                } else {
                    replacer = lReplacer;
                }
                int temp = replacer->value;
                delete(tree, replacer->value);
                target->value = temp;
            }
        }
    }
}

void preOrder(node *node, int *count) {
    if(node) {
        printf("%d",node->value);
        if(--(*count))
            printf(",");
        preOrder(node->left, count);
        preOrder(node->right, count);
    }
}
void inOrder(node *node, int *count) {
    if(node) {
        inOrder(node->left, count);
        printf("%d",node->value);
        if(--(*count))
            printf(",");
        inOrder(node->right, count);
    }
}
void postOrder(node *node, int *count) {
    if(node) {
        postOrder(node->left, count);
        postOrder(node->right, count);
        printf("%d",node->value);
        if(--(*count))
            printf(",");
    }
}
int main() {
    bTree tree;
    tree.root = NULL;
    char input[100];
    int input_i[100];
    fgets(input, 100, stdin);
    while (input[strlen(input)-1] == ' ' || input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    int i = 0;
    input_i[i++] = atoi(strtok(input, " ,"));
    char *temp = strtok(NULL, " ,");
    while (temp) {
        input_i[i++] = atoi(temp);
        temp = strtok(NULL, " ,");
    }
    for (int j=0; j<i; j++) {
        insert(&tree, input_i[j]);
    }
    int *count = (int *) malloc(sizeof(int));
    int key;
    scanf("%d", &key);
    delete(&tree, key);
    i--;
    *count = i;
    printf("preorder:");
    preOrder(tree.root, count);
    printf("\n");
    *count = i;
    printf("inorder:");
    inOrder(tree.root, count);
    printf("\n");
    *count = i;
    printf("postorder:");
    postOrder(tree.root, count);
    printf("\n");
}
