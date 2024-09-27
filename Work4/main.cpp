#include <iostream>
#include <vector>
#include <algorithm>
#include "segment.h"
#include "trapezoid.h"

bool compare(Object *x, Object *y) {
    return (x->mass() < y->mass());
}

int main() {
    std::vector<Object *> array_objects;
    int command;
    int stop = 0;
    while (stop == 0) {
        std::cout << "1. Add figure " << '\n';
        std::cout << "2. Show all figures" << '\n';
        std::cout << "3. Sum all perimeters" << '\n';
        std::cout << "4. Sum all areas" << '\n';
        std::cout << "5. System mass center" << '\n';
        std::cout << "6. Show figures memory" << '\n';
        std::cout << "7. Sort figure" << '\n';
        std::cout << "8. Exit" << '\n';
        std::cout << "Enter command: ";
        std::cin >> command;
        std::cout << '\n';
        if (command == 8) {
            stop = 1;
            break;
        } else if (command == 1) {
            std::cout << "1. Segment" << '\n';
            std::cout << "2. Hexagon" << '\n';
            std::cout << "Enter command: ";
            std::cin >> command;
            std::cout << '\n';
            if (command == 1) {
                array_objects.push_back(new Segment());
                break;
            } else if (command == 2) {
                array_objects.push_back(new Trapezoid());
                break;
            }
        } else if (command == 2) {
            for (int i = 0; i < array_objects.size(); i++) {
                array_objects[i]->draw();
            }
            break;
        } else if (command == 3) {
            double sum = 0;
            for (int i = 0; i < array_objects.size(); i++) {
                sum += array_objects[i]->perimeter();
            }
            std::cout << "Perimeter sum: " << sum << '\n';
            std::cout << '\n';
            break;
        } else if (command == 4) {
            double sum = 0;
            for (int i = 0; i < array_objects.size(); i++) {
                sum += array_objects[i]->size();
            }
            std::cout << "Area sum: " << sum << '\n';
            std::cout << '\n';
            break;
        } else if (command == 5) {
            double sum = 0;
            double x = 0;
            double y = 0;
            for (int i = 0; i < array_objects.size(); i++) {
                x += array_objects[i]->position().x * array_objects[i]->mass();
                y += array_objects[i]->position().y * array_objects[i]->mass();
                sum += array_objects[i]->mass();
            }
            CVector2D center;
            center.x = x / sum;
            center.y = y / sum;
            std::cout << "Center weight coords: " << center.x << ' ' << center.y << '\n';
            std::cout << '\n';
            break;

        } else if (command == 6) {
            std::cout << "Figures memory: ";
            for (int i = 0; i < array_objects.size(); i++) {
                std::cout << array_objects[i]->size() << " ";
            }
            std::cout << '\n';
            break;
        } else if (command == 7) {
            std::cout << "Sorted ..." << '\n';
            std::sort(array_objects.begin(), array_objects.end(), compare);
            std::cout << "Figures mass: ";
            for (int i = 0; i < array_objects.size(); i++) {
                std::cout << array_objects[i]->mass() << " ";
            }
            std::cout << '\n';
            break;
        }
    }
}
