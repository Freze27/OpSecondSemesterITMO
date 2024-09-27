#ifndef LAB5_ARRAY_H
#define LAB5_ARRAY_H
#include "error.h"

template<int Size, class T>
class Array {
private:
    T *mass;
public:
    Array();
    void push_in(int index, T value);
    void print(int index);
};

#endif
