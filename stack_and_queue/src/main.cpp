// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'algorithm_design' project.
// This program is called: 'main'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "sequence_stack.hpp"
#include "circular_queue.hpp"

void
sequence_stack_test() {
    SqStack s;
    for (int i = 0; i < SEQUENCE_STACK_MAXSIZE; ++i)
        Push(s, i);

    int value = -1;
    for (int i = 0; i < SEQUENCE_STACK_MAXSIZE; ++i) {
        Pop(s, value);
        fmt::print("{}\t", value);
    }
}

void
circular_queue_test() {
    CirQueue q;
    for (int i = 0; i < CIRCULAR_QUEUE_MAXSIZE; ++i)
        EnQueue(q, i);

    int value = -1;
    for (int i = 0; i < CIRCULAR_QUEUE_MAXSIZE; ++i) {
        DeQueue(q, value);
        fmt::print("{}\t", value);
    }
}

int
main() {
    // sequence_stack_test();
    circular_queue_test();
    return 0;
}