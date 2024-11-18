#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <unistd.h>
#include "../include/Board.hpp"
#include "../include/Shapes.hpp"

const std::string colorList[7] = {"\x1B[48;5;196m", "\x1B[48;5;208m", "\x1B[48;5;39m", "\x1B[48;5;190m", "\x1B[48;5;201m", "\x1B[48;5;15m", "\x1B[48;5;28m"};

Board::Board() {
    location[0] = 0;
    location[1] = 0;
    currentRotation = 0;
    pieceOnGround = false;
    latestShape = -1;
}

void Board::initializeBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = "";
        }
    }
}

void Board::newPiece() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 6);
    latestShape = distr(gen);
    Shapes newShape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = newShape.getShape(0);
    currentRotation = 0;
    location[0] = width/2-1;
    location[1] = 0;
    for (int i = 0; i < 4; i++) {
        board[location[1]+points[i][1]][location[0]+points[i][0]] = "-";
    }
}

void Board::movePiece(int direction) {
    Shapes shape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = shape.getShape(currentRotation);
    bool valid = true;
    for (int i = 0; i < 4; i++) {
        int x = location[0] + points[i][0];
        if (x + direction >= width || x + direction < 0) {
            valid = false;
            break;
        } else if (board[location[1]+points[i][1]][x+direction] != "" && board[location[1]+points[i][1]][x+direction] != "-") {
            valid = false;
            break;
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
    location[0] += direction;
}
void Board::rotatePiece() {
    Shapes shape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = shape.getShape(currentRotation+1);
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
    std::array<std::array<int, 2>, 4> old_points = shape.getShape(currentRotation);
    currentRotation++;
    for (int i = 0; i < 4; i++) {
        board[location[1] + old_points[i][1]][location[0] + old_points[i][0]] = "";
    }
    for (int i = 0; i < 4; i++) {
        board[location[1] + points[i][1]][location[0] + points[i][0]] = "-";
    }
}

void Board::printBoard() {
    system("clear");
    std::cout << "\033[0;0H";
    std::cout << "\033[0;0f";
    std::cout << "\n";
    std::cout << "\033[8m";
    std::cout << "\033[0;0";
    std::string newBoard = "";
    std::string line = "";
    for (int i = 0; i < width*2; i++) {
        line += "─";
    }
    // newBoard += "┌" + line + "┐\n";
    std::string clearEffects = "\x1B[0m";
    std::cout << clearEffects + "┌" + line + "┐" + "\033[8m" << std::endl;
    for (int i = 0; i < height; i++) {
        std::string currentRow = clearEffects + "│";
        for (int j = 0; j < width; j++) {
            std::string current = board[i][j];
            if (current == "-") {
                currentRow += colorList[latestShape] + "  " + clearEffects + "\033[8m";
            } else if (current == "") {
                currentRow += clearEffects + "  " + "\033[8m";
            }
            else {
                currentRow += current + clearEffects + "\033[8m";
            }
        }
        currentRow += clearEffects + "│\033[8m";
        // newBoard += currentRow + "\n";
        std::cout << clearEffects + currentRow  + "\033[8m" << std::endl;
    }
    // new_board += "└" + line + "┘";
    std::cout << clearEffects + "└" + line + "┘" + "\033[8m" << std::endl;
    std::cout << "\033[0;0H";
    std::cout << "\033[0;0f";
    // const char *newBoardChar = newBoard.c_str();
    // std::cout << newBoardChar;
}

int Board::updateBoard() {
    Shapes shape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = shape.getShape(currentRotation);
    bool stopMoving = false;
    for (int i = 0; i < 4; i += 1) {
        if (points[i][1]+location[1] >= height-1) {
            stopMoving = true;
            break;
        }
        if (board[points[i][1]+1+location[1]][points[i][0]+location[0]] != "" && board[points[i][1]+1+location[1]][points[i][0]+location[0]] != "-") {
            stopMoving = true;
            break;
        }
    }
    if (!stopMoving) return 0;
    for (int i = 0; i < 4; i += 1) { 
        board[location[1] + points[i][1]][location[0] + points[i][0]] = colorList[latestShape] + "  ";
    }
    bool bottom_full = true;
    while (bottom_full) {
        int row = -1;
        for (int i = height-1; i > 0; i--) {
            bool row_full = true;
            for (int j = 0; j < width; j++) {
                if (board[i][j] == "") {
                    row_full = false;
                    break;
                }
            }
            if (row_full) {
                row = i;
                break;
            }
        }
        if (row == -1) break;
        for (int i = row; i > 1; i--) {
            for (int j = 0; j < width; j++) {
                board[i][j] = board[i-1][j];
            }
        }
    }
    return 1;
}

void Board::moveDown() {
    Shapes shape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = shape.getShape(currentRotation);
    for (int i = 0; i < 4; i++) {
        board[location[1] + points[i][1]][location[0] + points[i][0]] = "";
    }
    for (int i = 0; i < 4; i++) {
        board[location[1] + points[i][1]+1][location[0] + points[i][0]] = "-";
    }
    location[1]++;
};


bool Board::isOver() {
    for (int j = 0; j < width; j++) {
        if (board[1][j] != "" && board[1][j] != "-")
            return true;
    }
    return false;
}
