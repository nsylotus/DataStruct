#include <windows.h> // 防止输出乱码, 不重要
#include "SingleList.h"

void TestSingleListInsert() {
    SingleList *p_list = NULL;
    SingleListPushBack(&p_list, 1);
    SingleListPushBack(&p_list, 5);
    SingleListPushBack(&p_list, 2);
    SingleListPushBack(&p_list, 2);
    SingleListPushBack(&p_list, 2);
    SingleListPushBack(&p_list, 3);
    SingleListPushFront(&p_list, 999);
    SingleListPushFront(&p_list, 888);
    SingleListPrint(p_list);
    printf("\n");
    SingleListPopBack(&p_list);
    SingleListPopFront(&p_list);
    SingleListPrint(p_list);
    printf("\n");
    SingleList *position = SingleListFind(p_list, 2);
    int i = 1;
    while (position) {
        printf("第%d个position节点:%p->%d\n", i++, position, position->data);
        // SingleListFind除了有查找, 还有修改的作用
        position = SingleListFind(position->next, 2);
    }
    position = SingleListFind(p_list, 5);
    if (position) {
        SingleListInsert(&p_list, position, 50);
    }
    SingleListPrint(p_list);
    printf("\n");
    position = SingleListFind(p_list, 999);
    if (position) {
        SingleListInsert(&p_list, position, 888);
    }
    SingleListPrint(p_list);
    SingleListDestroy(&p_list);
    SingleListPrint(p_list);
}

int main(void) {
    SetConsoleOutputCP(65001); // 防止输出乱码, 不重要
    TestSingleListInsert();
    return 0;
}
