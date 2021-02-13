/*
CCC '11 J4 - Boring Business
Key Concepts: Implementation
https://dmoj.ca/problem/ccc11j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXW = 410, MAXH = 210;

bitset<MAXH * MAXW> arr;

int r = -1, c = 0;
bool danger = 0;

// marks a certain square as visited
void mark(int y, int x) {
    int loc = (-y) * MAXH + x + MAXW/2;
    if (arr[loc]) danger = 1;
    else arr[loc] = 1;
}

// executes a drilling command
void traverse(char dir, int n) {
    int dr = 0, dc = 0;
    if (dir == 'd') dr = -1;
    else if (dir == 'u') dr = 1;
    else if (dir == 'l') dc = -1;
    else if (dir == 'r') dc = 1;
    for (int i = 0; i < n; i++) {
        r += dr;
        c += dc;
        //cout << r << " " << c << endl;
        mark(r, c);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    // init
    mark(r, c);
    traverse('d', 2);
    traverse('r', 3);
    traverse('d', 2);
    traverse('r', 2);
    traverse('u', 2);
    traverse('r', 2);
    traverse('d', 4);
    traverse('l', 8);
    traverse('u', 2);

    // logic
    char dir;
    int n;
    cin >> dir >> n;

    while (!danger && dir != 'q') {
        traverse(dir, n);
        cout << c << " " << r << " ";

        if (danger) cout << "DANGER\n";
        else cout << "safe\n";

        cin >> dir >> n;
    }

    return 0;
}