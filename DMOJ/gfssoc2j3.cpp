/*
Glenforest Spring Open '15 Junior 3 - Equation Solver
Key Concepts: Implementation 
https://dmoj.ca/problem/gfssoc2j3
Solution by Kevin Guo
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string l, s; 
    getline(cin, l);
    stringstream str(l);     // fun with stringstreams :D
    int ans = 0;
    int op = 1;

    while (str >> s) {
        if (s == "P") op = 1;
        else if (s == "M") op = -1;
        else if (s != "=") ans += op * stoi(s);
    }
    cout << ans << "\n";

    return 0;
}