#include <iostream>
#include "integerSet.h"

IntegerSet::IntegerSet() : elements(nullptr), size(0), max_size(0) {}

IntegerSet::IntegerSet(int max) : size(0), max_size(max) {
    elements = new int[max_size];
}

IntegerSet::IntegerSet(IntegerSet &other) : size(other.size), max_size(other.max_size) {
    elements = new int[max_size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

IntegerSet::~IntegerSet() {
    delete[] elements;
}

bool IntegerSet::contains(int element) {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

void IntegerSet::insert(int element) {
    if (size < max_size) {
        elements[size] = element;
        size++;
    }
}

void IntegerSet::remove(int element) {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            for (int j = i; j < size - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            size--;
            break;
        }
    }
}

IntegerSet IntegerSet::OrSet(IntegerSet &other) {
    IntegerSet result(max_size + other.max_size);
    for (int i = 0; i < size; ++i) {
        result.insert(elements[i]);
    }
    for (int i = 0; i < other.size; ++i) {
        result.insert(other.elements[i]);
    }
    return result;
}

IntegerSet IntegerSet::AndSet(IntegerSet &other) {
    IntegerSet result(max_size + other.max_size);
    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.insert(elements[i]);
        }
    }
    return result;
}

void IntegerSet::addAll(IntegerSet &other) {
    for (int i = 0; i < other.size; ++i) {
        insert(other.elements[i]);
    }
}

void IntegerSet::removeAll(IntegerSet &other) {
    IntegerSet result;
    for (int i = 0; i < size; ++i) {
        if (!other.contains(elements[i])) {
            result.insert(elements[i]);
        }
    }
    delete[] elements;
    elements = new int[max_size];
    size = 0;
    for (int i = 0; i < result.size; ++i) {
        insert(result.elements[i]);
    }
}

void IntegerSet::print() {
    std::cout << "IntegerSet: ";
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << ' ';
    }
    std::cout << '\n';
}