#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDataType;

typedef struct Stack {
    StackDataType *array;
    int top;
    int capacity; // 容量空间的大小
} Stack;

void StackInit(Stack *p_stack);

void StackDestroy(Stack *p_stack);

void StackPush(Stack *p_stack, StackDataType element);

void StackPop(Stack *p_stack);

StackDataType StackTop(Stack *p_stack);

int StackSizeof(Stack *p_stack);

bool StackEmpty(Stack *p_stack);

void StackPrint(Stack *p_stack);

#endif //STACK_H
