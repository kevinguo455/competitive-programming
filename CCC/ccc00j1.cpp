// https://dmoj.ca/problem/ccc00j1
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << "Sun Mon Tue Wed Thr Fri Sat" << std::endl;
    for (int i = 1; i < a; i++) {
        std::cout << "    ";
    }
    for (int i = a + 1; i < a + b + 1; i++) {
        if (i - a < 10) {
            std::cout << " ";
        }
        std::cout << " " << i - a;
        if ((i - 1) % 7 == 0) {
            std::cout << std::endl;
        }
        else if (i == a + b) {
            std::cout << std::endl;
        }
        else {
            std::cout << " ";
        }
    }
}