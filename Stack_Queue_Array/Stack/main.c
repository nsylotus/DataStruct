#include "Stack.h"

void StackTest() {
    Stack stack;
    StackInit(&stack);
    for (int i = 0; i < 5; i++) {
        StackPush(&stack, i);
    }
    StackPop(&stack);
    printf("%d\n", StackSizeof(&stack));
    printf("%d\n", StackTop(&stack));
    printf("%d\n", StackEmpty(&stack));
    StackPush(&stack, 521);
    while (!StackEmpty(&stack)) {
        printf("%d ", StackTop(&stack));
        StackPop(&stack);
    }
    StackDestroy(&stack);
}

int main(void) {
    StackTest();
    return 0;
}
