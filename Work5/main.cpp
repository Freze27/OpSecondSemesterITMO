#include <iostream>
#include "array.h"
#include "array.cpp"

template<typename T>
void swap(T &a, T &b) {
    T s;
    s = a;
    a = b;
    b = s;
}

int main() {
    int a = 5;
    int b = 10;
    std::cout << a << ' ' << b << '\n';
    swap(a, b);
    std::cout << a << ' ' << b << '\n';
    Array<10, int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_in(i, i);
    }
    for (int i = 0; i < 10; i++) {
        arr.print(i);
    }
    arr.print(10);
    arr.push_in(10,10);
}
