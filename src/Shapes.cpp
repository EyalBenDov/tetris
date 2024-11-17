#include <iostream>

class Shapes {
    public:
        int shapeType;

        Shapes(int shapeNumber) {
            shapeType = shapeNumber;
        };

        int** getO(int rotation) {
            int nums[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            return listToPtr(nums);
        }

        int** getI(int rotation) {
            int nums[2][4][2] = {
                {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                {{-1, 0}, {0, 0}, {1, 0}, {2, 0}}
            };
            return listToPtr(nums[rotation%2]);
        }

        int** getS(int rotation) {
            int nums[2][4][2] = {
                {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
                {{1, 0}, {0, 1}, {2, 0}, {1, 1}}
            };
            return listToPtr(nums[rotation%2]);
        }

        int** getZ(int rotation) {
            int nums[2][4][2] = {
                {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
                {{0, 0}, {1, 1}, {2, 1}, {1, 0}}
            };
            return listToPtr(nums[rotation%2]);
        }

        int** getL(int rotation) {
            int nums[4][4][2] = {
                {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
                {{0, 1}, {-1, 1}, {1, 1}, {-1, 2}},
                {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
                {{0, 1}, {-1, 1}, {1, 1}, {1, 0}},
            };
            return listToPtr(nums[rotation]);
        }
        int** getJ(int rotation) {
            int nums[4][4][2] = {
                {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
                {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
                {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
                {{0, 0}, {1, 0}, {2, 0}, {2, 1}}
            };
            return listToPtr(nums[rotation]);
        }

        int** getT(int rotation) {
            int nums[4][4][2] = {
                {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
                {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
                {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
                {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
            };
        return listToPtr(nums[rotation]);
        }
        
        int** getShape(int rotation) {
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

    private:
        int** listToPtr(int list[4][2]) {
            int** ptr = (int**) malloc(4*2*sizeof(int));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    ptr[i][j] = list[i][j];
                }
            }
            return ptr;
        }
};