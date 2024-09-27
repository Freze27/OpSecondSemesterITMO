#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
class RingBuffer {
private:
    T *b;
    int size;
    int capacity;
public:
class Iterator {
    private:
        T *pointer;
    public:
        Iterator(T *p) : pointer(p) {}

        T &operator*() const {
            return *pointer;
        }

        ptrdiff_t operator-(T *start) const {
            return (pointer - start);
        }

        ptrdiff_t operator-(Iterator start) const {
            return (pointer - start.pointer);
        }

        Iterator operator-(int n) const {
            return Iterator(pointer - n);
        }

        Iterator operator--() const {
            return Iterator(pointer-1);
        }

        Iterator operator++() const {
            return Iterator(pointer+1);
        }

        Iterator operator+(int n) {
            return Iterator(pointer + n);
        }

        bool operator ==(const Iterator& value) const {
            return pointer == value.pointer;
        }

        bool operator !=(const Iterator& value) const {
            return pointer != value.pointer;
        }

        bool operator <(const Iterator& value) const {
            return pointer < value.pointer;
        }
        bool operator >(const Iterator& value) const {
            return pointer > value.pointer;
        }

        bool operator <=(const Iterator& value) const {
            return pointer <= value.pointer;
        }
        bool operator >=(const Iterator& value) const {
            return pointer >= value.pointer;
        }
    };

    RingBuffer(int capacity) : capacity(capacity), size(0), b(new T[capacity]) {}

    ~RingBuffer() {
        delete[] b;
    }

    bool empty() {
        return size == 0;
    }

    void push_front(T value) {
        if (size < capacity) {
            for (int i = size; i >= 1; i++) {
                b[i] = b[i - 1];
            }
            size++;
            b[0] = value;
        } else {
            std::cout << "Buffer is full." << '\n';
        }
    }

    void push_back(T value) {
        if (size < capacity) {
            b[size] = value;
            size++;
        } else {
            for (int i = 1; i < size; i++) {
                b[i - 1] = b[i];
            }
            b[size - 1] = value;
        }
    }

    void pop_back() {
        if (!empty()) {
            size--;
        }
    }

    void pop_front() {
        if (!empty()) {
            for (int i = 1; i < size; i++) {
                b[i - 1] = b[i];
            }
            size--;
        }
    }

    Iterator begin() {
        return Iterator(b);
    }

    Iterator end() {
        return Iterator(b + size - 1);
    }

    void change_capacity(int NewCapacity) {
        T *NewB = new T[NewCapacity];
        int count = std::min(size, NewCapacity);
        for (int i = 0; i < count; i++) {
            NewB[i] = b[i];
        }
        delete[] b;
        b = NewB;
        size = count;
        capacity = NewCapacity;
    }

    void insert(Iterator p, T value) {
        b[(p - b) % size] = value;
    }

    void pop(Iterator p) {
        for (int i = ((p - b) % size); i < size - 1; i++) {
            b[i] = b[i + 1];
        }
    }

    T operator[](int index) {
        return (b[index % size]);
    }

    T front_element() {
        return *b;
    }

    T back_element() {
        return *(b + size - 1);
    }

    void print() {
        if (!empty()) {
            for (int i = 0; i < size; i++) {
                std::cout << b[i] << ' ';
            }
            std::cout << '\n';
        } else {
            std::cout << "Buffer is Empty." << '\n';
        }
    }
};

int main() {
    RingBuffer<int> Buffer(5);
    Buffer.push_back(5);
    Buffer.push_back(4);
    Buffer.push_back(3);
    Buffer.push_back(52);
    Buffer.push_back(53);
    Buffer.push_back(55);
    Buffer.push_back(56);
    Buffer.change_capacity(8);
    Buffer.push_back(57);
    Buffer.print();
    Buffer.pop_front();
    Buffer.print();
    Buffer.pop_back();
    Buffer.print();
    std::cout << Buffer.front_element() << '\n';
    std::cout << Buffer.back_element() << '\n';
    std::cout << Buffer[1] << '\n';
    std::cout << Buffer[7] << '\n';
    RingBuffer<int>::Iterator p(Buffer.begin() + 5);
    Buffer.insert(p,-100);
    Buffer.print();
    Buffer.pop(p);
    Buffer.print();
}
