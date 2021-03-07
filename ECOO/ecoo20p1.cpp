/*
ECOO '20 P1 - Music with Mimi
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo20p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12; 

int note(string s) {
    if (s == "C") return 0;
    else if (s == "C#") return 1;
    else if (s == "D") return 2;
    else if (s == "D#") return 3;
    else if (s == "E") return 4;
    else if (s == "F") return 5;
    else if (s == "F#") return 6;
    else if (s == "G") return 7;
    else if (s == "G#") return 8;
    else if (s == "A") return 9;
    else if (s == "A#") return 10;
    else if (s == "B") return 11;
    else return 12;
}

int d(int a, int b) {
    return (b - a + MAXN) % MAXN;
}

bool d7(int n[4]) {
    return (d(n[0], n[1]) == 4 && d(n[1], n[2]) == 3 && d(n[2], n[3]) == 3);
}

void rshift(int n[4]) {
    int t = n[3];
    n[3] = n[2];
    n[2] = n[1];
    n[1] = n[0];
    n[0] = t;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int cases; cin >> cases;
    while (cases--) {
        string s;
        int n[4];
        for (int i = 0; i < 4; i++) {
            cin >> s;
            n[i] = note(s);
        }
        if (d7(n)) {
            cout << "root\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "first\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "second\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "third\n";
            continue;
        }
        cout << "invalid\n";
    }

    return 0;
}