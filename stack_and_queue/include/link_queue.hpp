// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'link_queue'.
// Definition and Basic Operation of chain-mapped queues.
#ifndef ALGORITHM_DESIGN_LINK_QUEUE_HPP
#define ALGORITHM_DESIGN_LINK_QUEUE_HPP

typedef struct LinkNode {
    int              data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue {
    LinkNode *front;  /// 队头
    LinkNode *rear;   /// 队尾
} LinkQueue;

/**
 * @brief 初始化
 */
void
InitQueue(LinkQueue &q);

/**
 * @brief 入队操作
 */
void
EnQueue(LinkQueue &q, int value);

/**
 * @brief 出队操作
 */
bool
DeQueue(LinkQueue &q, int value);
#endif  // ALGORITHM_DESIGN_LINK_QUEUE_HPP
