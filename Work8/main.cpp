#include "CubeMain.h"

int main() {
    CubeR cube;
    int command;
    bool fl = true;
    while (fl) {
        std::cout << "1 - Scramble." << '\n';
        std::cout << "2 - Solve." << '\n';
        std::cout << "3 - Now state." << '\n';
        std::cout << "4 - Read from File." << '\n';
        std::cout << "5 - Save in File." << '\n';
        std::cout << "6 - Rotates." << '\n';
        std::cout << "0 - Exit." << '\n';
        std::cin >> command;
        if (command == 1) {
            std::cout << "Scramble: " << cube.Scramble() << '\n';
            std::cout << "Now state: " << '\n';
            std::cout << cube << '\n';
        } else if (command == 2) {
            std::cout << "Solve moves: " << '\n';
            std::cout << cube.Solve() << '\n';
        } else if (command == 3) {
            std::cout << "Now State: " << '\n';
            std::cout << cube;
        } else if (command == 4) {
            std::cout << "Enter file name: " << '\n';
            std::string file;
            Read(file, cube);
        } else if (command == 5) {
            std::cout << "Enter file name: " << '\n';
            std::string file;
            Write(file, cube);

        }
        else if(command == 6){
            std::string rotates;
            std::cout << "Enter moves: " << '\n';
            std::cin >> rotates;
            cube.Rotate(rotates);
            std::cout << "Now state: " << '\n';
            std::cout << cube << '\n';
        }
        else if (command == 0) {
            fl = false;
        }
    }
}
