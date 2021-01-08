/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 0B - Interleaving Leaves
Key Concepts: Implementation, String Algorithms
https://dmoj.ca/problem/acmtryouts0b
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int cases, n;
    std::string a, b, out = "";
    std::cin >> cases;

    for (int i = 0; i < cases; i++) {
        out = "";
        std::cin >> n >> a >> b;
        for (int j = n - 1; j >= 0; j--) {
            out += b[j];
            out += a[j];
        }
        std::cout << out << std::endl;
    }

    return 0;
}