/*
The DMOJ Driveway
Key Concepts: Data Structures (stack)
https://dmoj.ca/problem/stack1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    deque<string> driveway;
    int T, M; cin >> T >> M;
    string x, c;

    while (T--) {
        cin >> x >> c;
        if (c == "in") {
            driveway.push_back(x);
        }
        else {
            if (driveway.empty()) continue;
            if (driveway.back() == x) {
                driveway.pop_back();
            }
            else if (driveway.front() == x && M) {
                driveway.pop_front();
                M--;
            }
        }
    }

    while (!driveway.empty()) {
        cout << driveway.front() << '\n';
        driveway.pop_front();
    }

    return 0;
}