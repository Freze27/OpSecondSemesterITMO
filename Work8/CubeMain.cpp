#include "CubeMain.h"


CubeR::CubeR() {
    Initialize();
}

CubeR::CubeR(std::string &string) {
    for (int i = 0; i < cube.size(); ++i) {
        if (string[i] == 'Y') {
            cube[i] = Color::Yellow;
        } else if (string[i] == 'B') {
            cube[i] = Color::Blue;
        } else if (string[i] == 'R') {
            cube[i] = Color::Red;
        } else if (string[i] == 'G') {
            cube[i] = Color::Green;
        } else if (string[i] == 'O') {
            cube[i] = Color::Orange;
        } else if (string[i] == 'W') {
            cube[i] = Color::White;
        }
    }
}

void CubeR::Initialize() {
    for (int i = 0; i < 9; i++) {
        cube[(U * 9) + i] = Color::Yellow;
        cube[(L * 9) + i] = Color::Blue;
        cube[(F * 9) + i] = Color::Red;
        cube[(R * 9) + i] = Color::Green;
        cube[(B * 9) + i] = Color::Orange;
        cube[(D * 9) + i] = Color::White;
    }
}

bool CubeR::Solved() {
    for (int i = 0; i < 9; i++) {
        if (cube[(U * 9) + i] != Color::Yellow or cube[(L * 9) + i] != Color::Blue or
            cube[(F * 9) + i] != Color::Red or cube[(R * 9) + i] != Color::Green or
            cube[(B * 9) + i] != Color::Orange or cube[(D * 9) + i] != Color::White) {
            return false;
        }
    }
    return true;
}

char CubeR::ColorToChar(Color color) {
    if (color == Color::Yellow) {
        return 'Y';
    } else if (color == Color::Blue) {
        return 'B';
    } else if (color == Color::Red) {
        return 'R';
    } else if (color == Color::Green) {
        return 'G';
    } else if (color == Color::Orange) {
        return 'O';
    } else if (color == Color::White) {
        return 'W';
    }
}

void CubeR::RotateGround(Ground Ground, Rotation rotation) {
    for (int i = 0; i < rotation; ++i) {
        std::array<Color, 54> before_cube = cube;
        std::array<int, 9> turned_pieces_ids = {6, 3, 0, 7, 4, 1, 8, 5, 2};
        for (int j = 0; j < 9; ++j) {
            cube[Ground * 9 + j] = before_cube[Ground * 9 + turned_pieces_ids[j]];
        }
        std::array<int, 12> rotate_clockwise{};
        if (Ground == U) {
            rotate_clockwise =
                    {F * 9 + 2, F * 9 + 1,
                     F * 9 + 0,
                     L * 9 + 2, L * 9 + 1,
                     L * 9 + 0,
                     B * 9 + 2, B * 9 + 1,
                     B * 9 + 0,
                     R * 9 + 2, R * 9 + 1,
                     R * 9 + 0};
        } else if (Ground == L) {
            rotate_clockwise =
                    {F * 9 + 0, F * 9 + 3,
                     F * 9 + 6,
                     D * 9 + 0, D * 9 + 3,
                     D * 9 + 6,
                     B * 9 + 8, B * 9 + 5,
                     B * 9 + 2,
                     U * 9 + 0, U * 9 + 3,
                     U * 9 + 6};
        } else if (Ground == F) {
            rotate_clockwise =
                    {U * 9 + 6, U * 9 + 7,
                     U * 9 + 8,
                     R * 9 + 0, R * 9 + 3,
                     R * 9 + 6,
                     D * 9 + 2, D * 9 + 1,
                     D * 9 + 0,
                     L * 9 + 8, L * 9 + 5,
                     L * 9 + 2};
        } else if (Ground == R) {
            rotate_clockwise =
                    {F * 9 + 8, F * 9 + 5,
                     F * 9 + 2,
                     U * 9 + 8, U * 9 + 5,
                     U * 9 + 2,
                     B * 9 + 0, B * 9 + 3,
                     B * 9 + 6,
                     D * 9 + 8, D * 9 + 5,
                     D * 9 + 2};
        } else if (Ground == B) {
            rotate_clockwise =
                    {R * 9 + 8, R * 9 + 5,
                     R * 9 + 2,
                     U * 9 + 2, U * 9 + 1,
                     U * 9 + 0,
                     L * 9 + 0, L * 9 + 3,
                     L * 9 + 6,
                     D * 9 + 6, D * 9 + 7,
                     D * 9 + 8};
        } else if (Ground == D) {
            rotate_clockwise = {F * 9 + 6, F * 9 + 7,
                                F * 9 + 8,
                                R * 9 + 6, R * 9 + 7,
                                R * 9 + 8,
                                B * 9 + 6, B * 9 + 7,
                                B * 9 + 8,
                                L * 9 + 6, L * 9 + 7,
                                L * 9 + 8};
        }
        for (int j = 0; j < 12; ++j) {
            cube[rotate_clockwise[j]] = before_cube[rotate_clockwise[(j + 9) % 12]];
        }
    }
}

