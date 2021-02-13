/*
Mock CCC '21 S4 - Forest Cabin
Key Concepts: Coordinate Rotation, 2D Prefix Sum Array
https://www.hackerrank.com/contests/mss-csec-mock-2021-senior/challenges/csec-2021-mock-structure
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2002, MAXN2 = 4005; 
//const int MAXN = 5, MAXN2 = 10; 

int arr[MAXN2][MAXN2];
ll psa[MAXN2][MAXN2];

struct Coord{int x, y;};

int R, C, Q;

Coord r45(int x, int y) {
    return {x+y, x-y+MAXN};
}

Coord r45(Coord c) {
    return r45(c.x, c.y);
}

void print() {
    for (int i = 0; i < MAXN2; i++) {
        for (int j = 0; j < MAXN2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void print2() {
    for (int i = 0; i < MAXN2; i++) {
        for (int j = 0; j < MAXN2; j++) {
            cout << psa[i][j] << " ";
        }
        cout << "\n";
    }
}

void build() {
    for (int i = 1; i < MAXN2; i++) {
        for (int j = 1; j < MAXN2; j++) {
            psa[i][j] = arr[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
}

ll sum(int r1, int r2, int c1, int c2) {
    r2 = min(r2, MAXN2-1);
    c2 = min(c2, MAXN2-1);
    c1 = max(0, c1-1);
    r1 = max(0, r1-1);
    return psa[r2][c2] - psa[r2][c1] - psa[r1][c2] + psa[r1][c1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> Q;
    Coord c;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            c = r45(i, j);
            cin >> arr[c.x][c.y];
        }
    }

    //print();
    build();
    //print2();

    int r;
    while (Q--) {
        cin >> c.x >> c.y >> r;
        c = r45(c);
        cout << sum(c.x - r, c.x + r, c.y - r, c.y + r) << '\n';
    }

    return 0;
}