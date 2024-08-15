// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'sequence_tree'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef ALGORITHM_DESIGN_SEQUENCE_TREE_HPP
#define ALGORITHM_DESIGN_SEQUENCE_TREE_HPP

#define SEQUENCE_TREE_MAXSIZE 100

typedef struct TreeNode {
    int  _value{};                     /// 节点数据元素
    bool _is_empty = true;             /// 节点是否为空
} TreeNode, t[SEQUENCE_TREE_MAXSIZE];  /// 从上到下，从左到右顺序存储


#endif  // ALGORITHM_DESIGN_SEQUENCE_TREE_HPP
