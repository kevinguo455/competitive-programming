/*
Chow Computing Contest 2019-2020 S4 — Arithmetic Square
Key Concepts: 
https://www.hackerrank.com/contests/the-chow-computing-contest-2019-1/challenges/s4arithmetic-square
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Square {
    int arr[3][3];

    bool solved() {
        return (arr[0][0] == 1 && arr[0][1] == 2 && arr[0][2] == 3 &&
                arr[1][0] == 4 && arr[1][1] == 5 && arr[1][2] == 6 &&
                arr[2][0] == 7 && arr[2][1] == 8 && arr[2][2] == 0);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Square s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> s.arr[i][j];
        }
    }

    queue<Square> q;
    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Square c = q.front(); 
            q.pop();
            if (c.solved()) {
                cout << dist << "\n";
                return 0;
            }
        }
        dist++;
    }

    return 0;
}