#include <windows.h> // 防止输出乱码, 不重要
#include "SequenceList.h"

void TestSequenceList() {
    SequenceList sequence_list;
    // 初始化线性表
    SequenceInitList(&sequence_list);
    // 末尾插入数据
    for (int i = 1; i <= 3; i++) {
        SequencePushBack(&sequence_list, i);
    }
    // 打印数据
    SequencePrint("末尾插入数据后测试", &sequence_list);
    // 末尾删除数据
    for (int i = 1; i <= 1; i++) {
        SequencePopBack(&sequence_list);
    }
    SequencePrint("末尾删除数据测试", &sequence_list);
    for (int i = 1; i <= 3; i++) {
        SequencePushFront(&sequence_list, i * 10);
    }
    SequencePrint("测试头插", &sequence_list);

    SequencePopFront(&sequence_list);
    SequencePrint("测试头删", &sequence_list);
    printf("找到元素的下标为%d\n", SequenceListFind(&sequence_list, 2));
    SequenceListInsert(&sequence_list, 2, 5);
    SequenceListInsert(&sequence_list, 0, -1);
    SequenceListInsert(&sequence_list, 6, 50);
    SequencePrint("指定位置插入数据", &sequence_list);
    SequenceListErase(&sequence_list, 1);
    SequencePrint("指定位置删除数据", &sequence_list);
    SequenceListDestory(&sequence_list);
}

int main(void) {
    SetConsoleOutputCP(65001); // 防止输出乱码, 不重要
    TestSequenceList();
    return 0;
}
