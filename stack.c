#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}stackNode_t;

stackNode_t* newNode(int x){
    stackNode_t* nodePointer = (stackNode_t*)malloc(sizeof(stackNode_t));
    nodePointer->data = x;
    nodePointer->next = NULL;
    return nodePointer;
}

bool isEmpty(stackNode_t* root){
    return !root;
}
void push(stackNode_t** root, int x){
    stackNode_t* t = newNode(x);
    t->next = *root;
    *root = t;
    printf("push %d into stack.\n", x);
}

int pop(stackNode_t** root){
    if(isEmpty(*root)){
        printf("Stack Empty.\n");
    }else{
        stackNode_t* t = *root;
        int x = t->data;
        *root = t->next;
        free(t);
        return x;
    }
}

int main(void){
    stackNode_t* stack = NULL;
    stackNode_t** root = &stack;

    push(root, 1);
    printf("%d\n", pop(root));
    push(root, 2);
    push(root, 3);
    printf("%d\n", pop(root));
    printf("%d\n", pop(root));
    push(root, 4);
}