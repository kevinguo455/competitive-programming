/*
Mock CCC '15 Junior P2 - Lowest Exam Mark
Key Concepts: Simple Math
https://dmoj.ca/problem/mockccc15j2
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int p, q, w, n;
    std::cin >> p >> q >> w;
    for (int i = 0; i <= 100; i++) {
        if (p * (100-w) + i * w >= q * 100 - 50) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << "DROP THE COURSE";
    return 0;
}