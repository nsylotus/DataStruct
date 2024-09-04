#include "DoubleList.h"

void DoubleListTest() {
    DoubleList *doubleList = DoubleListInit();
    for (int i = 0; i < 5; i++) {
        DoubleListPushBack(doubleList, i);
    }
    DoubleListPrint(doubleList);
    DoubleListPopBack(doubleList);
    DoubleListPrint(doubleList);
    DoubleListDestroy(doubleList);
    doubleList = NULL;
}

void DoubleListPushFrontTest() {
    DoubleList *doubleList = DoubleListInit();
    for (int i = 0; i < 5; i++) {
        DoubleListPushFront(doubleList, i);
    }
    DoubleListPrint(doubleList);
    DoubleListPopFront(doubleList);
    DoubleListPrint(doubleList);
    printf("%d\n", DoubleListFind(doubleList, 2)->data);
    DoubleListDestroy(doubleList);
    doubleList = NULL;
}

void DoubleListInsertEraseTest() {
    DoubleList *doubleList = DoubleListInit();
    for (int i = 0; i < 50; i += 10) {
        DoubleListPushFront(doubleList, i);
    }
    DoubleListPrint(doubleList);
    DoubleList *position = DoubleListFind(doubleList, 20);
    if (position) {
        DoubleListErase(position);
    }
    DoubleListPrint(doubleList);
    position = DoubleListFind(doubleList, 10);
    if (position) {
        DoubleListInsert(position, 60);
    }
    DoubleListPrint(doubleList);
    DoubleListDestroy(doubleList);
    doubleList = NULL;
}

int main(void) {
    DoubleListTest();
    DoubleListPushFrontTest();
    DoubleListInsertEraseTest();
    return 0;
}
