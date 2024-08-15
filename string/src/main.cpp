// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'main'.
// Ingress for string implementation.
#include <iostream>
#include "sequence_string.hpp"

void
sequence_string_test() {
    SqString str1 = {"hello world!"};
    str1.length   = 12;
    SqString str2;
    SubString(str2, str1, 0, 5);

    fmt::print("{}\n", str1.data);    /// hello world!
    fmt::print("{}\n", str1.length);  /// 12
    fmt::print("{}\n", str2.data);    /// hello

    SqString str3 = {"world"};
    str3.length   = 5;
    fmt::print("{}\n", Index(str1, str3));   /// 6
    fmt::print("{}\n", Index1(str1, str3));  /// 6
}

int
main() {
    sequence_string_test();
    return 0;
}