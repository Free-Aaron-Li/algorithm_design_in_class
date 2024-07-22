// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_stack'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef ALGORITHM_DESIGN_SEQUENCE_STACK_HPP
#define ALGORITHM_DESIGN_SEQUENCE_STACK_HPP

#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>

#define SEQUENCE_STACK_MAXSIZE 10

typedef struct SqStack {
    int data[SEQUENCE_STACK_MAXSIZE]{};  /// 静态数组存放栈中元素
    int top = -1;                        /// 栈顶指针，默认在栈底（-1）
} SqStack;

/**
 * @brief 进栈操作
 * <p>
 * 新元素入栈
 */
bool
Push(SqStack &s, int value);

/**
 * @brief 出栈操作
 */
bool
Pop(SqStack &s, int &value);

/**
 * @brief 读取栈顶元素操作
 */
bool
GetTop(const SqStack &s, int &value);

/**
 * @brief 判空
 */
bool
StackEmpty(const SqStack &s);

/**
 * @brief 应用——括号匹配
 */
bool
bracket_check(std::string str, int length);
#endif  // ALGORITHM_DESIGN_SEQUENCE_STACK_HPP
