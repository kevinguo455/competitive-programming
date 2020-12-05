// https://dmoj.ca/problem/dmopc13c1p4
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, w; cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l >> w;
        int row, col;
        char house[51][51];
        for (int j = 0; j < w; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < l; k++) {
                house[j][k] = s[k];
                if (s[k] == 'C') {
                    row = j;
                    col = k;
                }
            }
        }
        queue<pair<int, int> > q; // bfs
        q.push(make_pair(row, col));
        int d = 0;
        bool exit = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (r < 0 || c < 0 || r >= w || c >= l) continue;
                char ch = house[r][c];
                if (ch == 'X') continue;
                if (ch == 'W') {
                    // good
                    exit = 1;
                    break;
                }
                // keep searching
                house[r][c] = 'X';
                q.push(make_pair(r-1,c));
                q.push(make_pair(r,c-1));
                q.push(make_pair(r,c+1));
                q.push(make_pair(r+1,c));
            }
            if (exit) break;
            d++;
            if (d >= 60) break;
            if (q.empty()) d = 60;
        }
        if (d >= 60) 
            cout << "#notworth" << endl;
        else 
            cout << d << endl;
    }
    return 0;
}
