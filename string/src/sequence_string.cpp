// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_string'.
// Implementation of 'sequence_string.hpp'
#include "sequence_string.hpp"

bool
SubString(SqString& sub, const SqString& s, int pos, int len) {
    if (pos + len - 1 > s.length)  /// 越界
        return false;
    for (int i = pos; i < pos + len; ++i)
        sub.data[i - pos] = s.data[i];
    sub.length = len;
    return true;
}

int
StrCompare(const SqString& s, const SqString& t) {
    for (int i = 0; i < s.length && i < t.length; ++i)
        if (s.data[i] != t.data[i])
            return s.data[i] - t.data[i];  /// 比较相同下标字符

    return s.length - t.length;  /// 比较字符串长度
}

int
Index(const SqString& s, const SqString& t) {
    if (s.length < t.length)
        return -1;

    int      index = 0;
    SqString temp;                              /// 暂存字串
    while (index <= s.length - t.length + 1) {  /// 确定范围
        SubString(temp, s, index, t.length);
        if (StrCompare(temp, t) != 0)
            ++index;
        else
            return index;
    }
    return -1;  /// s中不存在与t相等的字串
}

int
Index1(const SqString& s, const SqString& t) {
    int s_index = 0;
    int t_index = 0;

    while (s_index <= s.length && t_index <= t.length) {  /// 等于字串长度是为了反映模式串匹配成功
        if (s.data[s_index] == t.data[t_index]) {         /// 同位字符相等，向后比较
            ++s_index;
            ++t_index;
        } else {
            s_index = s_index - t_index + 1;  /// 主串指针向后移动一单位
            t_index = 0;                      /// 模式串指针归位
        }

        if (t_index >= t.length)        /// 模式串指针溢出，则证明匹配成功
            return s_index - t.length;  /// 返回字串起始位置
    }
    return -1;
}

auto
Index_KMP(const SqString& s, const SqString& sqstring) -> int {
    int s_index = 0;
    int t_index = 0;

    int next[] = {};

    while (s_index <= s.length && t_index <= sqstring.length) {  /// 等于字串长度是为了反映模式串匹配成功
        if (t_index == 0 || s.data[s_index] == sqstring.data[t_index]) {  /// 同位字符相等，向后比较
            ++s_index;
            ++t_index;
        } else {
            t_index = next[t_index];  /// 模式串向右移动
        }

        if (t_index >= sqstring.length)        /// 模式串指针溢出，则证明匹配成功
            return s_index - sqstring.length;  /// 返回字串起始位置
    }
    return -1;
}

void
get_next(const SqString& t, int* next) {
    int i = 1;
    int j = 0;

    next[1] = 0;
    while (i < t.length) {
        if (j == 0 || t.data[i] == t.data[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
    }
}
