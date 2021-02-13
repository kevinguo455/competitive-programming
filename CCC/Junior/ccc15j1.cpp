// https://dmoj.ca/problem/ccc15j1
#include <iostream>
#include <string>

int main() {
    int m, d;
    std::cin >> m >> d;
    if (m == 2) {
        if (d == 18) {
            std::cout << "Special";
        } else if (d < 18) {
            std::cout << "Before";
        } else {
            std::cout << "After";
        }
    } else if (m < 2) {
        std::cout << "Before";
    } else {
        std::cout << "After";
    }
    return 0;
}
