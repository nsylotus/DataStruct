#include "Queue.h"

void QueueInit(Queue *queue) {
    assert(queue);
    queue->head = NULL;
    queue->tail = NULL;
}

void QueueDestroy(Queue *queue) {
    assert(queue);
    QueueNode *current = queue->head;
    while (current != NULL) {
        QueueNode *next = queue->head;
        free(current);
        current = next;
    }
    queue->head = NULL;
    queue->tail = NULL;
}

void QueuePush(Queue *queue, QueueDataType element) {
    assert(queue);
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    newNode->data = element;
    newNode->next = NULL;
    if (queue->head == NULL) {
        queue->head = queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void QueuePop(Queue *queue) {
    assert(queue);
    /*if(queue->head == NULL){
        return;
    }*/
    assert(!QueueEmpty(queue));
    QueueNode *next = queue->head->next;
    free(queue->head);
    queue->head = next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
}

QueueDataType QueueFront(Queue *queue) {
    assert(queue);
    return queue->head->data;
}

QueueDataType QueueBack(Queue *queue) {
    assert(queue);
    assert(!QueueEmpty(queue));
    return queue->tail->data;
}

int QueueSizeof(Queue *queue) {
    assert(queue);
    int n = 0;
    QueueNode *current = queue->head;
    while (current) {
        n++;
        current = current->next;
    }
    return n;
}

bool QueueEmpty(Queue *queue) {
    assert(queue);
    return queue->head == NULL;
}
