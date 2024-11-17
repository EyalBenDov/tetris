#include <iostream>

class Shapes {
    public:
        int shape_type;
        int** get_O(int rotation) {
            int nums[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            return list_to_ptr(nums);
        }

        int** get_I(int rotation) {
            int nums[2][4][2] = {
                {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                {{-1, 0}, {0, 0}, {1, 0}, {2, 0}}
            };
            return list_to_ptr(nums[rotation%2]);
        }

        int** get_S(int rotation) {
            int nums[2][4][2] = {
                {{0, 0}, {0, -1}, {1, -1}, {1, -2}},
                {{1, 0}, {0, -1}, {2, 0}, {1, -1}}
            };
            return list_to_ptr(nums[rotation%2]);
        }

        int** get_Z(int rotation) {
            int nums[2][4][2] = {
                {{1, 0}, {1, -1}, {0, -1}, {0, -2}},
                {{0, 0}, {1, -1}, {2, -1}, {1, 0}}
            };
            return list_to_ptr(nums[rotation%2]);
        }

        int** get_L(int rotation) {
            int nums[4][4][2] = {
                {{0, 0}, {0, -1}, {0, -2}, {1, -2}},
                {{0, -1}, {-1, -1}, {1, -1}, {-1, -2}},
                {{0, 0}, {0, -1}, {0, -2}, {-1, 0}},
                {{0, -1}, {-1, -1}, {1, -1}, {1, 0}},
            };
            return list_to_ptr(nums[rotation]);
        }
        int** get_J(int rotation) {
            int nums[4][4][2] = {
                {{1, 0}, {1, -1}, {1, -2}, {0, -2}},
                {{0, 0}, {0, -1}, {1, -1}, {2, -1}},
                {{0, 0}, {1, 0}, {0, -1}, {0, -2}},
                {{0, 0}, {1, 0}, {2, 0}, {2, -1}}
            };
            return list_to_ptr(nums[rotation]);
        }

        int** get_T(int rotation) {
            int nums[4][4][2] = {
                {{1, 0}, {0, -1}, {1, -1}, {2, -1}},
                {{1, 0}, {1, -1}, {1, -2}, {2, -1}},
                {{0, -1}, {1, -1}, {2, -1}, {1, -2}},
                {{1, 0}, {1, -1}, {1, -2}, {0, -1}},
            };
        return list_to_ptr(nums[rotation]);
        }

        int get_width(int shape, int rotation);
        int get_height(int shape, int rotation);
        
        int** get_shape(int rotation);

    private:
        int** list_to_ptr(int list[4][2]) {
            int** ptr = (int**) malloc(4*2*sizeof(int));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    ptr[i][j] = list[i][j];
                }
            }
            return ptr;
        }
        Shapes(int shape_number) {
            shape_type = shape_number;
        };
};