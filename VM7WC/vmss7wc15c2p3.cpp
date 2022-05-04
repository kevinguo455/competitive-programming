/*
VM7WC '15 #2 Gold - Uniting the Earth Empire
Key Concepts: Data Structures (monotonic stack)
https://dmoj.ca/problem/vmss7wc15c2p3
Solution by Kevin Guo
*/

// This is also a solution to COI '06 #1 Patrik: https://dmoj.ca/problem/coi06p1 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Hill {
    ll h;   // height
    int f;  // freq
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    stack<Hill> mono_stack;

    ll x, ans = 0; cin >> x;
    mono_stack.push({x, 1});
    N--;

    while (N--) {
        cin >> x;
        while (!mono_stack.empty() && mono_stack.top().h < x) {          
            ans += mono_stack.top().f;
            mono_stack.pop();
        }
        if ((!mono_stack.empty() && mono_stack.top().h > x) || (mono_stack.size() >= 2 && mono_stack.top().h == x)) ans++;
        if (!mono_stack.empty() && mono_stack.top().h == x) ans += mono_stack.top().f++;
        else mono_stack.push({x, 1});
    }

    cout << ans << '\n';

    return 0;
}