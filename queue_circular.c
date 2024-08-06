#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int data;
    struct QueueNode* link;
}queueNode_t;

typedef struct Queue{
    queueNode_t* rear;
}queue_t;

queueNode_t* newNode(int x){
    queueNode_t* nodePointer = (queueNode_t*)malloc(sizeof(queueNode_t));
    nodePointer->data = x;
    nodePointer->link = NULL;
    return nodePointer;
}

queue_t* newQueue(){
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->rear = NULL;
    return queue;
}

void enQueue(queue_t* queue, int data){
    queueNode_t* t = newNode(data);
    if(queue->rear == NULL){
        t->link = t;
    }else{
        t->link = queue->rear->link;
        queue->rear->link = t;
    }
    queue->rear = t;
    printf("enqueue %d into queue\n", data);
}

int deQueue(queue_t* queue){
    queueNode_t* t = queue->rear->link;
    int item = t->data;
    if(queue->rear->link == queue->rear){
        queue->rear = NULL;
    }else{
        queue->rear->link = queue->rear->link->link;
    }
    free(t);
    return item;
}

int main(void){
    queue_t* q = newQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    printf("dequeue: %d\n", deQueue(q));
    enQueue(q, 5);
    printf("dequeue: %d\n", deQueue(q));
    printf("dequeue: %d\n", deQueue(q));
    printf("dequeue: %d\n", deQueue(q));
    printf("dequeue: %d\n", deQueue(q));
}

