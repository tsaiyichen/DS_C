#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int x){
    struct StackNode* nodePointer = (struct StackNode*)malloc(sizeof(struct stackNode));
    nodePointer->data = x;
    nodePointer->next = NULL;
    return nodePointer;
}

bool isEmpty(struct StackNode* root){
    return !root;
}
void push(struct StackNode** root, int x){
    struct StackNode* t = newNode(x);
    t->next = *root;
    *root = t;
    printf("push %d into stack.", x);
}

int pop(structNode** root){
    if(isEmpty(*root)){
        printf("Stack Empty.");
    }else{
        struct StackNode* t = *root;
        int x = t->data;
        *root = t->next;
        free(t);
        return item;
    }
}

int main(void){
    struct StackNode* stack = NULL;
    struct StackNode** root = &stack;

    push(root, 1);
    push(root, 2);
    push(root, 3);
    push(root, 4);
}