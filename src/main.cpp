#include <iostream>
#include "../include/Board.hpp"
#include "../include/Shapes.hpp"

int main() {
    // Shapes shape1 = Shapes(0);
    // std::cout << shape1.getL(0)[0][0];
    Board board1 = Board();
    board1.initializeBoard();
    board1.newPiece();
    // board1.newPiece();
    board1.moveDown();
    board1.moveDown();
    board1.moveDown();
    board1.moveDown();
    board1.moveDown();
    board1.moveDown();

    board1.printBoard();

}