#include <iostream>
#include "func.h"

int main() {
    queue q;
    Complex a(5, 6);
    Complex b(10, 100);
    q << 4;
    q.operator<<(4);
    q << 5;
    q.operator<<(5);
    q >> 5;
    q.operator>>(5);
    q >> 6;
    q.operator>>(6);
    Complex c = a + b;
    c.print();
    c = a.operator+(b);
    c.print();
    c = a * b;
    c.print();
    c = a.operator*(b);
    c.print();
    c = a * 5.1;
    c.print();
    c = a.operator*(5.1);
    c.print();
    double r = double(a);
    std::cout << r << '\n';
    r = a.operator double();
    std::cout << r << '\n';
}
