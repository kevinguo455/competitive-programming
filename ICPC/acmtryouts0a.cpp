/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 0A - Max Flow
Key Concepts: Implementation
https://dmoj.ca/problem/acmtryouts0a
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int t, n, x = 0, y = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        y = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> x;
            if (x > y) {
                y = x;
            }
        }
        std::cout << y << std::endl;
    }

    return 0;
}