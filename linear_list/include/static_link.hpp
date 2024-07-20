// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'static_link'.
// Static data linked list definition and basic operation.
#ifndef ALGORITHM_DESIGN_STATIC_LINK_HPP
#define ALGORITHM_DESIGN_STATIC_LINK_HPP

#include <fmt/core.h>
#include <fmt/format.h>

#define STATIC_LINKNODE_MAXSIZE 10  /// 静态链表的最大长度

typedef struct SLinkNode {
    int data{};     /// 存储数据元素
    int next = -2;  /// 下一个元素的下标，默认空节点下标为-2
} SLinkNode, SLinkList[STATIC_LINKNODE_MAXSIZE];


#endif  // ALGORITHM_DESIGN_STATIC_LINK_HPP
