/*
PEG Test '14 - Water
Key Concepts: Implementation
https://dmoj.ca/problem/avatarwater
Solution by Kevin Guo
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, fish;
    cin >> a >> b >> c;
    if (a == b) {
        fish = c - a;
    } else if (a == c) {
        fish = b - a;
    } else {
        fish = a - b;
    }
    cout << fish;
    return 0;
}