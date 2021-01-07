/*
AtCoder Educational DP Contest Problem A - Frog 1
Key Concepts: Dynamic Programming 
https://dmoj.ca/problem/dpa
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MAXN = 100005;

int c[MAXN];
int h[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    f(i,1,n+1){
        cin >> h[i];
    }
    c[2] = abs(h[1]-h[2]);  // dp transition: minimum of (jump from two rocks away), (jump from one rock away)
    f(i,3,n+1){
        c[i] = min(c[i-1] + abs(h[i-1]-h[i]), c[i-2] + abs(h[i-2]-h[i]));
    }
    cout << c[n] << endl;
    return 0;
}