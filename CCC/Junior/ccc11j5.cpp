// https://dmoj.ca/problem/ccc11j5
#include <bits/stdc++.h>
using namespace std;

vector<int> g[7];

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    int score = 0;
    for (int i = 0; i < pow(2, n-1); i++) {
        int x = i;
        bool good = 1;
        for (int j = 1; j < n; j++) {
            if (x % 2 == 1) {
                queue<int> q;
                q.push(j);
                while (!q.empty()) {
                    int d = q.front();
                    q.pop();
                    if ((i >> (d-1)) % 2 == 0) {
                        good = 0;
                        break;
                    }
                    for (int i:g[d])
                        q.push(i);
                }
            }
            x = x >> 1;
        }
        if (good) score++;
    }
    cout << score << endl;
    return 0;
}