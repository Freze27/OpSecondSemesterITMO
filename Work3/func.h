#ifndef LAB3_FUNC_H
#define LAB3_FUNC_H

class Complex {
private:
    double x;
    double y;

public:
    void print();
    Complex(double real_, double imaginary_);
    Complex operator*(double scalar);
    Complex operator+(Complex &other);
    Complex operator*(Complex &other);
    operator double();
};

class Node {
public:
    int data;
    Node *next;
    Node(int data_);
};

class queue {
private:
    Node *front;
    Node *rear;
    int size;
public:
    queue();
    void add(int value);
    void del();
    void operator<<(int n);
    void operator>>(int n);
};

#endif
