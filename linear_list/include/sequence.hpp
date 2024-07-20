// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence'.
// Sequential Mapping of Linear Tables.
#ifndef ALGORITHM_DESIGN_SEQUENCE_H
#define ALGORITHM_DESIGN_SEQUENCE_H

#include <fmt/core.h>
#include <fmt/format.h>

#define STATIC_LINKNODE_MAXSIZE 10  /// 定义最大长度
#define INITSIZE                10

typedef struct {
    int data[STATIC_LINKNODE_MAXSIZE];  /// 用静态的”数组“存放数据类型
    int length;                         /// 顺序表的当前长度
} SqlList_static;                       /// 顺序表的类型定义

typedef struct {
    int *data;      /// 指示动态分配数组的指针
    int  Maxsize;   /// 顺序表的最大容量
    int  length;    /// 顺序表的当前长度
} SqlList_dynamic;  /// 顺序表的类型定义

/// @brief 基本操作——初始化一个顺序表
void
InitList_static(SqlList_static &L);

void
InitList_dynamic(SqlList_dynamic &L);

/// @brief 增加动态数组的长度
void
IncreaseSize(SqlList_dynamic &L, int len);

/// @brief 插入元素
bool
ListInsert(SqlList_static &L, int i, int e);

/// @brief 删除元素
bool
ListDelete(SqlList_static &L, int i, int &e);

/// @brief <b>查找元素</b> \n
/// 按位查找
int
GetElem_time(const SqlList_static &L, int time);

/// @brief 按值查找
int
LocateElem_value(const SqlList_static &L, int value);

#endif  // ALGORITHM_DESIGN_SEQUENCE_H
