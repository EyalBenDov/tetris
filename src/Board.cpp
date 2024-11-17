#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/Board.hpp"
#include "../include/Shapes.hpp"

const std::string colorList[7] = {"\x1B[48;5;1m", "\x1B[48;5;2m", "\x1B[48;5;4m", "\x1B[48;5;6m", "\x1B[48;5;7m", "\x1B[48;5;8m", "\x1B[48;5;28m"};

Board::Board(unsigned int boardWidth, unsigned int boardHeight) {
    width = boardWidth;
    height = boardHeight;
    board = (std::string**) calloc(height*width, sizeof(char)*12);
    location[0] = 0;
    location[1] = 0;
    currentRotation = 0;
    gameEnded = false;
    pieceOnGround = false;
    latestShape = -1;
}

void Board::newPiece() {
    latestShape = rand() % 7;
    Shapes newShape = Shapes(latestShape);
    int** points = newShape.getShape(0);
    std::cout << "Made it here\n";
    currentRotation = 0;
    location[0] = width/2;
    location[1] = 0;
    for (int i = 0; i < 4; i += 1) {
        int* current_point = points[i];
        board[location[1]+current_point[1]][location[0]+current_point[0]] = "-";

    }
}

void Board::movePiece(int direction) {
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
        board[location[1] + points[i][1]][location[0] + points[i][0]] = "";
    }
    for (int i = 0; i < 4; i++) {
        board[location[1] + points[i][1]][location[0] + points[i][0] + direction] = "-";
    }
}
void Board::rotatePiece() {
    Shapes shape = Shapes(latestShape);
    int** points = shape.getShape(currentRotation+1);
    bool valid = true;
    for (int i = 0; i < 4; i++) {
        int x = location[0] + points[i][0];
        if (x >= width || x < 0) {
            valid = false;
        } 
    }
    if (!valid) {
        return;
    }
    int** old_points = shape.getShape(currentRotation);
    currentRotation++;
    for (int i = 0; i < 4; i++) {
        board[location[1] + old_points[i][1]][location[0] + old_points[i][0]] = "";
    }
    for (int i = 0; i < 4; i++) {
        board[location[1] + points[i][1]][location[0] + points[i][0]] = "-";
    }
}
void Board::printBoard() {
    std::cout << "\x1B[H";
    std::string line = "";
    for (int i = 0; i < width; i++) {
        line += "─";
    }
    std::cout << "┌" << line << "┐";
    std::string clearEffects = "\x1B[0m";
    for (int i = 0; i < height; i++) {
        std::string currentRow = "│";
        for (int j = 0; j < width; j++) {
            std::string current = board[i][j];
            if (current == "-") {
                currentRow += currentColor + " " + clearEffects;
            } else if (current == "") {
                currentRow += clearEffects + " ";
            }
            else {
                currentRow += current;
            }
        }
        currentRow += "│";
        std::cout << currentRow << "\n";
    }
    std::cout << "└" << line << "┘";
}

void Board::updateBoard() {
    int i;
};
void Board::moveDown() {
    int i;
};


bool Board::isOver() {
    return gameEnded;
}
