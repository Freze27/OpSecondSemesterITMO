#include <iostream>
#include "func.h"
#include <math.h>

Node::Node(int data_) : data(data_), next(nullptr) {}

void Complex::print() {
    std::cout << x << '\n';
    std::cout << y << '\n';
}

Complex::Complex(double x_, double y_) : x(x_), y(y_) {}

Complex Complex::operator*(double k) {
    return Complex(x * k, y * k);
}

Complex Complex::operator+(Complex &other) {
    return Complex(x + other.x, y + other.y);
}

Complex Complex::operator*(Complex &other) {
    double new_x = (x * other.x) - (y * other.y);
    double new_y = (x * other.y) + (y * other.x);
    return Complex(new_x, new_y);
}

Complex::operator double() {
    return sqrt(x * x + y * y);
}

queue::queue() : front(nullptr), rear(nullptr), size(0) {}

void queue::add(int value) {
    Node *newNode = new Node(value);
    if (rear == nullptr) {
        size++;
        front = newNode;
        rear = newNode;
    } else {
        if (size <= 100) {
            size++;
            rear->next = newNode;
            rear = newNode;
        }
    }
}

void queue::del() {
    if (front != nullptr) {
        Node *temp = front;
        front = front->next;
        size--;
        delete temp;
    }
}

void queue::operator<<(int n) {
    add(n);
}

void queue::operator>>(int n) {
    Node *start = front;
    Node *prev = nullptr;
    int fl = 0;
    while (start != nullptr) {
        if (start->data == n) {
            Node *tmp = start;
            if (start->next != nullptr) {
                prev->next = start->next->next;
                start->next = nullptr;
            } else {
                prev->next = nullptr;
            }
            std::cout << start->data << '\n';
            fl = 1;
            delete tmp;
            break;
        }
        prev = start;
        start = start->next;
    }

    if (fl == 0) {
        std::cout << "Element not in queue." << '\n';
    }
}



