/*
CCC '08 J2 - Do the Shuffle
Key Concepts: Implementation
https://dmoj.ca/problem/ccc08j2
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
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    deque<char> dq;
    dq.pb('A');
    dq.pb('B');
    dq.pb('C');
    dq.pb('D');
    dq.pb('E');

    int a = -1, n = -1;
    char x, y;

    while (a != 4) {
        cin >> a >> n;
        if (a == 1) {
            f(i,0,n) {
                dq.pb(dq.front());
                dq.pop_front();
            }
        }
        else if (a == 2) {
            f(i,0,n) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if (a == 3) {
            if (n % 2 == 1) {
                x = dq.front();
                dq.pop_front();
                y = dq.front();
                dq.pop_front();
                dq.push_front(x);
                dq.push_front(y);
            }
        }
        else if (a == 4) {
            while (!dq.empty()) {
                cout << dq.front() << " ";
                dq.pop_front();
            }
        }
    }

    return 0;
}