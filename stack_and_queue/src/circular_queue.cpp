// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'single_queue'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "circular_queue.hpp"

bool
EnQueue(CirQueue& q, int value) {
    if (q.size == CIRCULAR_QUEUE_MAXSIZE)  /// 队满
        return false;
    q.data[q.rear] = value;                                  /// 将值插入队尾
    q.rear         = (q.rear + 1) % CIRCULAR_QUEUE_MAXSIZE;  /// 将队尾指针加1取模，确保可以往复存数据
    ++q.size;
    return true;
}

bool
DeQueue(CirQueue& q, int& value) {
    if (q.size == 0)  /// 队空
        return false;
    value   = q.data[q.front];
    q.front = (q.front + 1) % CIRCULAR_QUEUE_MAXSIZE;
    --q.size;
    return true;
}

bool
GetHead(const CirQueue& q, int& value) {
    if (q.size == 0)  /// 队空
        return false;
    value = q.data[q.front];
    return true;
}