std::ostream &operator<<(std::ostream &os, CubeR &cube) {
    for (int i = 0; i < 3; ++i) {
        os << std::string(6, ' ');
        for (int j = 0; j < 3; ++j) {
            os << cube.get(i * 3 + j) << ' ';
        }
        os << '\n';
    }
    std::array<int, 12> fourth_level = {9, 10, 11, 18, 19, 20, 27, 28, 29, 36, 37, 38};
    std::array<int, 12> fifth_level = {12, 13, 14, 21, 22, 23, 30, 31, 32, 39, 40, 41};
    std::array<int, 12> sixth_level = {15, 16, 17, 24, 25, 26, 33, 34, 35, 42, 43, 44};
    for (int i = 0; i < fourth_level.size(); i++) {
        os << cube.get(fourth_level[i]) << ' ';
    }
    os << '\n';

    for (int i = 0; i < fifth_level.size(); i++) {
        os << cube.get(fifth_level[i]) << ' ';
    }
    os << '\n';

    for (int i = 0; i < sixth_level.size(); i++) {
        os << cube.get(sixth_level[i]) << ' ';
    }
    os << '\n';

    for (int i = 0; i < 3; ++i) {
        os << std::string(6, ' ');
        for (int j = 0; j < 3; ++j) {
            os << cube.get(45 + i * 3 + j) << ' ';
        }
        os << '\n';
    }
    os << '\n';
    return os;
}

std::string CubeR::Scramble() {
    std::string scramble;
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<int> dist(1, 18);
    std::uniform_int_distribution<int> dist_m(13, 25);
    int action;
    int count_moves = dist_m(gen);
    for (int i = 0; i < count_moves; ++i) {
        action = dist(gen);
        if (action == 1) {
            scramble += "R ";
        } else if (action == 2) {
            scramble += "R\' ";
        } else if (action == 3) {
            scramble += "L ";
        } else if (action == 4) {
            scramble += "L\' ";
        } else if (action == 5) {
            scramble += "F ";
        } else if (action == 6) {
            scramble += "F\' ";
        } else if (action == 7) {
            scramble += "U ";
        } else if (action == 8) {
            scramble += "U\' ";
        } else if (action == 9) {
            scramble += "D ";
        } else if (action == 10) {
            scramble += "D\' ";
        } else if (action == 11) {
            scramble += "B ";
        } else if (action == 12) {
            scramble += "B\' ";
        } else if (action == 13) {
            scramble += "R2 ";
        } else if (action == 14) {
            scramble += "L2 ";
        } else if (action == 15) {
            scramble += "F2 ";
        } else if (action == 16) {
            scramble += "U2 ";
        } else if (action == 17) {
            scramble += "D2 ";
        } else if (action == 18) {
            scramble += "B2 ";
        }
    }
    Rotate(scramble);
    return scramble;
}

