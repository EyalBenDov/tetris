#include <iostream>
#include <string>

#ifndef BOARD_H
#define BOARD_H
class Board {
    public:
        Board(unsigned int boardWidth, unsigned int boardHeight);
        void initializeBoard();
        void newPiece();
        void movePiece(int direction);
        void rotatePiece();
        void printBoard();
        void updateBoard();
        void moveDown();
        bool isOver();
    private:
        int width;
        int height;
        char ***board;
        int location[2];
        bool gameEnded;
        bool pieceOnGround;
        int currentRotation;
        int latestShape;
        std::string colorList[7];
        std::string currentColor;

};
#endif