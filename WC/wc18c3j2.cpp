#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x; cin >> n;
    priority_queue<int> pq;
    while (n--) {
        cin >> x;
        if (x > 100) continue;
        pq.push(x);
    }

    int ans = 0;
    if (!pq.empty()) ans += pq.top();
    if (!pq.empty()) pq.pop();
    if (!pq.empty()) ans += pq.top();
    cout << ans << "\n";

    return 0;
}