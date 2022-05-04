/*
PEG Test '14 - Earth
Key Concepts: Implementation
https://dmoj.ca/problem/avatarearth
Solution by Kevin Guo
*/
#include <iostream>
using namespace std;

int main() {
    int x, y, a, c, b, d;
    cin >> x >> y >> a >> c >> b >> d;
    if ((x >= a && x <= b) && (y >= c && y <= d)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}