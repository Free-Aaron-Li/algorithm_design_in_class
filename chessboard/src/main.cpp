//
// This 'main' belongs to the 'algorithm_design',part of the 'chessboard' project
//
// Created by aaron on 23-9-26.
// Copyright (c) 2023 aaron. All rights reserved.
//
// The source file follows the GPL3.0 protocol and is distributed with the file.
// If you do not receive the GPL3.0 protocol ontology or you find a bug,
// please let me know (email: fly_aaron.li@outlook.com)
#include <iostream>
#include <vector>

#define BOARD_POSITION 0

std::vector<std::vector<int>>& creatVector(std::vector<std::vector<int>>& vector, const int& size, int default_number);
void                           printer(const std::vector<std::vector<int>>& vector);
void                           cover(int ll, int lc, int sl, int sc, int board_size);
void                           ui();

/** chess board object */
std::vector<std::vector<int>> chess_board;

int main() { ui(); }

/**
 * @title
 * creatVector
 * @description
 * Creates a two-dimensional vector and fills the specified element
 * @memberof
 * vector: Two-dimensional vector Object
 * @memberof
 * size: The range of two-dimensional vector, dimensional-length consistency
 * @memberof
 * default_number: Default fill number
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
 * Printing vector elements
 * @memberof
 * vector: Two-dimensional vector Object
 * @return
 * null
 */
void printer(const std::vector<std::vector<int>>& vector) {
    for (const auto& c : vector) {
        for (const auto& b : c) {
            std::cout << b << "\t";
        }
        std::cout << "\n";
    }
}


int  title = 0;
/**
 * @title
 * cover
 * @description
 * Overlay board
 * @memberof
 * ll: The <b>line number</b> that determines the position of the square in the <b>top left</b> corner of the board
 * @memberof
 * lc: The <b>column number</b> that determines the position of the square in the <b>top left</b> corner of the board
 * @memberof
 * sl: The <b>row position</b> coordinates of a particular square
 * @memberof
 * sc: The <b>column position</b> coordinates of a particular square
 * @memberof
 * board_size: Chess_board size
 * @return
 * null
 */
void cover(int ll, int lc, int sl, int sc, int board_size) {
    if (board_size == 1)
        return;

    int t = title++;        /* L-shaped square number */
    int s = board_size / 2; /* Split board */

    /** Cover the top left sub_chess_board */
    if (sl < ll + s && sc < lc + s) /* Identify the special square in this sub_chess_board */
        cover(ll, lc, sl, sc, s);
    else { /* no special square in this sub_chess_board */
        chess_board[ll + s - 1][lc + s - 1]
          = t; /* Cover the lower right corner of the sub_chess_board with an L-shaped square code-named t */
        cover(ll, lc, ll + s - 1, lc + s - 1, s); /* cover other squares */
    }

    /** Cover the top right sub_chess_board */
    if (sl < ll + s && sc >= lc + s)
        cover(ll, lc + s, sl, sc, s);
    else {
        chess_board[ll + s - 1][lc + s] = t;
        cover(ll, lc + s, ll + s - 1, lc + s, s);
    }

    /** Cover the lower left sub_chess_board */
    if (sl >= ll + s && sc < lc + s)
        cover(ll + s, lc, sl, sc, s);
    else {
        chess_board[ll + s][lc + s - 1] = t;
        cover(ll + s, lc, ll + s, lc + s - 1, s);
    }

    /** Cover the lower right sub_chess_board */
    if (sl >= ll + s && sc >= lc + s)
        cover(ll + s, lc + s, sl, sc, s);
    else {
        chess_board[ll + s][lc + s] = t;
        cover(ll + s, lc + s, ll + s, lc + s, s);
    }
}


void ui() {
    /** Overwrites chess_board numbers by default */
    int default_number = 0;
    int board_size     = 0;
    int x = 0, y = 0;
    std::cout << "Please enter the board size: ";
    std::cin >> board_size;
    std::cout << "Please enter the line coordinate for the special grid: ";
    std::cin >> x;
    std::cout << "Please enter the column coordinate for the special grid: ";
    std::cin >> y;
    creatVector(chess_board, board_size, default_number);
    cover(BOARD_POSITION, BOARD_POSITION, x, y, board_size);
    printer(chess_board);
}