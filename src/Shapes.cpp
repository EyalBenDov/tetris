#include <iostream>
#include "../include/Shapes.hpp"


Shapes::Shapes(int shapeNumber) : shapeType(shapeNumber) {};

int** Shapes::getO(int rotation) {
    int nums[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    return listToPtr(nums);
}

int** Shapes::getI(int rotation) {
    int nums[2][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{-1, 0}, {0, 0}, {1, 0}, {2, 0}}
    };
    return listToPtr(nums[rotation%2]);
}

int** Shapes::getS(int rotation) {
    int nums[2][4][2] = {
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{1, 0}, {0, 1}, {2, 0}, {1, 1}}
    };
    return listToPtr(nums[rotation%2]);
}

int** Shapes::getZ(int rotation) {
    int nums[2][4][2] = {
        {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
        {{0, 0}, {1, 1}, {2, 1}, {1, 0}}
    };
    return listToPtr(nums[rotation%2]);
}

int** Shapes::getL(int rotation) {
    int nums[4][4][2] = {
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{0, 1}, {-1, 1}, {1, 1}, {-1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
        {{0, 1}, {-1, 1}, {1, 1}, {1, 0}},
    };
    return listToPtr(nums[rotation]);
}
int** Shapes::getJ(int rotation) {
    int nums[4][4][2] = {
        {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}}
    };
    return listToPtr(nums[rotation]);
}

int** Shapes::getT(int rotation) {
    int nums[4][4][2] = {
        {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
        {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    };
return listToPtr(nums[rotation]);
}

int** Shapes::getShape(int rotation) {
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
// Helper method, returns a pointer to an inputed list
int** listToPtr(int list[4][2]) {
    int** ptr = (int**) malloc(4*2*sizeof(int));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            ptr[i][j] = list[i][j];
        }
    }
    return ptr;
}
