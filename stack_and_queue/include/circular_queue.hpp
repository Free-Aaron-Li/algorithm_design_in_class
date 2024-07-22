// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'single_queue'.
// Definition and Basic Operation of Circular Queue.
#ifndef ALGORITHM_DESIGN_CIRCULAR_QUEUE_HPP
#define ALGORITHM_DESIGN_CIRCULAR_QUEUE_HPP

#include <fmt/core.h>

#define CIRCULAR_QUEUE_MAXSIZE 10

typedef struct CirQueue {
    int data[CIRCULAR_QUEUE_MAXSIZE]{};  /// 存放队列元素
    int front = 0;
    int rear  = 0;  /// 队头指针和队尾指针
    int size  = 0;  /// 队列长度
} CirQueue;

/**
 * @brief 入队操作
 */
bool
EnQueue(CirQueue &q, int value);

/**
 * @brief 出队操作
 */
bool
DeQueue(CirQueue &q, int &value);

/**
 * @brief 获得对头元素的值
 */
bool
GetHead(const CirQueue &q, int &value);
#endif  // ALGORITHM_DESIGN_CIRCULAR_QUEUE_HPP
