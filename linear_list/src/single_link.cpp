// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'single_link'.
// 'single_link.hpp' implementation.
#include "single_link.hpp"

bool
initList_null(LinkList &L) {
    L = nullptr;  /// 空表，防止脏数据
    return true;
}

bool
empty(LinkList L) {
    return (L == nullptr);
}

bool
initList_leader(LinkList &L) {
    /**
     * @brief 需要注意到：new分配内存失败，是直接返回异常的。所以执行L=nullptr其实是没有意义的。\n
     * 在使用malloc/calloc函数下，进行返回空指针判断则是非常好的编程习惯。
     */
    try {
        L = new LinkNode;                        /// 分配一个头节点
    } catch (const std::bad_alloc &exception) {  /// 内存不足，分配失败
        delete L;
        return false;
    }

    /*
    if (L == nullptr) {  /// 内存不足，分配失败
        delete (L);
        L = nullptr;
        return false;
    }
    */

    L->next = nullptr;  /// 头节点之后暂时还没有节点
    return true;
}

bool
ListInsert_leader(LinkList &L, const int time, const int value) {
    if (time < 1)  /// 单链表从1开始，而非从0开始（这只是一个杜撰的节点）
        return false;

    int  j       = 0;  /// 当前pointer指向的是第几个节点
    auto pointer = L;  /// 指针指向头节点
                       /// 指针pointer指向当前扫描到的节点

    while (pointer != nullptr && j < time - 1) {  /// 循环找到第time-1个节点
        pointer = pointer->next;
        ++j;
    }

    if (pointer == nullptr)  /// 如果查找的位序不存在
        return false;

    const auto new_node = new LinkNode;
    new_node->data      = value;  /// 注意以下两句不能颠倒，否则后续断链
    new_node->next      = pointer->next;
    pointer->next       = new_node;  /// 完成插入

    return true;
}

bool
ListInert_null(LinkList &L, int time, int value) {
    if (time < 1)  /// 单链表从1开始，而非从0开始（这只是一个杜撰的节点）
        return false;

    if (time == 1) {
        LinkNode *temp_node;
        try {
            temp_node = new LinkNode;
        } catch (const std::bad_alloc &exception) {
            delete temp_node;
            return false;
        }
        temp_node->data = value;
        temp_node->next = L;
        L               = temp_node;  /// 头指针指向新节点
        return true;
    }

    int  j       = 1;  /// 指向第一个节点
    auto pointer = L;  /// 指针指向头节点
                       /// 指针pointer指向当前扫描到的节点

    while (pointer != nullptr && j < time - 1) {  /// 循环找到第time-1个节点
        pointer = pointer->next;
        ++j;
    }

    if (pointer == nullptr)  /// 如果查找的位序不存在
        return false;

    const auto new_node = new LinkNode;
    new_node->data      = value;  /// 注意以下两句不能颠倒，否则后续断链
    new_node->next      = pointer->next;
    pointer->next       = new_node;  /// 完成插入

    return true;
}

bool
InsertNextNode(LinkNode *pointer, int value) {  /// 注意使用 LinkNode *pointer而非LinkNode &pointer
    if (pointer == nullptr)
        return false;
    LinkNode *next_node;
    try {
        next_node = new LinkNode;
    } catch (const std::bad_alloc &exception) {
        delete next_node;
        return false;
    }

    /// 后插
    next_node->data = value;
    next_node->next = pointer->next;
    pointer->next   = next_node;
    return true;
}

bool
InsertPriorNode(LinkNode *pointer, int value) {
    /// 注意使用 LinkNode *pointer而非LinkNode &pointer
    if (pointer == nullptr)
        return false;
    LinkNode *next_node;
    try {
        next_node = new LinkNode;
    } catch (const std::bad_alloc &exception) {
        delete next_node;
        return false;
    }

    /// 前插
    next_node->next = pointer->next;
    pointer->next   = next_node;
    next_node->data = pointer->data;  /// 替换二者数据，实现前插操作
    pointer->data   = value;
    return true;
}

bool
ListDelete(LinkList &L, int time, int &value) {
    if (time < 1)
        return false;
    int  j       = 0;                             /// 当前指针p指向的是第几个节点
    auto pointer = L;                             /// L指向头节点，头节点不存放数据。
    while (pointer != nullptr && j < time - 1) {  /// 查找第time-1个节点
        pointer = pointer->next;
        ++j;
    }
    if (pointer == nullptr)
        return false;
    if (pointer->next == nullptr)  /// 第time-1个节点之后无其他节点
        return false;

    auto delete_node = pointer->next;  /// 将被删除的节点
    value            = delete_node->data;
    pointer->next    = delete_node->next;
    delete (delete_node);  /// 释放被删除节点内存空间
    return true;
}

bool
DeleteNode(LinkNode *pointer) {
    if (pointer == nullptr)
        return false;
    auto delete_node = pointer->next;        /// 将pointer后继节点复制给pointer，删除pointer的后继节点
    pointer->data    = pointer->next->data;  /// 将后继节点内容复制给pointer
    pointer->next    = delete_node->next;    /// 将后继节点的后继节点复制给pointer，完成替换
    delete (delete_node);                    /// 删除pointer的后继节点
    return true;
}

LinkNode *
GetElem(LinkList L, int time) {
    if (time < 0)
        return nullptr;
    int  j       = 0;
    auto pointer = L;
    while (pointer != nullptr && j < time) {
        pointer = pointer->next;
        ++j;
    }
    return pointer;
}

LinkNode *
LocateElem(LinkList L, int value) {
    auto pointer = L->next;  /// pointer 指向第一个节点
    while (pointer != nullptr && pointer->data != value)
        pointer = pointer->next;
    return pointer;  /// 找到后返回该节点指针，否则返回nullptr
}

int
length(LinkList L) {
    int  length  = 0;
    auto pointer = L;
    while (pointer->next != nullptr) {
        pointer = pointer->next;
        ++length;
    }
    return length;
}

LinkList
List_HeadInsert(LinkList &L) {
    LinkNode *next_node;  /// 节点
    int       value;      /// 节点值
    L       = new LinkNode;
    L->next = nullptr;  /// 创建头节点，必须让头指针指向nullptr
    std::cin >> value;
    while (value != 9999) {
        next_node       = new LinkNode;
        next_node->data = value;
        next_node->next = L->next;
        L->next         = next_node;
        std::cin >> value;
    }

    return L;
}

LinkList
List_TailInsert(LinkList &L) {
    int value;  /// 节点值
    L               = new LinkNode;
    L->next         = nullptr;  /// 创建头节点
    auto prior_node = L;        /// 前节点
    auto next_node  = L;        /// 后节点

    std::cin >> value;       /// 输入节点值
    while (value != 9999) {  /// 输入9999，表示结束
        next_node        = new LinkNode;
        next_node->data  = value;
        prior_node->next = next_node;
        prior_node       = next_node;  /// 保证prior_node指向最后一个节点
        std::cin >> value;
    }
    prior_node->next = nullptr;

    return L;
}
