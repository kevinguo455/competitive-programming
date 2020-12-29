/*
COCI '06 Contest 2 #1 R2
Key Concepts: Simple Math
https://dmoj.ca/problem/coci06c2p1
Solution by Kevin Guo
*/
#include <iostream>

int main() {

    int R1, R2, S;

    std::cin >> R1 >> S;

    R2 = S + (S-R1);

    std::cout << R2;

    return 0;
}


