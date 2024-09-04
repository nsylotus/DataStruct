#include "SequenceList.h"

void SequencePrint(char *str, SequenceList *sequence_list) {
    printf("%s\t", str);
    for (int i = 0; i < sequence_list->size; i++) {
        printf("%d\t", sequence_list->array[i]);
    }
    printf("\n");
}

void SequenceInitList(SequenceList *sequence_list) {
    sequence_list->array = NULL;
    sequence_list->size = 0;
    sequence_list->capacity = 0;
}

void SequenceListDestory(SequenceList *sequence_list) {
    free(sequence_list);
    sequence_list->array = NULL;
    sequence_list->size = 0;
    sequence_list->capacity = 0;
}

void SequenceListCheckCapacity(SequenceList *sequence_list) {
    // 如果没有空间或者空间不足, 进行扩容
    if (sequence_list->size == sequence_list->capacity) {
        int newCapacity = sequence_list->capacity == 0 ? 4 : sequence_list->capacity * 2;
        ElementType *temp = (ElementType *) realloc(sequence_list->array, newCapacity * sizeof(ElementType));
        if (temp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        sequence_list->array = temp;
        sequence_list->capacity = newCapacity;
    }
}

void SequencePushBack(SequenceList *sequence_list, ElementType element) {
    /*// 空间不够进行扩容
    SequenceListCheckCapacity(sequence_list);
    // 空间足够
    sequence_list->array[sequence_list->size] = element;
    sequence_list->size++;*/
    SequenceListInsert(sequence_list, sequence_list->size, element);
}

void SequencePopBack(SequenceList *sequence_list) {
    /*if (sequence_list->size > 0) {
        sequence_list->size--;
    }*/
    SequenceListErase(sequence_list, sequence_list->size - 1);
}

void SequencePushFront(SequenceList *sequence_list, ElementType element) {
    /*// 如果空间不够进行扩容
    SequenceListCheckCapacity(sequence_list);
    // 移动数据
    int end = sequence_list->size - 1;
    while (end >= 0) {
        sequence_list->array[end + 1] = sequence_list->array[end];
        end--;
    }
    sequence_list->array[0] = element;
    sequence_list->size++;*/
    SequenceListInsert(sequence_list, 0, element);
}

void SequencePopFront(SequenceList *sequence_list) {
    assert(sequence_list->size > 0); // 也可以使用if方式进行判断
    /*int begin = 1;
    // 移动数据
    while (begin < sequence_list->size) {
        sequence_list->array[begin - 1] = sequence_list->array[begin];
        ++begin;
    }
    sequence_list->size--;*/
    SequenceListErase(sequence_list, 0);
}

// 找到了返回element位置下标, 没有找到返回-1
int SequenceListFind(SequenceList *sequence_list, ElementType element) {
    for (int i = 0; i < sequence_list->size; i++) {
        if (sequence_list->array[i] == element) {
            return i;
        }
    }
    return -1;
}

// 指定position下标位置插入
void SequenceListInsert(SequenceList *sequence_list, int position, ElementType element) {
    /*if(position > sequence_list->size || position < 0){
        printf("position invalid\n");
        return;
    }*/
    // 断言为True,没有问题, 为False就发生报错
    assert(position >= 0 && position<= sequence_list->size);
    SequenceListCheckCapacity(sequence_list);
    // 挪动数据
    int end = sequence_list->size - 1;
    while (end >= position) {
        sequence_list->array[end + 1] = sequence_list->array[end];
        end--;
    }
    sequence_list->array[position] = element;
    sequence_list->size++;
}

// 删除position位置的数据
void SequenceListErase(SequenceList *sequence_list, int position) {
    assert(position >= 0 && position< sequence_list->size);
    int bengin = position + 1;
    while (bengin < sequence_list->size) {
        sequence_list->array[bengin - 1] = sequence_list->array[bengin];
        bengin++;
    }
    sequence_list->size--;
}
