// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'link_tree'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef ALGORITHM_DESIGN_LINK_TREE_HPP
#define ALGORITHM_DESIGN_LINK_TREE_HPP

typedef struct ElemType {
    int _value;
} ElemType;

typedef struct BiTNode {
    ElemType        _data;       /// 数据域
    struct BiTNode *_lchild;     /// 左孩子指针
    struct BiTNode *_rchild;     /// 右孩子指针
    int             ltag, rtag;  /// 左、右线索标志
} BiTNode, *BiTree;

/**
 * @brief 树的深度
 */
int
treeDepth(const BiTree &t);
#endif  // ALGORITHM_DESIGN_LINK_TREE_HPP
