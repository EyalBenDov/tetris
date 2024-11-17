#include <iostream>

class Shapes {
    public:
        int shape_type;
        int** get_O(int rotation);
        int** get_I(int rotation);
        int** get_S(int rotation);
        int** get_Z(int rotation);
        int** get_L(int rotation);
        int** get_J(int rotation);
        int** get_T(int rotation);

        int get_width(int shape, int rotation);
        int get_height(int shape, int rotation);

        int** get_shape(int rotation);

    private:
        int** list_to_ptr();
        Shapes(int shape_number) {};
};