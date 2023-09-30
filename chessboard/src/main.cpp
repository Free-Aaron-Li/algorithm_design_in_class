//
// This 'main' belongs to the 'algorithm_design',part of the 'chessboard' project
//
// Created by aaron on 23-9-26.
// Copyright (c) 2023 aaron. All rights reserved.
//
// The source file follows the GPL3.0 protocol and is distributed with the file. If you do not receive the GPL3.0 protocol ontology or you
// find a bug,
// please let me know (email: fly_aaron.li@outlook.com)
#include <iostream>
#include <vector>

std::vector<std::vector<int>>& creatVector(std::vector<std::vector<int>>& vector, const int& size, int default_number);
void                           printer(const std::vector<std::vector<int>>& vector);

int main() {
    int                           default_number = -1;
    int                           board_size     = 4;
    std::vector<std::vector<int>> vector;
    creatVector(vector, board_size, default_number);
    printer(vector);
}

/**
 * @title
 * creatVector
 * @description
 * Creates a two-dimensional vector and fills the specified element
 * @memberof
 * vector: two-dimensional vector Object
 * @memberof
 * size: the range of two-dimensional vector, dimensional-length consistency
 * @memberof
 * default_number: default fill number
 * @return
 * Vector object
 */
std::vector<std::vector<int>>& creatVector(std::vector<std::vector<int>>& vector, const int& size, int default_number) {
    vector.resize(size, std::vector<int>(size, default_number));
    return vector;
}

/**
 * @title
 * printer
 * @description
 * printing vector elements
 * @memberof
 * vector: two-dimensional vector Object
 * @return
 * null
 */
void printer(const std::vector<std::vector<int>>& vector) {
    for (const auto& c : vector) {
        for (const auto& b : c) {
            std::cout << b << " ";
        }
        std::cout << "\n";
    }
}
