#include <iostream>
#include <array>
#include "../include/Shapes.hpp"


std::array<std::array<int, 2>, 4> listToArr(int list[4][2]);

Shapes::Shapes(int shapeNumber) : shapeType(shapeNumber) {};

std::array<std::array<int, 2>, 4> Shapes::getO(int rotation) {
    int nums[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    return listToArr(nums);
}

std::array<std::array<int, 2>, 4> Shapes::getI(int rotation) {
    int nums[2][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{-1, 0}, {0, 0}, {1, 0}, {2, 0}}
    };
    return listToArr(nums[rotation%2]);
}

std::array<std::array<int, 2>, 4> Shapes::getS(int rotation) {
    int nums[2][4][2] = {
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{1, 0}, {0, 1}, {2, 0}, {1, 1}}
    };
    return listToArr(nums[rotation%2]);
}

std::array<std::array<int, 2>, 4> Shapes::getZ(int rotation) {
    int nums[2][4][2] = {
        {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
        {{0, 0}, {1, 1}, {2, 1}, {1, 0}}
    };
    return listToArr(nums[rotation%2]);
}

std::array<std::array<int, 2>, 4> Shapes::getL(int rotation) {
    int nums[4][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{0, 1}, {-1, 1}, {1, 1}, {-1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
        {{0, 1}, {-1, 1}, {1, 1}, {1, 0}},
    };
    std::array<std::array<int, 2>, 4> test = listToArr(nums[rotation]);
    return test;
}
std::array<std::array<int, 2>, 4> Shapes::getJ(int rotation) {
    int nums[4][4][2] = {
        {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}}
    };
    return listToArr(nums[rotation]);
}

std::array<std::array<int, 2>, 4> Shapes::getT(int rotation) {
    int nums[4][4][2] = {
        {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
        {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    };
return listToArr(nums[rotation]);
}

std::array<std::array<int, 2>, 4> Shapes::getShape(int rotation) {
    switch(shapeType) {
        case 0:
            return getO(rotation);
        case 1:
            return getI(rotation);
        case 2:
            return getS(rotation);
        case 3:
            return getZ(rotation);
        case 4:
            return getL(rotation);
        case 5:
            return getJ(rotation);
        case 6:
            return getT(rotation);
        default:
            return getO(rotation);
    };
}

std::array<std::array<int, 2>, 4> listToArr(int list1[4][2]) {
    std::array<std::array<int, 2>, 4> arr;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            arr[i][j] = list1[i][j];
        }
    }
    return arr;
}
