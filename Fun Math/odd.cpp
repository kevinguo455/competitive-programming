// https://dmoj.ca/problem/odd
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum = sum ^ x;
    }
    cout << sum << endl;
    return 0;
}