/*
Mock CCC '15 Junior P4 - Vox in Box
Key Concepts: Implementation
https://dmoj.ca/problem/mockccc15j4
Solution by Kevin Guo
*/
#include <iostream>
#include <string>
#include <vector>

int l, symmetry = 0;
std::vector<std::string> box;

void checkv() { //Symmetry across horizontal line
    char a, b;

    for (int x = 0; x < l; x++) {
        for (int y = 0; y < l; y++) {
            a = box[x][y];
            b = box[l-x-1][y];

            if ((a == '.' && b == '.') || (a == 'O' && b == 'O') || (a == '\\' && b == '/') || (a == '/' && b == '\\') || (a == '(' && b == '(') || (a == ')' && b == ')')) {
            }
            else {
                return;
            }
        }
    }
    symmetry++;
}

void checkh() { //Symmetry across vertical line
    char a, b;

    for (int x = 0; x < l; x++) {
        for (int y = 0; y < l; y++) {
            a = box[x][y];
            b = box[x][l-y-1];

            if ((a == '.' && b == '.') || (a == 'O' && b == 'O') || (a == '\\' && b == '/') || (a == '/' && b == '\\') || (a == '(' && b == ')') || (a == ')' && b == '(')) {
            }
            else {
                return;
            }
        }
    }
    symmetry++;
}

void checkd1() { //Symmetry across topright-bottomleft
    char a, b;

    for (int x = 0; x < l; x++) {
        for (int y = 0; y < l; y++) {
            a = box[x][y];
            b = box[l-y-1][l-x-1];

            if ((a == '.' && b == '.') || (a == 'O' && b == 'O') || (a == '\\' && b == '\\') || (a == '/' && b == '/')) {
            }
            else {
                return;
            }
        }
    }
    symmetry++;
}

void checkd2() { //Symmetry across topleft-bottomright
    char a, b;

    for (int x = 0; x < l; x++) {
        for (int y = 0; y < l; y++) {
            a = box[x][y];
            b = box[y][x];

            if ((a == '.' && b == '.') || (a == 'O' && b == 'O') || (a == '\\' && b == '\\') || (a == '/' && b == '/')) {
            }
            else {
                return;
            }
        }
    }
    symmetry++;
}

int main() {
    std::cin >> l;

    std::string s;
    for (int i = 0; i < l; i++) {
        std::cin >> s;
        box.push_back(s);
    }

    checkv();
    checkh();
    checkd1();
    checkd2();

    std::cout << symmetry << std::endl;

    return 0;
}