#include <iostream>
#ifndef SHAPES_H
#define SHAPES_H

class Shapes {
    public:
        Shapes(int shapeNumber) {};
        int shapeType;
        int** getO(int rotation);
        int** getI(int rotation);
        int** getS(int rotation);
        int** getZ(int rotation);
        int** getL(int rotation);
        int** getJ(int rotation);
        int** getT(int rotation);
        int** getShape(int rotation);
};
#endif