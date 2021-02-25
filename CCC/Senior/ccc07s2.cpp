/*
CCC '07 S2 - Boxes
Key Concepts: Implementation
https://dmoj.ca/problem/ccc07s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Box {
    int l, w, h;
    int v;
    bool operator<(const Box &b) {
        return v < b.v;
    }
};

vector<Box> boxes;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    boxes.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].l >> boxes[i].w >> boxes[i].h;
        boxes[i].v = boxes[i].l * boxes[i].w * boxes[i].h;
    }

    int Q; cin >> Q;
    int dim[3];
    for (int i = 0; i < Q; i++) {
        cin >> dim[0] >> dim[1] >> dim[2];
        sort(dim, dim + 3);

        int minv = INF;
        for (Box b : boxes) {
            do {
                if (b.l >= dim[0] && b.w >= dim[1] && b.h >= dim[2]) {
                    minv = min(minv, b.v);
                }
            }
            while (next_permutation(dim, dim + 3));
        }

        if (minv == INF) cout << "Item does not fit.\n";
        else cout << minv << '\n';
    }
}