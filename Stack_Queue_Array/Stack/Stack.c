#include "Stack.h"

void StackInit(Stack *p_stack) {
    assert(p_stack);
    p_stack->array = NULL;
    p_stack->top = 0; // top给-1也可以
    // top给0意味着指向栈顶数据的下一个,先放数据在加1
    // top给-1意味着指向栈顶数据,使用时要先加1在放数据
    p_stack->capacity = 0;
}

void StackDestroy(Stack *p_stack) {
    assert(p_stack);
    free(p_stack->array);
    p_stack->array = NULL;
    p_stack->capacity = p_stack->top = 0;
}

void StackPush(Stack *p_stack, StackDataType element) {
    assert(p_stack);
    // 对空间不够的处理
    if (p_stack->top == p_stack->capacity) {
        int newCapacity = p_stack->capacity == 0 ? 4 : p_stack->capacity * 2;
        StackDataType *temp = realloc(p_stack->array, sizeof(StackDataType) * newCapacity);
        if (temp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        p_stack->array = temp;
        p_stack->capacity = newCapacity;;
    }
    p_stack->array[p_stack->top] = element;
    p_stack->top++;
}

void StackPop(Stack *p_stack) {
    assert(p_stack);
    if (p_stack->top > 0) {
        p_stack->top--;
    }
}

StackDataType StackTop(Stack *p_stack) {
    assert(p_stack);
    if (p_stack->top > 0) {
        return p_stack->array[p_stack->top - 1];
    }
}

int StackSizeof(Stack *p_stack) {
    assert(p_stack);
    return p_stack->top;
}

bool StackEmpty(Stack *p_stack) {
    assert(p_stack);
    /*if(p_stack->top == 0) {
        return true;
    }else {
        return false;
    }*/
    return p_stack->top == 0;
}

void StackPrint(Stack *p_stack) {
    Stack *current = p_stack;
    while (current->top > 0) {
        printf("%d ", current->array[current->top - 1]);
        current->top--;
    }
}
