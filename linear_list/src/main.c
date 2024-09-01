// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'main'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "single_linked_list.h"

/**
* 带头节点点链表操作
*/
void
test_single_linked_list_with_head() {
    LinkList L1 = NULL;
    initList_with_head(&L1); /// 初始化
    insert_node_by_header_with_head(&L1); /// 带头节点头插节点
    //insert_node_by_tail_with_head(&L1); /// 带头节点尾插节点
    display_with_head(L1); /// 打印表
    printf("\n%d", Length(L1)); /// 打印表长度
}

/**
 * 不带头节点链表操作
 */
void
test_single_linked_list_not_head() {
    LinkList L2 = NULL;
    initList_not_head(&L2);
    // insert_node_by_header_not_head(&L2);
    insert_node_by_tail_not_head(&L2);
    display_not_head(L2);
    printf("\n%d", Length(L2)); /// 打印表长度

    const LNode* node1 = GetElem(L2, 1);
    const LNode* node2 = LocateElem(L2, 2);
    if (node1 == NULL)
        printf("\nNULL");
    else
        printf("\n%d", node1->data); /// 按序号查找
    if (node2 == NULL)
        printf("\nNULL");
    else
        printf("\n%d", node2->data); /// 按值查找
}

int
main() {
    // test_single_linked_list_with_head();
    test_single_linked_list_not_head();
    return 0;
}