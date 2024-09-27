#include <iostream>
#include "integerSet.h"

int main() {
    int max_size, current_size,new_element;
    std::cin >> max_size >> current_size;
    IntegerSet Set(max_size);
    for (int i = 0; i < current_size; i++) {
        std::cin >> new_element;
        Set.insert(new_element);
    }
    Set.print();
    std::cin >> new_element;
    if(Set.contains(new_element)){
        std::cout << "Yes" << '\n';
    }
    else{
        std::cout << "No" << '\n';
    }
    std::cin >> new_element;
    Set.remove(new_element);
    Set.print();
    std::cin >> max_size >> current_size;
    IntegerSet NewSet(max_size);
    for (int i = 0; i < current_size; i++) {
        std::cin >> new_element;
        NewSet.insert(new_element);
    }
    IntegerSet ResultAndSet(Set.AndSet(NewSet));
    ResultAndSet.print();
    IntegerSet ResultOrSet(Set.OrSet(NewSet));
    ResultOrSet.print();

}
