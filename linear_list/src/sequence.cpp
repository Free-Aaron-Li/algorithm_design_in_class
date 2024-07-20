// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence'.
// 'sequence.h' implementation.
#include "sequence.hpp"

void
InitList_static(SqlList_static &L) {
    for (int i = 0; i < L.length; ++i)
        i = 0;                           /// 将所有数据元素设置为默认初始化值
    L.length = STATIC_LINKNODE_MAXSIZE;  /// 顺序表初始长度为0
}

void
InitList_dynamic(SqlList_dynamic &L) {
    L.data    = new int[INITSIZE];  /// 申请一块默认大小的连续的存储空间
    L.length  = INITSIZE;
    L.Maxsize = INITSIZE;
}

void
IncreaseSize(SqlList_dynamic &L, const int len) {
    const auto point = L.data;
    L.data           = new int[L.Maxsize + len];  /// 扩展指定大小的空间
    for (int i = 0; i < L.length; ++i)
        L.data[i] = point[i];     /// 将数据复制到新区域
    L.Maxsize = L.Maxsize + len;  /// 顺序表最大长度增加到 len
    delete (point);               /// 释放原来的内存空间
}

bool
ListInsert(SqlList_static &L, const int i, const int e) {
    if (i < 1 || i > L.length + 1 || L.length >= STATIC_LINKNODE_MAXSIZE)  /// i的范围是否有效，且存储空间是否已满
        return false;
    for (int j = L.length; j >= i; --j)  /// 将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;  /// 在位置i处放入e。
    ++L.length;         /// 长度加1
    return true;
}

bool
ListDelete(SqlList_static &L, const int i, int &e) {
    if (i < 1 || i > L.length)  /// i的范围是否有效
        return false;
    e = L.data[i - 1];                  /// 将被删除匀速赋值给e
    for (int j = i; j < L.length; ++j)  /// 将第i个位置的元素前移
        L.data[j - 1] = L.data[j];
    --L.length;
    return true;
}

int
GetElem_time(const SqlList_static &L, const int time) {
    return L.data[time - 1];
}

int
LocateElem_value(const SqlList_static &L, const int value) {
    for (int i = 0; i < L.length; ++i)
        if (L.data[i] == value)
            return i + 1;
    return -1;
}