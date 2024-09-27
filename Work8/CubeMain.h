#ifndef LAB8_CUBEMAIN_H
#define LAB8_CUBEMAIN_H

#include <array>
#include <string>
#include <random>
#include <iostream>
#include <fstream>

class CubeR {
public:
    enum Color {
        Yellow,
        Blue,
        Red,
        Green,
        Orange,
        White
    };
    enum Ground {
        U,
        L,
        F,
        R,
        B,
        D
    };
    enum Rotation {
        Clockwise = 1,
        Double,
        Anticlockwise
    };

    CubeR();
    CubeR(std::string &string);
    void Initialize();
    std::string Scramble();
    void Rotate(std::string &input);
    std::string Solve();
    char ColorToChar(Color color);
    char get(int index);

private:
    std::array<Color, 54> cube;
    void RotateWithOutput(const std::string &input, std::string &output);
    void RotateGround(Ground Ground, Rotation rotation);
    bool Solved();
    bool SolvedCross(Ground Ground, Color color);
    bool SolvedAdjacentToWhiteCross();
    bool SolvedWhiteEdges();
    bool SolvedSecondLayer();
    bool SolvedGround(Ground Ground);
};

std::ostream& operator<<(std::ostream &os, CubeR &cube);
void Read(std::string &filename, CubeR &cube);
void Write(std::string &filename, CubeR &cube);

#endif
