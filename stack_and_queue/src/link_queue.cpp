// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'link_queue'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "link_queue.hpp"

void
InitQueue(LinkQueue& q) {
    q.front = q.rear = new LinkNode;  /// 队头和队尾指向同一节点
    q.front->next    = nullptr;
    q.rear->next     = nullptr;
}

void
EnQueue(LinkQueue& q, int value) {
    auto new_node  = new LinkNode;
    new_node->data = value;
    new_node->next = nullptr;
    q.rear->next   = new_node;  /// 插入新节点
    q.rear         = new_node;  /// 移动表尾指针
}

bool
DeQueue(LinkQueue& q, int value) {
    if (q.front == q.rear)  /// 空队
        return false;
    auto pointer  = q.front->next;
    value         = pointer->data;  /// 返回队头元素
    q.front->next = pointer->next;  /// 修改头节点的next指针
    if (q.rear == pointer)          /// 最后一个节点
        q.rear = q.front;
    delete (pointer);
    return true;
}
