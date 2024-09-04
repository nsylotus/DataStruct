#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DoubleListType;

typedef struct DoubleListNode {
    struct DoubleListNode *prev;
    DoubleListType data;
    struct DoubleListNode *next;
} DoubleList;

DoubleList *DoubleListInit();

void DoubleListPrint(DoubleList *p_head_point);

DoubleList *BuyDoubleListNode(DoubleListType element);

void DoubleListPushBack(DoubleList *p_head_point, DoubleListType element);

void DoubleListPopBack(DoubleList *p_head_point);

void DoubleListPushFront(DoubleList *p_head_point, DoubleListType element);

void DoubleListPopFront(DoubleList *p_head_point);

DoubleList *DoubleListFind(DoubleList *p_head_point, DoubleListType serach_element);

void DoubleListInsert(DoubleList *position, DoubleListType element);

void DoubleListErase(DoubleList *position);

void DoubleListDestroy(DoubleList *p_head_point);


#endif //DOUBLELIST_H
