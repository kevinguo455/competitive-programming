/*
The Cosmic Era (Seed) P3 - Battle Positions
Key Concepts: Data Structures (Difference Array)
https://dmoj.ca/problem/seed3
Solution by Kevin Guo
*/
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
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int d[MAXN];

int main() {
    fio;

    int n, m, q; cin >> n >> m >> q;
    
    // init difference array
    int l, r, a;
    f(i,0,q){
        cin >> l >> r >> a;
        d[l] += a;
        d[r+1] -= a;
    }

    // eval difference array
    int c = 0;
    f(i,0,n){
        if (d[i] < m) c++;
        d[i+1] += d[i];
    }

    cout << c << "\n";

    return 0;
}