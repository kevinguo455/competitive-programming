// https://dmoj.ca/problem/ccc03j1
#include <iostream>
#include <math.h>

int main() {
    int t, s, h;
    std::cin >> t >> s >> h;
    for (int i = 0; i < t; i++) {
        std::cout << "*";
        for (int j = 0; j < s; j++) {
            std::cout << " ";
        }
        std::cout << "*";
        for (int j = 0; j < s; j++) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }
    for (int j = 0; j < s*2+3; j++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    for (int i = 0; i < h; i++) {
        std::cout << " ";
        for (int j = 0; j < s; j++) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }

    return 0;
}