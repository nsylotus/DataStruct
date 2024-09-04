#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QueueDataType;

typedef struct QueueNode {
    struct QueueNode *next;
    QueueDataType data;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
} Queue;

void QueueInit(Queue *queue);

void QueueDestroy(Queue *queue);

void QueuePush(Queue *queue, QueueDataType element);

void QueuePop(Queue *queue);

QueueDataType QueueFront(Queue *queue);

QueueDataType QueueBack(Queue *queue);

int QueueSizeof(Queue *queue);

bool QueueEmpty(Queue *queue);


#endif //QUEUE_H
