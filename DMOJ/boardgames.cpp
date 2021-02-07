/*
Board Games
Key Concepts: Graph Theory (BFS)
https://dmoj.ca/problem/boardgames
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 160000; 

bool vis[MAXN];

int main() {
    fio;

    int n, m, d = 0; cin >> n >> m;

    queue<int> q;   // bfs
    q.push(n);
    while (!q.empty()) {
        int s = q.size();
        f(i,0,s){
            int c = q.front();
            q.pop();
            if (c == m) {               // reached end
                cout << d << "\n";
                return 0;
            }
            if (c < 0 || c > MAXN) continue; // out of range
            if (vis[c]) continue;

            vis[c] = 1;

            // possible moves
            q.push(3*c);
            q.push(c-1);
            q.push(c-3);
            if (c % 2 == 0) q.push(c/2);
        }
        d++;    // track distance
    }

    cout << "Uh oh...\n";

    return 0;
}