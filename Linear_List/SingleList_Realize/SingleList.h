#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SingListDataType;

typedef struct SingleListNode {
    SingListDataType data; // 要存的数据
    struct SingleListNode *next; // 指向下一个元素的指针
} SingleList;

SingleList *BuyListNode(SingListDataType element);

void SingleListPrint(SingleList *head_point);

void SingleListPushBack(SingleList **p_head_point, SingListDataType element);

void SingleListPushFront(SingleList **p_head_point, SingListDataType element);

void SingleListPopBack(SingleList **p_head_point);

void SingleListPopFront(SingleList **p_head_point);

SingleList *SingleListFind(SingleList *p_head_point, SingListDataType element);

// 在position的位置之前插入一个节点
void SingleListInsert(SingleList **p_head_point, SingleList *position, SingListDataType element);

// 在position的后面插入(一般都是这种插入)
void SingleListInsertAfter(SingleList *position, SingListDataType element);

void SingleListErase(SingleList **p_head_point, SingleList *position);

// 删除position的最后一个
void SingleListEraseAfter(SingleList **p_head_point, SingleList *position);

void SingleListDestroy(SingleList **p_head_point);
#endif //SINGLELIST_H
