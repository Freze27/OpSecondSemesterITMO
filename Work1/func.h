#ifndef INC_1_LAB_C___FUNC_H
#define INC_1_LAB_C___FUNC_H
struct complex_number {
    int x;
    int y;
};
struct matrix {
    float data[3][3];
};
void plus_pointer(int *a, int *b);
void zn_change_pointer(int *a);
void complex_change_pointer(complex_number *a);
void matrix_pointer(matrix *matrix, float *c);
void plus_link(int &a, int &b);
void zn_change_link(int &a);
void complex_change_link(struct complex_number &a);
void matrix_link(matrix &matrix, float &c);
#endif