void CubeR::Rotate(std::string &input) {
    int i = 0;
    while (i < input.length()) {
        Ground rotation_Ground;
        Rotation rotation_type = Clockwise;
        if (input[i] == 'U') {
            rotation_Ground = U;
        } else if (input[i] == 'L') {
            rotation_Ground = L;
        } else if (input[i] == 'F') {
            rotation_Ground = F;
        } else if (input[i] == 'R') {
            rotation_Ground = R;
        } else if (input[i] == 'B') {
            rotation_Ground = B;
        } else if (input[i] == 'D') {
            rotation_Ground = D;
        }
        i++;
        if ((input.length() - i) > 0) {
            if (input[i] == '2') {
                rotation_type = Double;
                i++;
            } else if (input[i] == '\'') {
                rotation_type = Anticlockwise;
                i++;
            }
            ++i;
        }
        RotateGround(rotation_Ground, rotation_type);
    }
}

void CubeR::RotateWithOutput(const std::string &input, std::string &output) {
    output += input;
    if (input[input.length() - 1] != ' ') {
        output += ' ';
    }
    int i = 0;
    while (i < input.length()) {
        Ground rotation_Ground;
        Rotation rotation_type = Clockwise;
        if (input[i] == 'U') {
            rotation_Ground = U;
        } else if (input[i] == 'L') {
            rotation_Ground = L;
        } else if (input[i] == 'F') {
            rotation_Ground = F;
        } else if (input[i] == 'R') {
            rotation_Ground = R;
        } else if (input[i] == 'B') {
            rotation_Ground = B;
        } else if (input[i] == 'D') {
            rotation_Ground = D;
        }
        i++;
        if ((input.length() - i) > 0) {
            if (input[i] == '2') {
                rotation_type = Double;
                i++;
            } else if (input[i] == '\'') {
                rotation_type = Anticlockwise;
                i++;
            }
            i++;
        }
        RotateGround(rotation_Ground, rotation_type);
    }
}

