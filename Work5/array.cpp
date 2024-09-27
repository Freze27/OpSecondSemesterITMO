#include "array.h"
#include <iostream>

template<int Size, class T>
Array<Size, T>::Array() {
    mass = new T[Size];
}

template<int Size, class T>
void Array<Size, T>::push_in(int index, T value) {
    try{
        if (index < 0 or index >= Size) {
            throw Error("Element cant be added", 000);
        } else {
            mass[index] = value;
            std::cout << "Element added" << '\n';
        }
    }
    catch(Error &err) {
        std::cout << "Message: " << err.letter() << '\n';
        std::cout << "Code: " << err.type() << '\n';
    }
}

template<int Size, class T>
void Array<Size, T>::print(int index) {
    try{
        if (index < 0 or index >= Size) {
            throw Error("Element not found", 001);
        } else {
            std::cout << "Element in " << index << ' ' << mass[index] << '\n';
        }
    }
    catch(Error &err) {
        std::cout << "Message: " << err.letter() << '\n';
        std::cout << "Code: " << err.type() << '\n';
    }
}
