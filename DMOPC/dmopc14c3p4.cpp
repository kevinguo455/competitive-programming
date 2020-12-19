/*
DMOPC '14 Contest 3 P4 - Not Enough Testers!
Key Concepts: Factorization, Binary Search, Implementation
https://dmoj.ca/problem/dmopc14c3p4
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5, MAXK = 128; 

int fac[MAXN];
vi num[MAXK+1];

int main() {
    fio;

    // sieve
    f(i,1,MAXN){
        for (int j = i; j < MAXN; j+=i){
            fac[j]++;
        }
    }
    f(i,1,MAXN){
        num[fac[i]].pb(i);
    }

    int q, k, a, b; cin >> q;
    f(i,0,q){
        cin >> k >> a >> b;
        if (k > MAXK) {
            cout << 0 << "\n";
        }
        else {
            cout << distance(lower_bound(num[k].begin(), num[k].end(), a), upper_bound(num[k].begin(), num[k].end(), b)) << "\n";
        }
    }

    return 0;
}