// https://dmoj.ca/problem/ccc03s3
#include <bits/stdc++.h>
using namespace std;

int f, rs, cs;
char grid[26][26];
bool vis[26][26];
vector<int> roomSizes;

pair<int, int> next() {
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            if (!vis[i][j]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main() {
    cin >> f >> rs >> cs;
    for (int i = 0; i < rs; i++) {
        string s; cin >> s;
        for (int j = 0; j < cs; j++) {
            grid[i][j] = s[j];
            if (s[j] == 'I') {
                vis[i][j] = 1;
            }
        }
    }

    pair<int, int> nextLoc = next();
    while (nextLoc.first != -1) {
        int size = 0;
        queue<pair<int, int> > q;
        q.push(nextLoc); // bfs
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r < 0 || c < 0 || r >= rs || c >= cs) {
                continue;
            }
            if (vis[r][c]) {
                continue;
            }
            size++;
            vis[r][c] = 1;
            q.push(make_pair(r-1,c));
            q.push(make_pair(r+1,c));
            q.push(make_pair(r,c-1));
            q.push(make_pair(r,c+1));
        }
        roomSizes.push_back(size);
        nextLoc = next();
    }
    sort(roomSizes.begin(), roomSizes.end(), greater<int>());
    int filled = 0;
    for (int i:roomSizes) {
        if (i > f) {
            break;
        }
        f -= i;
        filled++;
    }
    cout << filled << " room";
    if (filled != 1) cout << "s";
    cout << ", " << f << " square metre(s) left over" << endl;
    return 0;
}