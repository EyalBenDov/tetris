#include <iostream>

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

    private:
        int** listToPtr(int list[4][2]);
};