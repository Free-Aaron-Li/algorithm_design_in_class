// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'linked_list'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; /// 定义节点元素类型

/**
 * 单链表
 */
typedef struct LNode {
    ElemType      data;
    struct LNode* next;
} LNode,* LinkList;

/**
 * 打印单链表
 */
void
display_with_head(LinkList L);

void
display_not_head(LinkList L);

/**
 * 初始化（含有头节点）
 */
void
initList_with_head(LinkList* L);

/**
 * 初始化（不含头节点）
 */
void
initList_not_head(LinkList* L);

/// 插入节点
/// @{

/**
 * 头插法（带头节点）
 */
void
insert_node_by_header_with_head(const LinkList* L);

/**
 * 头插法（不带头节点）
 */
void
insert_node_by_header_not_head(LinkList* L);

/**
* 尾插法（带头节点）
*/
void
insert_node_by_tail_with_head(const LinkList* L);

/**
 * 尾插法（不带头节点）
 */
void
insert_node_by_tail_not_head(LinkList* L);

/// @}

/**
 * 获取表长
 */
int
Length(LinkList L);

/**
 * 按序号查找节点
 */
LNode*
GetElem(LinkList L, int index);

LNode*
LocateElem(LinkList L, ElemType value);

#endif  // LINKED_LIST_HPP