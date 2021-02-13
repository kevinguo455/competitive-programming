/*
CCC '06 J3 - Cell-Phone Messaging
Key Concepts: Implementation
https://dmoj.ca/problem/ccc06j3
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 1}, {'e', 2}, {'f', 3}, {'g', 1}, {'h', 2}, {'i', 3}, {'j', 1}, {'k', 2}, {'l', 3}, {'m', 1}, {'n', 2}, {'o', 3}, {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4}, {'t', 1}, {'u', 2}, {'v', 3}, {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4}};
map<char, int> b = {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 2}, {'e', 2}, {'f', 2}, {'g', 3}, {'h', 3}, {'i', 3}, {'j', 4}, {'k', 4}, {'l', 4}, {'m', 5}, {'n', 5}, {'o', 5}, {'p', 6}, {'q', 6}, {'r', 6}, {'s', 6}, {'t', 7}, {'u', 7}, {'v', 7}, {'w', 8}, {'x', 8}, {'y', 8}, {'z', 8}};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    string s; cin >> s;
    while (s != "halt") {
        int n = 0;
        f(i,0,(int)s.size()) {
            n += m[s[i]];
            if (i > 0 && b[s[i]] == b[s[i-1]]) n += 2;
        }
        cout << n << endl;
        cin >> s;
    }

}