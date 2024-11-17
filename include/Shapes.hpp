#include <iostream>
#include <array>
#ifndef SHAPES_H
#define SHAPES_H

class Shapes {
    public:
        Shapes(int shapeNumber);
        int shapeType;
        std::array<std::array<int, 2>, 4> getO(int rotation);
        std::array<std::array<int, 2>, 4> getI(int rotation);
        std::array<std::array<int, 2>, 4> getS(int rotation);
        std::array<std::array<int, 2>, 4> getZ(int rotation);
        std::array<std::array<int, 2>, 4> getL(int rotation);
        std::array<std::array<int, 2>, 4> getJ(int rotation);
        std::array<std::array<int, 2>, 4> getT(int rotation);
        std::array<std::array<int, 2>, 4> getShape(int rotation);
};
#endif