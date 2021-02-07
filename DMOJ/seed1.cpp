/*
The Cosmic Era (Seed) P1 - Ship
Key Concepts: Implementation
https://dmoj.ca/problem/seed1
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

int main() {
    fio;

    string s; cin >> s;
    bool b = 0, f = 0, t = 0, l = 0, c = 0;
    f(i,0,(int)s.length()) {
        if (s[i] == 'B') b = 1;
        else if (s[i] == 'F') f = 1;
        else if (s[i] == 'T') t = 1;
        else if (s[i] == 'L') l = 1;
        else if (s[i] == 'C') c = 1;
    }
    if (b && f && t && l && c) {
        cout << "NO MISSING PARTS\n";
        return 0;
    }
    if (!b) cout << "B";
    if (!f) cout << "F";
    if (!t) cout << "T";
    if (!l) cout << "L";
    if (!c) cout << "C";
    cout << "\n";

    return 0;
}