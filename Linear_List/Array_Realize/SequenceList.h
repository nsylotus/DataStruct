#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 255

typedef int ElementType;

typedef struct SequenceList {
    // 这种是静态存储
    // ElementType array[MAX_SIZE];

    ElementType *array; // 指向动态开辟的数组
    int size; // 数组中存储了多少个数据
    int capacity; // 数组实际能存放数据空寂按容量是多大
} SequenceList;

void SequencePrint(char *str, SequenceList *sequence_list);

void SequenceInitList(SequenceList *sequence_list);

void SequenceListDestory(SequenceList *sequence_list);

void SequenceListCheckCapacity(SequenceList *sequence_list);

void SequencePushBack(SequenceList *sequence_list, ElementType element);

void SequencePopBack(SequenceList *sequence_list);

void SequencePushFront(SequenceList *sequence_list, ElementType element);

void SequencePopFront(SequenceList *sequence_list);

// 找到了返回element位置下标, 没有找到返回-1
int SequenceListFind(SequenceList *sequence_list, ElementType element);

// 指定position下标位置插入
void SequenceListInsert(SequenceList *sequence_list, int position, ElementType element);

// 删除position位置的数据
void SequenceListErase(SequenceList *sequence_list, int position);

#endif //SEQUENCELIST_H
