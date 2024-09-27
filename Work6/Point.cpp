#include "Point.h"

double Point::p_x() {
    return x;
}

double Point::p_y() {
    return y;
}

Point::Point(double x_, double y_) : x(x_), y(y_) {}

Point::Point() : x(0), y(0) {}

bool Point::operator==(Point b) {
    return (x==b.p_x() and y==b.p_y());
}

