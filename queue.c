#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    int data;
    struct QueueNode* link;
}queueNode_t;

typedef struct Queue{
    queueNode_t *rear;
    queueNode_t *front;
}queue_t;

queueNode_t* newNode(int x){
    queueNode_t* nodePointer = (queueNode_t*)malloc(sizeof(queueNode_t));
    nodePointer->data = x;
    nodePointer->link = NULL;
    return nodePointer;
}
queue_t* newQueue(){
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enQueue(queue_t* queue, int data){
    queueNode_t* t = newNode(data);
    if(queue->front == NULL){
        queue->front = t;
    }else{
        queue->rear->link = t;
    }
    queue->rear = t;
    printf("enqueue %d into queue\n", data);
}

int deQueue(queue_t* queue){
    if(queue->front == NULL){
        printf("queue is empty\n");
        return INT_MIN;
    }else{
       queueNode_t* t = queue->front;
       int item = t->data;
       queue->front = t->link;
       if(queue->front == NULL){
           queue->rear = NULL;
       }
       free(t);
       return item;
    }
}

int main(void){
    queue_t* q = newQueue();
    deQueue(q);
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
