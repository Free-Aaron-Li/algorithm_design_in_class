// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'link_string'.
// If there are no special instructions, this file is used as an exercise and test file.
// Definition and Base operations of String for link mapping.
#ifndef ALGORITHM_DESIGN_LINK_STRING_HPP
#define ALGORITHM_DESIGN_LINK_STRING_HPP

#include <fmt/core.h>

#define LINK_STRING_NODE_SIZE 4

typedef struct StringNode {
    char               data[LINK_STRING_NODE_SIZE];  /// 通过存储多个字节，增加存储密度
    struct StringNode *next;
} StringNode, *String;
#endif  // ALGORITHM_DESIGN_LINK_STRING_HPP
