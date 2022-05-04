/*
ACSL Practice 2009 Problem 7 - Cube
Key Concepts: Implementation, Brute Force, Graph Theory (?)
https://dmoj.ca/problem/acsl1p7
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 6, F = 4;
const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int faces[6][4] = {{1, 2, 4, 5},   // 0 = U
                         {2, 0, 5, 3},   // 1 = R
                         {3, 4, 0, 1},   // 2 = F
                         {4, 2, 1, 5},   // 3 = D
                         {5, 0, 2, 3},   // 4 = L
                         {0, 4, 3, 1}};  // 5 = B

int arr[N][N], cube[N];
bool valid = 1;

void solve(int r, int c, int face, int offset) {
    if (cube[face] && cube[face] != arr[r][c]) valid = 0;
    if (!valid || cube[face] == arr[r][c]) return;
    cube[face] = arr[r][c];

    for (int dir = 0; dir < F; dir++) {
        int tr = r + dirs[dir][0];
        int tc = c + dirs[dir][1];
        if (tr < 0 || tc < 0 || tr >= N || tc >= N || arr[tr][tc] == 0) continue;

        int new_face = faces[face][(dir+offset)%F], new_offset = -1;
        
        for (int k = 0; k < F; k++)
            if (faces[new_face][k] == face) new_offset = (k-dir+6)%F;
        
        solve(tr, tc, new_face, new_offset);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int sr = -1, sc = -1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == 1) {
                sr = r; sc = c;
            }
        }
    }

    solve(sr, sc, 0, 0);

    for (int i = 0; i < N; i++)
        if (!cube[i]) valid = 0;

    if (!valid) cout << "0\n";
    else cout << cube[3] << '\n';

    return 0;
}