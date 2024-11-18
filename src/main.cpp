#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include "../include/Board.hpp"

bool keyPressed(char key) {
    // IMPLEMENT
    return false;
}

int main() {
    clock_t startTime = clock();
    Board board = Board();
    board.initializeBoard();
    board.newPiece();
    bool up_held = false;
    bool right_held = false;
    bool left_held = false;
    double downDelay = 400;  
        // 65: up, 66: down, 67: right, 68: left
    board.printBoard();
    while (true) {
        bool change = false;
        if (keyPressed('q')) break;
        if (keyPressed(65)) {
            if (up_held == false) board.rotatePiece();
            up_held = true;
            change = true;
        } else {
            up_held = false;
        }
        if (keyPressed(67)) {
            if (up_held == false) board.movePiece(1);
            right_held = true;
            change = true;
        } else {
            right_held = false;
        }
        if (keyPressed(68)) {
            if (left_held == false) break;
            left_held = true;
            change = true;
        } else {
            left_held = false;
        }
        if (keyPressed(69)) {
            downDelay = 200;
        } else {
            downDelay = 400;
        }
        double sinceStart = (double(clock()-startTime)/CLOCKS_PER_SEC);
        if (sinceStart >= downDelay/1000) {
            startTime = clock();
            board.moveDown();
            change = true;
            if (board.updateBoard()) {
                board.newPiece();
            }
        }
        if (change)
            board.printBoard();
    }
}
