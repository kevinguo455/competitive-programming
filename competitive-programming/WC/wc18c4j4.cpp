// https://dmoj.ca/problem/wc18c4j4
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

char inc(char c, int n) {
    c += n;
    if (c > 'Z') c -= 26;
    return c;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    if (k < n+1 || k > 14*n+1) {
        cout << "Impossible" << endl;
        return 0;
    }
    k = k - n - 1;
    char c = 'A';
    while (k > 0) {
        if (k >= 13) {
            c = inc(c, 13);
            k -= 13;
            cout << c;
        }
        else {
            c = inc(c, k);
            k = 0;
            cout << c;
        }
        n -= 1;
    }
    while (n > 0) {
        cout << c;
        n -= 1;
    }
    cout << endl;
    return 0;
}