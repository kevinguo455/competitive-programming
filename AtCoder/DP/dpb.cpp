/*
AtCoder Educational DP Contest Problem B - Frog 2
Key Concepts: Dynamic Programming
https://dmoj.ca/problem/dpb
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MAXN = 1e5+5;

int c[MAXN];
int h[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    f(i,1,n+1){
        cin >> h[i];
    }
    ms(c,0x3f);
    c[1] = 0;
    f(i,2,n+1){
        f(j,max(i-k,1),i){  // try jump to every rock in range, storing minimum
            c[i] = min(c[i], c[j] + abs(h[j]-h[i]));
        }
    }
    cout << c[n] << endl;
    return 0;
}