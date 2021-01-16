/*
DWITE '07 R1 #2 - Cubes in a Pyramid
Key Concepts: Simple Math
https://dmoj.ca/problem/dwite07c1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double b, h; 
    cin >> b >> h;
    cout << ceil(b*b*h/3) << "\n";

    return 0;
}