std::string CubeR::Solve() {
    std::string moves;
    if (Solved()) {
        return moves;
    }
    if (!SolvedCross(D, Color::White) or !SolvedAdjacentToWhiteCross()) {
        while (!SolvedCross(U, Color::White)) {
            if (cube[L * 9 + 1] == Color::White) {
                RotateWithOutput("L", moves);
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F", moves);
            } else if (cube[F * 9 + 1] == Color::White) {
                RotateWithOutput("F", moves);
                while (cube[U * 9 + 5] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("R\'", moves);
            } else if (cube[R * 9 + 1] == Color::White) {
                RotateWithOutput("R\'", moves);
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F\'", moves);
            } else if (cube[B * 9 + 1] == Color::White) {
                RotateWithOutput("B", moves);
                while (cube[U * 9 + 3] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("L", moves);
            } else if (cube[L * 9 + 3] == Color::White) {
                while (cube[U * 9 + 1] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("B\'", moves);
            } else if (cube[L * 9 + 5] == Color::White) {
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F", moves);
            } else if (cube[F * 9 + 3] == Color::White) {
                while (cube[U * 9 + 3] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("L\'", moves);
            } else if (cube[F * 9 + 5] == Color::White) {
                while (cube[U * 9 + 5] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("R", moves);
            } else if (cube[R * 9 + 3] == Color::White) {
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F\'", moves);
            } else if (cube[R * 9 + 5] == Color::White) {
                while (cube[U * 9 + 1] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("B", moves);
            } else if (cube[B * 9 + 3] == Color::White) {
                while (cube[U * 9 + 5] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("R\'", moves);
            } else if (cube[B * 9 + 5] == Color::White) {
                while (cube[U * 9 + 3] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("L", moves);
            } else if (cube[L * 9 + 7] == Color::White) {
                while (cube[U * 9 + 3] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("L U B\'", moves);
            } else if (cube[F * 9 + 7] == Color::White) {
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F U L\'", moves);
            } else if (cube[R * 9 + 7] == Color::White) {
                while (cube[U * 9 + 5] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("R U F\'", moves);
            } else if (cube[B * 9 + 7] == Color::White) {
                while (cube[U * 9 + 1] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("B U R\'", moves);
            } else if (cube[D * 9 + 1] == Color::White) {
                while (cube[U * 9 + 7] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("F2", moves);
            } else if (cube[D * 9 + 3] == Color::White) {
                while (cube[U * 9 + 3] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("L2", moves);
            } else if (cube[D * 9 + 5] == Color::White) {
                while (cube[U * 9 + 5] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("R2", moves);
            } else if (cube[D * 9 + 7] == Color::White) {
                while (cube[U * 9 + 1] == Color::White) {
                    RotateWithOutput("U", moves);
                }
                RotateWithOutput("B2", moves);
            }
        }

        while (!SolvedCross(D, Color::White)) {
            while (cube[U * 9 + 7] != Color::White) {
                RotateWithOutput("U", moves);
            }
            if (cube[F * 9 + 1] == Color::Blue) {
                RotateWithOutput("U L2", moves);
            } else if (cube[F * 9 + 1] == Color::Red) {
                RotateWithOutput("F2", moves);
            } else if (cube[F * 9 + 1] == Color::Green) {
                RotateWithOutput("U\' R2", moves);
            } else if (cube[F * 9 + 1] == Color::Orange) {
                RotateWithOutput("U2 B2", moves);
            }
        }
        if (Solved()) {
            return moves;
        }
    }
    while (!SolvedWhiteEdges()) {
        if (cube[U * 9 + 0] == Color::White) {
            if (cube[L * 9 + 0] == Color::Blue) {
                RotateWithOutput("U\' F U F\' U\' F U F\' U\' F U F\' U\'", moves);
            } else if (cube[L * 9 + 0] == Color::Red) {
                RotateWithOutput("U2 R U R\' U\' R U R\' U\' R U R\' U\'", moves);
            } else if (cube[L * 9 + 0] == Color::Green) {
                RotateWithOutput("U B U B\' U\' B U B\' U\' B U B\' U\'", moves);
            } else if (cube[L * 9 + 0] == Color::Orange) {
                RotateWithOutput("L U L\' U\' L U L\' U\' L U L\' U\'", moves);
            }
        } else if (cube[U * 9 + 2] == Color::White) {
            RotateWithOutput("U\'", moves);
        } else if (cube[U * 9 + 6] == Color::White) {
            RotateWithOutput("U", moves);
        } else if (cube[U * 9 + 8] == Color::White) {
            RotateWithOutput("U2", moves);
        } else if (cube[L * 9 + 8] == Color::White) {
            RotateWithOutput("F U F\'", moves);
        } else if (cube[F * 9 + 8] == Color::White) {
            RotateWithOutput("R U R\' U", moves);
        } else if (cube[R * 9 + 8] == Color::White) {
            RotateWithOutput("B U B\' U2", moves);
        } else if (cube[B * 9 + 8] == Color::White) {
            RotateWithOutput("L U L\' U\'", moves);
        } else if (cube[L * 9 + 2] == Color::White) {
            RotateWithOutput("F U F\' U\' F U F\'", moves);
        } else if (cube[F * 9 + 2] == Color::White) {
            RotateWithOutput("R U R\' U' R U R\' U", moves);
        } else if (cube[R * 9 + 2] == Color::White) {
            RotateWithOutput("B U B\' U\' B U B\' U2", moves);
        } else if (cube[B * 9 + 2] == Color::White) {
            RotateWithOutput("L U L\' U\' L U L\' U\'", moves);
        } else if (cube[L * 9 + 6] == Color::White) {
            RotateWithOutput("L U\' L\'", moves);
        } else if (cube[F * 9 + 6] == Color::White) {
            RotateWithOutput("F U\' F\' U", moves);
        } else if (cube[R * 9 + 6] == Color::White) {
            RotateWithOutput("R U\' R\' U2", moves);
        } else if (cube[B * 9 + 6] == Color::White) {
            RotateWithOutput("B U\' B\' U\'", moves);
        } else if (cube[L * 9 + 0] == Color::White) {
            RotateWithOutput("U L U\' L\' U L U\' L\'", moves);
        } else if (cube[F * 9 + 0] == Color::White) {
            RotateWithOutput("U F U\' F\' U F U\' F\' U", moves);
        } else if (cube[R * 9 + 0] == Color::White) {
            RotateWithOutput("U R U\' R\' U R U\' R\' U2", moves);
        } else if (cube[B * 9 + 0] == Color::White) {
            RotateWithOutput("U B U\' B\' U B U\' B\' U\'", moves);
        } else if (cube[D * 9 + 0] == Color::White and cube[L * 9 + 8] != Color::Blue) {
            RotateWithOutput("F U F\' U\' F U F\' U\' F U F\'", moves);
        } else if (cube[D * 9 + 2] == Color::White and cube[F * 9 + 8] != Color::Red) {
            RotateWithOutput("R U R\' U\' R U R\' U\' R U R\' U", moves);
        } else if (cube[D * 9 + 6] == Color::White and cube[B * 9 + 8] != Color::Orange) {
            RotateWithOutput("L U L\' U\' L U L\' U\' L U L\' U\'", moves);
        } else if (cube[D * 9 + 8] == Color::White and cube[R * 9 + 8] != Color::Green) {
            RotateWithOutput("B U B\' U\' B U B\' U\' B U B\' U2", moves);
        }
    }

    if (Solved()) {
        return moves;
    }
    while (!SolvedSecondLayer()) {
        if (cube[U * 9 + 7] != Color::Yellow and cube[F * 9 + 1] != Color::Yellow) {
            if (cube[U * 9 + 7] == Color::Green and cube[F * 9 + 1] == Color::Red) {
                RotateWithOutput("U R U\' R\' U\' F\' U F", moves);
            } else if (cube[U * 9 + 7] == Color::Red and cube[F * 9 + 1] == Color::Green) {
                RotateWithOutput("U2 F\' U F U R U\' R\'", moves);
            } else if (cube[U * 9 + 7] == Color::Orange and cube[F * 9 + 1] == Color::Green) {
                RotateWithOutput("B U\' B\' U\' R\' U R", moves);
            } else if (cube[U * 9 + 7] == Color::Green and cube[F * 9 + 1] == Color::Orange) {
                RotateWithOutput("U R\' U R U B U\' B\'", moves);
            } else if (cube[U * 9 + 7] == Color::Blue and cube[F * 9 + 1] == Color::Orange) {
                RotateWithOutput("U\' L U\' L\' U\' B\' U B", moves);
            } else if (cube[U * 9 + 7] == Color::Orange and cube[F * 9 + 1] == Color::Blue) {
                RotateWithOutput("B\' U B U L U\' L\'", moves);
            } else if (cube[U * 9 + 7] == Color::Blue and cube[F * 9 + 1] == Color::Red) {
                RotateWithOutput("U\' L\' U L U F U\' F\'", moves);
            } else if (cube[U * 9 + 7] == Color::Red and cube[F * 9 + 1] == Color::Blue) {
                RotateWithOutput("U2 F U\' F\' U\' L\' U L", moves);
            }
        } else if (cube[U * 9 + 5] != Color::Yellow and cube[R * 9 + 1] != Color::Yellow) {
            RotateWithOutput("U", moves);
        } else if (cube[U * 9 + 1] != Color::Yellow and cube[B * 9 + 1] != Color::Yellow) {
            RotateWithOutput("U2", moves);
        } else if (cube[U * 9 + 3] != Color::Yellow and cube[L * 9 + 1] != Color::Yellow) {
            RotateWithOutput("U\'", moves);
        } else if (cube[B * 9 + 5] != cube[B * 9 + 4] or cube[L * 9 + 3] != cube[L * 9 + 4]) {
            RotateWithOutput("B\' U B U L U\' L\'", moves);
        } else if (cube[L * 9 + 5] != cube[L * 9 + 4] or cube[F * 9 + 3] != cube[F * 9 + 4]) {
            RotateWithOutput("L\' U L U F U\' F\'", moves);
        } else if (cube[F * 9 + 5] != cube[F * 9 + 4] or cube[R * 9 + 3] != cube[R * 9 + 4]) {
            RotateWithOutput("F\' U F U R U\' R\'", moves);
        } else if (cube[R * 9 + 5] != cube[R * 9 + 4] or cube[B * 9 + 3] != cube[B * 9 + 4]) {
            RotateWithOutput("B U\' B\' U\' R\' U R", moves);
        }
    }

    if (Solved()) {
        return moves;
    }

    while (!SolvedCross(U, Color::Yellow)) {
        if (cube[U * 9 + 1] == cube[U * 9 + 3]) {
            RotateWithOutput("F R U R\' U\' R U R\' U\' F\'", moves);
        } else if (cube[U * 9 + 3] == cube[U * 9 + 5]) {
            RotateWithOutput("F R U R\' U\' F\'", moves);
        } else if (cube[U * 9 + 1] != Color::Yellow and cube[U * 9 + 3] != Color::Yellow and
                   cube[U * 9 + 5] != Color::Yellow and cube[U * 9 + 7] != Color::Yellow) {
            RotateWithOutput("F R U R\' U\' F\' U2 F R U R\' U\' R U R\' U\' F\'", moves);
        } else {
            RotateWithOutput("U", moves);
        }
    }
    while (cube[F * 9 + 1] != cube[F * 9 + 4]) {
        RotateWithOutput("U", moves);
    }
    if (cube[L * 9 + 1] != Color::Blue or cube[F * 9 + 1] != Color::Red or
        cube[R * 9 + 1] != Color::Green or cube[B * 9 + 1] != Color::Orange) {
        if (cube[L * 9 + 1] == Color::Blue) {
            RotateWithOutput("L U L\' U L U2 L\' U", moves);
        } else if (cube[L * 9 + 1] == Color::Orange) {
            if (cube[R * 9 + 1] == Color::Green) {
                RotateWithOutput("F U F\' U F U2 F\' U", moves);
            } else {
                RotateWithOutput("U R U R\' U R U2 R\' U", moves);
            }
        } else if (cube[L * 9 + 1] == Color::Green) {
            RotateWithOutput("U\' B U B\' U B U2 B\' U", moves);
            if (cube[L * 9 + 1] != Color::Blue or cube[F * 9 + 1] != Color::Red or
                cube[R * 9 + 1] != Color::Green or cube[B * 9 + 1] != Color::Orange) {
                RotateWithOutput("U' R U R\' U R U2 R\' U2", moves);
            }
        }
    }
    while (!SolvedGround(U)) {
        while (cube[U * 9 + 8] == Color::Yellow) {
            RotateWithOutput("U", moves);
        }
        if (cube[F * 9 + 2] == Color::Yellow) {
            RotateWithOutput("R F\' R\' F R F\' R\' F", moves);
        } else if (cube[R * 9 + 0] == Color::Yellow) {
            RotateWithOutput("F\' R F R\' F\' R F R\'", moves);
        }
    }
    while (cube[F * 9 + 1] != cube[F * 9 + 4]) {
        RotateWithOutput("U", moves);
    }
    if (Solved()) {
        return moves;
    } else {
        int pll_tries = 5;
        while (!Solved() and pll_tries > 0) {
            pll_tries--;
            int side_Grounds_amount = 4 + 1;
            while (side_Grounds_amount>0) {
                side_Grounds_amount--;
                if (cube[F * 9 + 0] == cube[F * 9 + 2]) {
                    break;
                }
                RotateWithOutput("U", moves);
            }
            if (cube[F * 9 + 0] == cube[F * 9 + 2]) {
                if (cube[L * 9 + 0] == cube[L * 9 + 1] and cube[B * 9 + 1] == cube[B * 9 + 2]) {
                    RotateWithOutput("R\' D2 R U R\' D2 R U2 R\' D2 R U R\' D2 R", moves);
                } else if (cube[B * 9 + 0] == cube[B * 9 + 1] and cube[R * 9 + 1] == cube[R * 9 + 2]) {
                    RotateWithOutput("L D2 L\' U\' L D2 L\' U2 L D2 L\' U\' L D2 L\'", moves);
                } else if (cube[R * 9 + 0] == cube[R * 9 + 2]) {
                    RotateWithOutput("R2 U2 R2 U2 R2 U R2 U2 R2 U2 R2 U\'", moves);
                }
            } else if (cube[L * 9 + 0] == cube[R * 9 + 2] and cube[L * 9 + 2] == cube[R * 9 + 0]) {
                RotateWithOutput("U R\' U' R\' D\' R U\' R\' D R U R\' D\' R U R\' D R2", moves);
            } else if (cube[F * 9 + 0] == cube[B * 9 + 2] and cube[F * 9 + 2] == cube[B * 9 + 0]) {
                RotateWithOutput("R\' U\' R\' D\' R U\' R\' D R U R\' D\' R U R\' D R2", moves);
            }
            int count = 4;
            while (!Solved() and count > 0) {
                RotateGround(U, Clockwise);
                moves += "U ";
                count--;
            }
        }
        int count = 4;
        while (!Solved() and count > 0) {
            RotateGround(U, Clockwise);
            moves += "U ";
            count--;
        }
    }
    return moves;
}

bool CubeR::SolvedCross(Ground Ground, Color color) {
    return ((cube[(Ground * 9) + 1] == color) and (cube[(Ground * 9) + 3] == color) and
            (cube[(Ground * 9) + 5] == color) and (cube[(Ground * 9) + 7] == color));
}

bool CubeR::SolvedAdjacentToWhiteCross() {
    return ((cube[L * 9 + 4] == cube[L * 9 + 7]) and (cube[F * 9 + 4] == cube[F * 9 + 7]) and
            (cube[R * 9 + 4] == cube[R * 9 + 7]) and (cube[B * 9 + 4] == cube[B * 9 + 7]));
}

bool CubeR::SolvedWhiteEdges() {
    return ((cube[D * 9 + 0] == Color::White and cube[D * 9 + 2] == Color::White and
             cube[D * 9 + 6] == Color::White and cube[D * 9 + 8] == Color::White) and
            (cube[L * 9 + 4] == cube[L * 9 + 6] and cube[F * 9 + 4] == cube[F * 9 + 6] and
             cube[R * 9 + 4] == cube[R * 9 + 6] and cube[B * 9 + 4] == cube[B * 9 + 6]));
}

bool CubeR::SolvedSecondLayer() {
    return ((cube[L * 9 + 3] == cube[L * 9 + 4] and cube[L * 9 + 5] == cube[L * 9 + 4]) and
            (cube[F * 9 + 3] == cube[F * 9 + 4] and cube[F * 9 + 5] == cube[F * 9 + 4]) and
            (cube[R * 9 + 3] == cube[R * 9 + 4] and cube[R * 9 + 5] == cube[R * 9 + 4]) and
            (cube[B * 9 + 3] == cube[B * 9 + 4] and cube[B * 9 + 5] == cube[B * 9 + 4]));
}

bool CubeR::SolvedGround(Ground Ground) {
    for (int i = 0; i < 9; ++i) {
        if (cube[Ground * 9 + i] != cube[Ground * 9 + 4]) {
            return false;
        }
    }
    return true;
}

char CubeR::get(int index) {
    return (ColorToChar(cube[index]));
}

void Read(std::string &filename, CubeR &cube) {
    std::ifstream input_file(filename);
    if (!input_file) {
        std::cout << "Error with File" << '\n';
    } else {
        std::string cube_string;
        std::getline(input_file, cube_string);
        cube = CubeR(cube_string);
        std::cout << "The cube was successfully initialized from the file." << '\n';
    }
    input_file.close();
}

void Write(std::string &filename, CubeR &cube) {
    std::ofstream output_file(filename);
    if (!output_file) {
        std::cout << "Error with File" << '\n';
    } else {
        for (int i = 0; i < 54; i++) {
            output_file << cube.get(i);
        }
        std::cout << "Cube state saved successfully." << '\n';
    }
    output_file.close();
}