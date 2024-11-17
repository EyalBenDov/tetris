#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include "../include/Board.hpp"
#include "../include/Shapes.hpp"

const std::string colorList[7] = {"\x1B[48;5;1m", "\x1B[48;5;2m", "\x1B[48;5;4m", "\x1B[48;5;6m", "\x1B[48;5;7m", "\x1B[48;5;8m", "\x1B[48;5;28m"};

Board::Board() {
    location[0] = 0;
    location[1] = 0;
    currentRotation = 0;
    gameEnded = false;
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
    location[0] = width/2;
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
    std::cout << "\x1B[2J";
    std::string line = "";
    for (int i = 0; i < width*2; i++) {
        line += "─";
    }
    std::cout << "┌" << line << "┐" << std::endl;
    std::string clearEffects = "\x1B[0m";
    for (int i = 0; i < height; i++) {
        std::string currentRow = "│";
        for (int j = 0; j < width; j++) {
            std::string current = board[i][j];
            if (current == "-") {
                currentRow += colorList[latestShape] + "  " + clearEffects;
            } else if (current == "") {
                currentRow += clearEffects + "  ";
            }
            else {
                currentRow += current;
            }
        }
        currentRow += "│";
        std::cout << currentRow << std::endl;
    }
    std::cout << "└" << line << "┘";
}
// TODO: FINISH FUNCTION
int Board::updateBoard() {
    Shapes shape = Shapes(latestShape);
    std::array<std::array<int, 2>, 4> points = shape.getShape(latestShape);
    bool stopMoving = false;
    for (int i = 0; i < 4; i += 1) {
        if (points[i][1]+1 >= height) {
            stopMoving = true;
            break;
        }
        else if (board[points[i][1]+1][points[i][0]] != "" && board[points[i][1]+1][points[i][0]] != "-") {
            stopMoving = true;
            break;
        }
    }
    if (!stopMoving) return 0;
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
    return gameEnded;
}
