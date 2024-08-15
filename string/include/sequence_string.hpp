// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_string'.
// Definition and Base Operations of Sequence String.
#ifndef ALGORITHM_DESIGN_SEQUENCE_STRING_HPP
#define ALGORITHM_DESIGN_SEQUENCE_STRING_HPP

#include <fmt/core.h>

#define SEQUENCE_STRING_MAXSIZE 255

/**
 * @brief 静态数组实现
 */
typedef struct SqString {
    char data[SEQUENCE_STRING_MAXSIZE];  /// 字符串分配空间
    int  length;                         /// 串实际长度
} SqString;

/**
 * @brief 字串
 */
bool
SubString(SqString& sub, const SqString& s, int pos, int len);

/**
 * @brief 比较
 * <p>
 * 若s>t或s<t，则返回值为二者相同下标字符差值或字符串长度；若s=t，则返回值为0；
 */
int
StrCompare(const SqString& s, const SqString& t);

/**
 * @brief 定位
 */
int
Index(const SqString& s, const SqString& t);

/**
 * @brief 朴素模式匹配算法——实现2
 */
int
Index1(const SqString& s, const SqString& t);

/**
 * @brief KMP算法
 */
int
Index_KMP(const SqString& s, const SqString& sqstring);

/**
 * @brief 求解模式串的next数组
 */
void
get_next(const SqString& t, int next[]);
#endif  // ALGORITHM_DESIGN_SEQUENCE_STRING_HPP
