// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'double_link'.
// The definition and basic operations of a doubly linked list.
#ifndef ALGORITHM_DESIGN_DOUBLE_LINK_HPP
#define ALGORITHM_DESIGN_DOUBLE_LINK_HPP

#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>

typedef struct DLinkNode {
    int               data;
    struct DLinkNode *prior;  /// 前驱
    struct DLinkNode *next;   /// 后继
} DLinkNode, *DLinkList;

/// 初始化
bool
InitDLinkList(DLinkList &L);

/**
 * @brief 插入
 * @note 将节点next_node插入到current_node之后
 */
bool
InsertNextDNode(DLinkNode *current_node, DLinkNode *next_node);

/// 删除
bool
DeleteNextDNode(DLinkNode *current_node);

/// 销毁链表
bool
DestroyList(DLinkList &L);

/**@{
 * 遍历
 */

/// 前向遍历


/**}@
 *
 */
#endif  // ALGORITHM_DESIGN_DOUBLE_LINK_HPP
