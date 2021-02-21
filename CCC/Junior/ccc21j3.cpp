/*
CCC '21 J3 - Secret Instructions
Key Concepts: Implementation
https://dmoj.ca/problem/ccc21j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string in; cin >> in;
    string lastdir; 
    while (in != "99999") {
        int dir = in[0] - '0' + in[1] - '0';
        if (dir % 2 == 1) lastdir = "left";
        else if (dir % 2 == 0 && dir != 0) lastdir = "right";
        cout << lastdir << ' ' << in.substr(2) << '\n';
        cin >> in;
    }

    return 0;
}