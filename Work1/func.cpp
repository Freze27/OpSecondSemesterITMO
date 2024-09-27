#include "func.h"
#include <iostream>

void plus_pointer(int *a, int *b) {
    *a += *b;
    std::cout << "Procedure a + b " << *a << '\n';
};

void zn_change_pointer(int *a) {
    *a *= (-1);
    std::cout << "Procedure change sign " << *a << '\n';
};

void complex_change_pointer(complex_number *a) {
    (*a).y *= (-1);
    std::cout << "Procedure conjugate complex number " << (*a).x;
    if ((*a).y > 0) {
        std::cout << '+' << (*a).y << '\n';
    }
    else{
        std::cout << (*a).y << '\n';
    }
};

void matrix_pointer(matrix *matrix, float *c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            (*matrix).data[i][j] *= (*c);
        }
    }
    std::cout << "Procedure matrix multiplication" << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << (*matrix).data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void plus_link(int &a, int &b) {
    a += b;
    std::cout << "Procedure a + b " << a << '\n';
};

void zn_change_link(int &a) {
    a *= (-1);
    std::cout << "Procedure change sign " << a << '\n';
};

void complex_change_link(struct complex_number &a) {
    a.y *= (-1);
    std::cout << "Procedure conjugate complex number " << a.x;
    if (a.y > 0) {
        std::cout << '+' << a.y << '\n';
    }
    else{
        std::cout << a.y << '\n';
    }
};

void matrix_link(matrix &matrix, float &c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix.data[i][j] *= c;
        }
    }
    std::cout << "Procedure matrix multiplication" << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix.data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
