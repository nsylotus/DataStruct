#include "SingleList.h"

SingleList *BuyListNode(SingListDataType element) {
    SingleList *newNode = (SingleList *) malloc(sizeof(SingleList));
    if (newNode == NULL) {
        printf("malloc fail\n");
        exit(-1);
    }
    newNode->data = element;
    newNode->next = NULL;
    return newNode;
}

void SingleListPrint(SingleList *head_point) {
    SingleList *sing_head_point = head_point;
    while (sing_head_point != NULL) {
        printf("%d->", sing_head_point->data);
        sing_head_point = sing_head_point->next;
    }
}

void SingleListPushBack(SingleList **p_head_point, SingListDataType element) {
    assert(p_head_point);
    SingleList *newNode = BuyListNode(element);

    if (*p_head_point == NULL) {
        *p_head_point = newNode;
    } else {
        // 先找到最后一个节点
        SingleList *tail = *p_head_point;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = newNode;
    }
}

void SingleListPushFront(SingleList **p_head_point, SingListDataType element) {
    assert(p_head_point);
    SingleList *newNode = BuyListNode(element);
    newNode->next = *p_head_point;
    *p_head_point = newNode;
}

void SingleListPopBack(SingleList **p_head_point) {
    assert(p_head_point);
    if (*p_head_point == NULL) {
        return;
    }
    if ((*p_head_point)->next == NULL) {
        free(*p_head_point);
        *p_head_point = NULL;
    } else {
        /*SingleList* prev = NULL;
        SingleList* tail = *p_head_point;
        while (tail->next!=NULL) {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;*/
        SingleList *tail = *p_head_point;
        while (tail->next->next != NULL) {
            tail = tail->next;
        }
        free(tail->next);
        tail->next = NULL;
    }
}

void SingleListPopFront(SingleList **p_head_point) {
    assert(p_head_point);
    if (*p_head_point == NULL) {
        return;
    }
    SingleList *next = (*p_head_point)->next;
    free(*p_head_point);
    *p_head_point = next;
}

SingleList *SingleListFind(SingleList *p_head_point, SingListDataType element) {
    SingleList *current = p_head_point;
    while (current) {
        if (current->data == element) {
            return current;
        } else {
            current = current->next;
        }
    }
    return NULL;
}

void SingleListInsert(SingleList **p_head_point, SingleList *position, SingListDataType element) {
    assert(p_head_point);
    SingleList *newNode = BuyListNode(element);
    if (*p_head_point == position) {
        newNode->next = *p_head_point;
        *p_head_point = newNode;
    } else {
        // 找到position的前一个位置
        SingleList *positionPrev = *p_head_point;
        while (positionPrev->next != position) {
            positionPrev = positionPrev->next;
        }
        positionPrev->next = newNode;
        newNode->next = position;
    }
}

void SingleListInsertAfter(SingleList *position, SingListDataType element) {
    assert(position);
    SingleList *newNode = BuyListNode(element);
    newNode->next = position->next;
    position->next = newNode;
}

// 时间复杂度是O(n)
void SingleListErase(SingleList **p_head_point, SingleList *position) {
    assert(p_head_point);
    if (*p_head_point == position) {
        *p_head_point = position->next;
        free(position);
    } else {
        SingleList *prev = *p_head_point;
        while (prev->next != position) {
            prev = prev->next;
        }
        prev->next = position->next;
        free(position);
    }
}

void SingleListEraseAfter(SingleList **p_head_point, SingleList *position) {
    assert(position->next); // 防止最后一个为空
    SingleList *nextDelete = position->next;
    position->next = nextDelete->next;
    free(nextDelete);
}

void SingleListDestroy(SingleList **p_head_point) {
    SingleList *current = *p_head_point;
    while (current != NULL) {
        SingleList *next = current->next;
        free(current);
        current = next;
    }
    *p_head_point = NULL;
}
