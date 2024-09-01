// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'linked_list'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "single_linked_list.h"

void
display_with_head(LinkList L) {
    printf("Linked List:\n");
    L = L->next; /// 排除头节点
    while (L != NULL) {
        printf("—> %d ", L->data);
        L = L->next; /// 指向下一个节点
    }
    printf("\n");
}

void
display_not_head(LinkList L) {
    printf("Linked List:\n");
    while (L != NULL) {
        printf("—> %d ", L->data);
        L = L->next; /// 指向下一个节点
    }
    printf("\n");
}

void
initList_with_head(LinkList* L) {
    /// 修改头指针本身，需要双重指针，避免初始化链表时采用值传递
    *L         = (LNode*) malloc(sizeof(LNode)); /// 创建头节点
    (*L)->next = NULL; /// 头节点下一节点为NULL
    if (*L == NULL) {
        exit(-1); // 如果内存分配失败，退出程序
    }
}

void
initList_not_head(LinkList* L) {
    *L = NULL; /// 不创建头节点
}

void
insert_node_by_header_with_head(const LinkList* L) {
    ElemType value; /// 新节点元素值
    printf("input node value, if input 9999 end input:\n");
    scanf("%d", &value);
    while (value != 9999) {
        /// 输入9999结束插入
        LNode* new_node = (LNode*) malloc(sizeof(LNode)); /// 新节点
        new_node->data  = value;
        new_node->next  = (*L)->next;
        (*L)->next      = new_node;
        scanf("%d", &value);
    }
}

void
insert_node_by_header_not_head(LinkList* L) {
    ElemType value;
    printf("input node value, if input 9999 end input:\n");
    scanf("%d", &value);
    *L         = (LNode*) malloc(sizeof(LNode)); /// 创建头节点（类同带头节点初始化操作）
    (*L)->next = NULL; /// 舍弃头节点赋值，保证尾节点指针置空
    while (value != 9999) {
        /// 输入9999结束插入
        LNode* new_node = (LNode*) malloc(sizeof(LNode)); /// 新节点
        new_node->data  = value;
        new_node->next  = (*L)->next;
        (*L)->next      = new_node;
        scanf("%d", &value);
    }
}

void
insert_node_by_tail_with_head(const LinkList* L) {
    ElemType value;
    LNode*   tail_node = (*L); /*/ 设置表尾指针，始终指向当前链表的尾节点*/
    printf("input node value, if input 9999 end input:\n");
    scanf("%d", &value);
    while (value != 9999) {
        LNode* new_node = (LNode*) malloc(sizeof(LNode));
        new_node->data  = value;
        tail_node->next = new_node;
        tail_node       = new_node;
        scanf("%d", &value);
    }
    tail_node->next = NULL; /// 尾节点指针置空
}

void
insert_node_by_tail_not_head(LinkList* L) {
    ElemType value;
    printf("input node value, if input 9999 end input:\n");
    scanf("%d", &value);
    if (value != 9999) {
        *L               = (LNode*) malloc(sizeof(LNode)); /// 创建头节点（类同带头节点初始化操作）
        (*L)->next       = NULL;
        (*L)->data       = value;
        LNode* tail_node = (*L); /// 尾节点
        scanf("%d", &value);
        while (value != 9999) {
            /// 输入9999结束插入
            LNode* new_node = (LNode*) malloc(sizeof(LNode)); /// 新节点
            new_node->data  = value;
            tail_node->next = new_node;
            tail_node       = new_node;
            scanf("%d", &value);
        }
        tail_node->next = NULL; /// 尾节点指针置空
    }
}

int
Length(const LinkList L) {
    int          counter = 1; /// 计数变量，数据节点个数
    const LNode* pointer = L; /// 表示 pointer 指针本身可以被修改，但是通过 pointer 指针所指向的对象的内容不可以被修改
    while (pointer->next != NULL) {
        pointer = pointer->next;
        ++counter;
    }
    return counter;
}

LNode*
GetElem(const LinkList L, const int index) {
    LNode* pointer             = L; /// 扫描指针
    int    current_node_number = 0; /// 当前节点序号
    while (pointer != NULL && current_node_number < index) {
        pointer = pointer->next;
        ++current_node_number;
    }
    return pointer;
}

LNode*
LocateElem(const LinkList L, const ElemType value) {
    LNode* pointer = L;
    while (pointer != NULL && pointer->data != value)
        pointer = pointer->next;
    return pointer;
}