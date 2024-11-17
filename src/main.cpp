#include <iostream>
#include "../include/Board.hpp"

int main() {
    Board board1 = Board(10, 20);
    board1.newPiece();
    board1.printBoard();
}