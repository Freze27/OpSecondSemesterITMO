#include "segment.h"
#include <math.h>

Segment::Segment()
{
    this->Segment::initFromDialog();
}

double Segment::square() {
    return 0;
}

double Segment::perimeter() {
    return len;
}

double Segment::mass() const {
    return m;
}

CVector2D Segment::position() {
    double x = (start.x + end.x) / 2.0;
    double y = (start.y + end.y) / 2.0;
    CVector2D middle;
    middle.x = x;
    middle.y = y;
    return middle;
}

bool Segment::operator==(const IPhysObject &obj) const {
    return mass() == obj.mass();
}

bool Segment::operator<(const IPhysObject &obj) const {
    return mass() < obj.mass();
}

void Segment::draw() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Mass: " << m << '\n';
    CVector2D middle = position();
    std::cout << "Position: " << middle.x << ' ' << middle.y << '\n';
    std::cout << "Perimeter: " << len << '\n';
    std::cout << "Size: " << size() << '\n';
    std::cout << '\n';
}

void Segment::initFromDialog() {
    std::cout << "Enter start point (x y): " << '\n';
    std::cin >> start.x >> start.y;
    std::cout << "Enter end point (x y): " << '\n';
    std::cin >> end.x >> end.y;
    std::cout << "Enter mass of segment: " << '\n';
    std::cin >> m;
    len = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}

const char* Segment::classname() {
    return name;
}

unsigned int Segment::size() {
    return sizeof(*this);
}