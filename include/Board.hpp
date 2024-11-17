#include <iostream>

class Board {
    public:
        Board(unsigned int board_width, unsigned int board_height);
        void newPiece(int pieceType);
        void movePiece(int direction);
        void rotatePiece();
        void printBoard();
        void initializeBoard();
        void updateBoard();
        void moveDown();
    private:  
        int width;
        int height;

};