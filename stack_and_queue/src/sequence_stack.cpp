// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_stack'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "sequence_stack.hpp"

bool
Push(SqStack& s, int value) {
    if (s.top == SEQUENCE_STACK_MAXSIZE - 1)  /// 栈满
        return false;
    s.data[++s.top] = value;  /// 先+1，再加入新数据
    return true;
}

bool
Pop(SqStack& s, int& value) {
    if (s.top == -1)  /// 栈空
        return false;
    value = s.data[s.top--];  /// 栈顶元素先出栈，再-1
    return true;
}

bool
GetTop(const SqStack& s, int& value) {
    if (s.top == -1)
        return false;
    value = s.data[s.top];
    return true;
}
