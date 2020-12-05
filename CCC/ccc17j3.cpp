// https://dmoj.ca/problem/ccc17j3
#include <iostream>
#include <cstdlib>

int main() {
    int startx, starty, endx, endy, steps;
    std::cin >> startx >> starty >> endx >> endy >> steps;

    int d;
    d = abs(endx-startx) + abs(endy-starty);

    if (steps < d) {
        std::cout << "N";
    } else if (steps % 2 == d % 2) {
        std::cout << "Y";
    } else {
        std::cout << "N";
    }
    return 0;
}