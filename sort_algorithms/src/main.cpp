// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'main'.
// The user's application portal
#include "Sort.hpp"

int
main() {
    Sort sort(5000, 1, 10000);
    sort.display_mode(3, "/home/aaron/Downloads/test.txt");
    sort.select_sort();
    sort.bubble_sort();
    sort.insertion_sort();

    std::vector<int> data1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Sort             sort1(data1);
    sort1.display_mode(1);
    sort1.select_sort();
    return 0;
}
