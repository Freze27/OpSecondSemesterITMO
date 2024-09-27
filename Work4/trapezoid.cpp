#include "interface.h"
#include "trapezoid.h"
#include <math.h>

Trapezoid::Trapezoid() {
    this->Trapezoid::initFromDialog();
}


double Trapezoid::square() {
    return (pow(side, 2) - pow(basis_large - basis_small, 2)) * ((basis_small + basis_large) / 2);
}

double Trapezoid::perimeter() {
    return side * 2 + basis_large + basis_small;
}

double Trapezoid::mass() const {
    return m;
}

CVector2D Trapezoid::position() {
    return center;
}

bool Trapezoid::operator==(const IPhysObject &obj) const {
    return mass() == obj.mass();
}

bool Trapezoid::operator<(const IPhysObject &obj) const {
    return mass() < obj.mass();
}

void Trapezoid::draw() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Position: " << center.x << ' ' << center.y << '\n';
    std::cout << "Weight: " << m << '\n';
    std::cout << "Side: " << side << '\n';
    std::cout << "Enter Large Basis: " << basis_large << '\n';
    std::cout << "Enter Small Basis: " << basis_small << '\n';
    std::cout << "Size: " << size() << '\n';
    std::cout << '\n';
}

void Trapezoid::initFromDialog() {
    std::cout << "Enter center coords: " << '\n';
    std::cin >> center.x >> center.y;
    std::cout << "Enter weight: " << '\n';
    std::cin >> m;
    std::cout << "Enter side: " << '\n';
    std::cin >> side;
    std::cout << "Enter Large Basis: " << '\n';
    std::cin >> basis_large;
    std::cout << "Enter Small Basis: " << '\n';
    std::cin >> basis_small;
}

const char *Trapezoid::classname() {
    return name;
};

unsigned int Trapezoid::size() {
    return sizeof(*this);
}