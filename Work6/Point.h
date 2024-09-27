#ifndef LAB6_POINT_H
#define LAB6_POINT_H
class Point {
private:
    double x;
    double y;

public:
    double p_x();
    double p_y();
    Point(double x_, double y_);
    Point();
    bool operator==(Point b);
};
#endif
