#include "DoubleList.h"

DoubleList *DoubleListInit() {
    // 使用另一种方法创建链表
    DoubleList *p_head_point = (DoubleList *) malloc(sizeof(DoubleList));
    p_head_point->next = p_head_point;
    p_head_point->prev = p_head_point;
    return p_head_point;
}

void DoubleListPrint(DoubleList *p_head_point) {
    assert(p_head_point);
    DoubleList *current = p_head_point->next;
    while (current != p_head_point) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

DoubleList *BuyDoubleListNode(DoubleListType element) {
    DoubleList *newNode = (DoubleList *) malloc(sizeof(DoubleList));
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void DoubleListPushBack(DoubleList *p_head_point, DoubleListType element) {
    assert(p_head_point);
    /*DoubleList* tail = p_head_point->prev;
    DoubleList * newNode = BuyDoubleListNode(element);
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = p_head_point;
    p_head_point->prev = newNode;*/
    DoubleListInsert(p_head_point, element);
}

void DoubleListPopBack(DoubleList *p_head_point) {
    assert(p_head_point);
    assert(p_head_point->next != p_head_point);
    /*DoubleList* tail = p_head_point->prev;
    p_head_point->prev = tail->prev;
    tail->prev->next = p_head_point;
    free(tail);*/
    DoubleListErase(p_head_point->prev);
}

void DoubleListPushFront(DoubleList *p_head_point, DoubleListType element) {
    assert(p_head_point);
    /*DoubleList * newNode = BuyDoubleListNode(element);
    newNode->next = p_head_point->next;
    p_head_point->next->prev = newNode;
    p_head_point->next = newNode;
    newNode->prev = p_head_point;*/
    DoubleListInsert(p_head_point->next, element);
}

void DoubleListPopFront(DoubleList *p_head_point) {
    assert(p_head_point);
    // 链表为空
    assert(p_head_point->next != p_head_point);
    /*DoubleList* next = p_head_point->next;
    DoubleList* nextNext = next->next;
    p_head_point->next = nextNext;
    nextNext->prev = p_head_point;
    free(p_head_point);*/
    DoubleListErase(p_head_point->next);
}

DoubleList *DoubleListFind(DoubleList *p_head_point, DoubleListType serach_element) {
    assert(p_head_point);
    DoubleList *current = p_head_point->next;
    while (current != p_head_point) {
        if (current->data == serach_element) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 在position位置之前插入
void DoubleListInsert(DoubleList *position, DoubleListType element) {
    assert(position);
    DoubleList *positionPrev = position->prev;
    DoubleList *newNode = BuyDoubleListNode(element);
    positionPrev->next = newNode;
    newNode->prev = positionPrev;
    newNode->next = position;
    position->prev = newNode;
}

// 删除position位置
void DoubleListErase(DoubleList *position) {
    assert(position);
    DoubleList *positionPrev = position->prev;
    DoubleList *positionNext = position->next;
    positionPrev->next = positionNext;
    positionNext->prev = positionPrev;
    free(position);
    position = NULL;
}

void DoubleListDestroy(DoubleList *p_head_point) {
    assert(p_head_point);
    DoubleList *current = p_head_point->next;
    while (current != p_head_point) {
        DoubleList *next = current->next;
        free(current);
        current = next;
    }
    free(p_head_point);
}
