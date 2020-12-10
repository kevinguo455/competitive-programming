/*
Mock CCC '15 Junior P3 - Problem-setting Pandemonium
Key Concepts: Implementation
https://dmoj.ca/problem/mockccc15j3
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int n, total = 0;
    std::cin >> n;
    int difficulty[n];

    for (int i = 0; i < n; i++) {
        std::cin >> difficulty[i];
        int j = 0;
        int k = 0;

        while (j < i) {
            if (difficulty[i] == difficulty[j]) {
                k = 1;
            }
            j++;
        }
        if (k == 0) {
            total++;
        }
    }

    std::cout << total;

    return 0;
}