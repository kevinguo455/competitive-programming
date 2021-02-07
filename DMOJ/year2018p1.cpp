/*
Happy New Year!
Key Concepts: Implementation
https://dmoj.ca/problem/year2018p1
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

    int h, m, s; cin >> h >> m >> s;
    h %= 12;
    m %= 12 * 60;
    s %= 12 * 60 * 60;
    m += h * 60;
    s += m * 60;

    s = 12 * 24 * 60 * 60 - s;
    m = s / 60;
    s %= 60;
    h = m / 60;
    m %= 60;
    h %= 12;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}