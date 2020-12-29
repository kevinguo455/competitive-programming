/*
COCI '06 Contest 3 #1 Patuljci
Key Concepts: Implementation
https://dmoj.ca/problem/coci06c3p1
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int dwarves[9];
    int total = 0, n = 0;
    for (int i = 0; i < 9; i++) {
        std::cin >> dwarves[i];
        total += dwarves[i];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j != i) {
                n = total;
                n -= dwarves[i];
                n -= dwarves[j];
                if (n == 100) {
                    for (int k = 0; k < 9; k++) {
                        if (k != i && k != j) {
                            std::cout << dwarves[k] << std::endl;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}