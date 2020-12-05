// https://dmoj.ca/problem/ccc01j1
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        for (int j = 0; j < n-i; j++) {
            std::cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = n-2; i >= 1; i -= 2) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        for (int j = 0; j < n-i; j++) {
            std::cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
