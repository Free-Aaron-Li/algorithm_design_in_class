// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'link_tree'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "link_tree.hpp"

/**
 * @brief 空树
 */
BiTree root = nullptr;

int
treeDepth(BiTree const& t) {
    if (t == nullptr)
        return 0;
    else {
        /// 后序遍历的变种
        int l = treeDepth(t->_lchild);
        int r = treeDepth(t->_rchild);
        return l > r ? l + 1 : r + 1;  /// 树的深度=Max（左子树深度，右子树深度）+1
    }
}
