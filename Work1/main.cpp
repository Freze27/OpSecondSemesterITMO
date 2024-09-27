#include <iostream>
#include "func.h"

int main() {
    int first, second;
    std::cin >> first >> second;
    int first_new = first;
    int second_new = second;
    complex_number comp_num;
    std::cin >> comp_num.x >> comp_num.y;
    complex_number comp_num_new = comp_num;
    matrix Matrix;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> Matrix.data[i][j];
        }
    }
    matrix Matrix_new = Matrix;
    plus_pointer(&first, &second);
    plus_link(first_new, second_new);
    zn_change_pointer(&first);
    zn_change_link(first_new);
    complex_change_link(comp_num_new);
    complex_change_pointer(&comp_num);
    float c;
    std::cin >> c;
    matrix_link(Matrix_new,c);
    matrix_pointer(&Matrix,&c);
}