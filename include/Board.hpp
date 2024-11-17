#include <iostream>
#include <string>

#ifndef BOARD_H
#define BOARD_H
class Board {
    public:
        Board();
        void initializeBoard();
        void newPiece();
        void movePiece(int direction);
        void rotatePiece();
        void printBoard();
        int updateBoard();
        void moveDown();
        bool isOver();
    private:
        static const int width = 10;
        static const int height = 20;
        std::string board[height][width];
        int location[2];
        bool gameEnded;
        bool pieceOnGround;
        int currentRotation;
        int latestShape;
        std::string currentColor;

};
#endif