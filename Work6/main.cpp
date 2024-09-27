#include <iostream>
#include <vector>
#include "Point.h"


bool predicate_i(int value) {
    return value % 2 == 0;
}

bool predicate_p(Point value) {
    return (value.p_x() + value.p_y()) >= 0;
}


template<typename Iterator, typename Predicate>
bool all_of(Iterator first, Iterator last, Predicate predicate) {
    while (first != last) {
        if (!predicate(*first)) {
            return false;
        }
        first++;
    }
    return true;
}

template<typename iterator, typename Predicate>
bool is_partitioned(iterator first, iterator last, Predicate predicate) {
    bool partitionFound = false;
    bool f = predicate(*first);
    while (first != last) {
        if (predicate(*first) != f) {
            partitionFound = true;
        }
        else{
            if(partitionFound){
                return false;
            }
        }
        first++;
    }
    return partitionFound;
}

template<typename Iterator, typename T>
Iterator find_backward(Iterator first, Iterator last, T value) {
    while (last != first) {
        if (*last == value) {
            return last;
        }
        last--;
    }
    return first;
}

int main() {
    std::vector<int> array_int(4);
    for (int i = 0; i < array_int.size(); i++) {
        array_int[i] = i + 1;
    }
    if (all_of(array_int.begin(), array_int.end(), predicate_i)) {
        std::cout << "All elements satisfy the predicate " << '\n';
    } else {
        std::cout << "Not all elements satisfy the predicate" << '\n';
    }
    if (is_partitioned(array_int.begin(), array_int.end(), predicate_i)) {
        std::cout << "There is a separator element" << '\n';
    } else {
        std::cout << "There is not a separator element" << '\n';
    }
    std::cout << *find_backward(array_int.begin(), array_int.end(), 2) << '\n';
    std::vector<Point> array_point;
    array_point.push_back({5, 6});
    array_point.push_back({-5, 6});
    array_point.push_back({-6, 1});
    array_point.push_back({100, 2});
    Point p = {-5, 6};
    if (all_of(array_point.begin(), array_point.end(), predicate_p)) {
        std::cout << "All elements satisfy the predicate " << '\n';
    } else {
        std::cout << "Not all elements satisfy the predicate" << '\n';
    }
    if (is_partitioned(array_point.begin(), array_point.end(), predicate_p)) {
        std::cout << "There is a separator element" << '\n';
    } else {
        std::cout << "There is not a separator element" << '\n';
    }
    Point result = *find_backward(array_point.begin(), array_point.end(), p);
    std::cout << result.p_x() << ' ' << result.p_y() << '\n';
}
