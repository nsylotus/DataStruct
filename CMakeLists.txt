cmake_minimum_required(VERSION 3.28)
project(DataStruct C)

set(CMAKE_C_STANDARD 17)

add_executable(DataStruct main.c)

add_executable(Array_Realize Linear_List/Array_Realize/main.c
        Linear_List/Array_Realize/SequenceList.c
        Linear_List/Array_Realize/SequenceList.h)
        
add_executable(SingleList_Realize Linear_List/SingleList_Realize/main.c
        Linear_List/SingleList_Realize/SingleList.c
        Linear_List/SingleList_Realize/SingleList.h)

add_executable(Double_Linked_List Linear_List/DoubleList/main.c
        Linear_List/DoubleList/DoubleList.c
        Linear_List/DoubleList/DoubleList.h)

add_executable(Stack Stack_Queue_Array/Stack/main.c
        Stack_Queue_Array/Stack/Stack.c
        Stack_Queue_Array/Stack/Stack.h)

add_executable(Queue Stack_Queue_Array/Queue/main.c
        Stack_Queue_Array/Queue/Queue.c
        Stack_Queue_Array/Queue/Queue.h)