#ifndef INC_2_LAB_C___INTEGERSET_H
#define INC_2_LAB_C___INTEGERSET_H

#include <iostream>

class IntegerSet {
private:
    int *elements;
    int size;
    int max_size;

public:
    IntegerSet();
    IntegerSet(int max);
    IntegerSet(IntegerSet &other);
    ~IntegerSet();
    bool contains(int element);
    void insert(int element);
    void remove(int element);
    IntegerSet OrSet(IntegerSet &other);
    IntegerSet AndSet(IntegerSet &other);
    void addAll(IntegerSet &other);
    void removeAll(IntegerSet &other);
    void print();
};


#endif