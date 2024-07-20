// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'main'.
// Linear table test entrance.
#include "sequence.hpp"
#include "single_link.hpp"
#include "static_link.hpp"

void
sequence_test() {
    SqlList_static  L;    /// 声明一个静态顺序表
    SqlList_dynamic L_d;  /// 声明一个动态顺序表

    InitList_static(L);  /// 初始化顺序表
    InitList_dynamic(L_d);
    IncreaseSize(L_d, 5);

    int temp_value = 3;
    fmt::print("{}\n", ListDelete(L, 2, temp_value));  /// true
    fmt::print("{}\n", ListInsert(L, 2, 3));           /// true
    fmt::print("{}\n", temp_value);                    /// 0

    fmt::print("{}\n", GetElem_time(L, 2));      /// 3
    fmt::print("{}\n", LocateElem_value(L, 3));  /// 2
}

void
single_link_test() {
    LinkList L;
    L = List_TailInsert(L);
    fmt::print("{}\n", length(L));
}

void
static_link_test() {
    struct SLinkNode x;
    fmt::print("{}\n", sizeof(x));

    struct SLinkNode a[STATIC_LINKNODE_MAXSIZE];
    fmt::print("{}\n", sizeof(a));

    SLinkList b;
    fmt::print("{}\n", sizeof(b));
}

int
main() {
    // sequence_test();
    // single_link_test();
    static_link_test();
    return 0;
}