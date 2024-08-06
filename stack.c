#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
}stackNode_t;

typedef struct Stack{
    stackNode_t* top;
}stack_t;

stackNode_t* newNode(int x){
    stackNode_t* nodePointer = (stackNode_t*)malloc(sizeof(stackNode_t));
    nodePointer->data = x;
    nodePointer->next = NULL;
    return nodePointer;
}
stack_t* newStack(){
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->top = NULL;
    return stack;
}

bool isEmpty(stack_t* stack){
    return !stack;
}
void push(stack_t* stack, int x){
    stackNode_t* t = newNode(x);
    t->next = stack->top;
    stack->top = t;
    printf("push %d into stack.\n", x);
}

int pop(stack_t* stack){
    if(isEmpty(stack)){
        printf("Stack Empty.\n");
    }else{
        stackNode_t* t = stack->top;
        int x = t->data;
        stack->top = t->next;
        free(t);
        return x;
    }
}

int main(void){
    stack_t* stack = newStack();
    push(stack, 1);
    printf("%d\n", pop(stack));
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    push(stack, 4);
}