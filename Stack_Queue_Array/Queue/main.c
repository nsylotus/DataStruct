#include "Queue.h"

void QueueTest() {
    Queue queue;
    QueueInit(&queue);
    for (int i = 0; i < 3; i++) {
        QueuePush(&queue, i);
    }
    QueuePop(&queue);
    printf("%d\n", QueueFront(&queue));
    printf("%d\n", QueueBack(&queue));
    QueueDestroy(&queue);
}

void QueueTest02() {
    Queue queue;
    QueueInit(&queue);
    for (int i = 0; i < 5; i++) {
        QueuePush(&queue, i);
    }
    while (!QueueEmpty(&queue)) {
        QueueDataType front = QueueFront(&queue);
        printf("%d ", front);
        QueuePop(&queue);
    }
    printf("\n");
    QueueDestroy(&queue);
}

int main(int argc, char const *argv[]) {
    // QueueTest();
    QueueTest02();
    return 0;
}
