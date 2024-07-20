// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'double_link'.
// 'double_link.hpp' implementation.
#include "double_link.hpp"

bool
InitDLinkList(DLinkList &L) {
    try {
        L = new DLinkNode;
    } catch (const std::bad_alloc &exception) {
        delete (L);
        return false;
    }

    L->prior = nullptr;
    L->next  = nullptr;
    return true;
}

bool
InsertNextDNode(DLinkNode *current_node, DLinkNode *next_node) {
    if (current_node == nullptr || next_node == nullptr)  /// 非法参数
        return false;
    next_node->next = current_node->next;
    if (current_node->next != nullptr)  /// 当前节点有后继节点
        current_node->next->prior = next_node;
    next_node->prior   = current_node;
    current_node->next = next_node;
    return true;
}

bool
DeleteNextDNode(DLinkNode *current_node) {
    if (current_node == nullptr)
        return false;
    auto next_node = current_node->next;
    if (next_node == nullptr)  /// 没有找到后继
        return false;
    current_node->next = next_node->next;
    if (next_node->next != nullptr)
        next_node->next->prior = current_node;
    delete (next_node);
    return true;
}

bool
DestroyList(DLinkList &L) {
    while (L->next != nullptr)  /// 循环释放各个数据节点
        DeleteNextDNode(L);
    delete (L);   /// 释放头节点
    L = nullptr;  /// 置空，方式野指针
    return true;
}
