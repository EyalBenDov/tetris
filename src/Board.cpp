#include <iostream>
#include <cstdlib>
#include "../include/Shapes.hpp"

class Board {
    public:
        Board(unsigned int boardWidth, unsigned int boardHeight) {
            width = boardWidth;
            height = boardHeight;
            board = (int**) calloc(height*width, sizeof(int));
            location[0] = 0;
            location[1] = 0;
            currentRotation = 0;
            gameEnded = false;
            pieceOnGround = false;
            latestShape = -1;
        }
        
        void initializeBoard() {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    board[i][j] = 0;
                }
            }
        }
        void newPiece(int pieceType) {
            latestShape = rand() % 7;
            Shapes newShape = Shapes(latestShape);
            int** points = newShape.getShape(0);
            currentRotation = 0;
            location[0] = width/2;
            location[1] = 0;
            for (int i = 0; i < 4; i += 1) {
                int* current_point = points[i];
                board[location[1]+current_point[1]][location[0]+current_point[0]] = 2;

            }
        }

        void movePiece(int direction) {
            Shapes shape = Shapes(latestShape);
            int** points = shape.getShape(currentRotation);
            bool valid = true;
            for (int i = 0; i < 4; i++) {
                int x = location[0] + points[i][0];
                if (x + direction >= width || x + direction < 0) {
                    valid = false;
                } 
            }
            if (!valid) {
                return;
            }
            for (int i = 0; i < 4; i++) {
                board[location[1] + points[i][1]][location[0] + points[i][0]] = 0;
            }
            for (int i = 0; i < 4; i++) {
                board[location[1] + points[i][1]][location[0] + points[i][0] + direction] = 2;
            }
        }
        void rotatePiece();
        void printBoard();
        void updateBoard();
        void moveDown() ;


        bool isOver() {
            return isOver;
        }
    private:
        int width;
        int height;
        int **board;
        int location[2];
        bool gameEnded;
        bool pieceOnGround;
        int currentRotation;
        int latestShape;

};