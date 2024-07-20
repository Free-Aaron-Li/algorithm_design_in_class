// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'single_link'.
// Implementation of Single Linked List of Linear Table.
#ifndef ALGORITHM_DESIGN_SINGLE_LINK_H
#define ALGORITHM_DESIGN_SINGLE_LINK_H

#include <iostream>
#include <fmt/color.h>
#include <fmt/format.h>

/// 定义单链表节点类型
typedef struct LinkNode {
    int              data;  /// 每个节点存放一个数据元素
    struct LinkNode *next;  /// 指针指向下一个节点
} *LinkList;

/// 初始化一个空的单链表
bool
initList_null(LinkList &L);  /// 操作一个指向单链表的指针，而非直接操作单链表本身。

/// 初始化一个带头指针的单链表
bool
initList_leader(LinkList &L);

/// 判断单链表是否为空
bool
empty(LinkList L);

/**@{
 * @brief 插入操作
 */

/**
 * @brief 按位序插入（带头节点）
 * <p>
 * 在第time个位置插入元素value
 */
bool
ListInsert_leader(LinkList &L, int time, int value);

/// 按位序插入（不带头节点）
bool
ListInert_null(LinkList &L, int time, int value);

/// 后插操作
bool
InsertNextNode(LinkNode *point, int value);

/// @brief 前插操作
bool
InsertPriorNode(LinkNode *point, int value);
/** }@
 */

/**@{
 * 删除操作
 */

/// 带头节点，按位序删除
bool
ListDelete(LinkList &L, int time, int &value);

/// 指定节点的删除
/// @bug 无法删除最后一个节点
bool
DeleteNode(LinkNode *point);
/**}@
 *
 */

/**@{
 * 查找操作
 */

/**
 * @brief  按位查找（带头节点）
 * @return 第time个元素
 */
LinkNode *
GetElem(LinkList L, int time);

/// 按值查找
LinkNode *
LocateElem(LinkList L, int value);
/**}@
 */

/// 表的长度
int
length(LinkList L);

/**@{
 * 单链表的建立
 */

/// 头插法
LinkList
List_HeadInsert(LinkList &L);

/// 尾插法
LinkList
List_TailInsert(LinkList &L);

/**@}
 *
 */
#endif  // ALGORITHM_DESIGN_SINGLE_LINK_H
