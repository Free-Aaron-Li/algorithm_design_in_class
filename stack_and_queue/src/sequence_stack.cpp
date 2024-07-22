// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_stack'.
// Implementation of 'sequence_stack.cpp'.
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
    if (StackEmpty(s))  /// 栈空
        return false;
    value = s.data[s.top--];  /// 栈顶元素先出栈，再-1
    return true;
}

bool
GetTop(const SqStack& s, int& value) {
    if (StackEmpty(s))
        return false;
    value = s.data[s.top];
    return true;
}

bool
StackEmpty(const SqStack& s) {
    if (s.top == -1)
        return true;
    return false;
}

bool
bracket_check(std::string str, int length) {
    SqStack s;         /// 创建临时栈
    int     top_elem;  /// 栈顶元素

    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(s, str[i]);  /// 扫描到左括号，入栈
        } else {
            if (StackEmpty(s))  /// 扫描到右括号，且当前栈空
                return false;
            Pop(s, top_elem);  /// 栈顶元素出栈
            if (str[i] == ')' && top_elem != '(')
                return false;
            if (str[i] == ']' && top_elem != '[')
                return false;
            if (str[i] == '}' && top_elem != '{')
                return false;
        }
    }
    return StackEmpty(s);
}
