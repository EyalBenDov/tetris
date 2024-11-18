#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <CoreGraphics/CoreGraphics.h>
#include "../include/Board.hpp"

bool keyPressed(CGKeyCode key) {
    return CGEventSourceKeyState(kCGEventSourceStateHIDSystemState, key);
}

int main() {
    CGRequestListenEventAccess();
    clock_t startTime = clock();
    Board board = Board();
    board.initializeBoard();
    board.newPiece();
    bool up_held = false;
    bool right_held = false;
    bool left_held = false;
    double downDelay = 400;  
    board.printBoard();
    while (true) {
        bool change = false;
        if (keyPressed(0x0C)) break;
        if (keyPressed(0x7E)) {
            if (up_held == false) board.rotatePiece();
            up_held = true;
            change = true;
        } else {
            up_held = false;
        }
        if (keyPressed(0x7C)) {
            if (right_held == false) {
                board.movePiece(1);
                right_held = true;
                change = true;
            }
        } else {
            right_held = false;
        }
        if (keyPressed(0x7B)) {
            if (left_held == false) {
                board.movePiece(-1);
                left_held = true;
                change = true;
            }
        } else {
            left_held = false;
        }
        if (keyPressed(0x7D)) {
            downDelay = 200;
        } else {
            downDelay = 400;
        }
        double sinceStart = (double(clock()-startTime)/CLOCKS_PER_SEC);
        if (sinceStart >= downDelay/1000) {
            startTime = clock();
            change = true;
            if (board.isOver()) {
                    break;
            }
            if (board.updateBoard()) {
                board.newPiece();
            }
            board.moveDown();
        }
        if (change)
            board.printBoard();
    }
}
