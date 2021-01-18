/*
Sales
Key Concepts: 
https://dmoj.ca/problem/sales
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 3e4+5; 


// knapsack
/*

n items, item i has cost w[i] and value v[i]
in the following D days, day j
card aj cost changes from w[aj] to b[j]
only xj ... yj items can be purchased

max weight <= 50

1. segment tree + knapsack
single updates, range queries to knapsack

*/
int B, N, D;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> B >> N >> D;
    for (int i = 1; i <= N; i++) {
        

        // consider multiset
    }
    // loop through days
    int a, b, x, y;
    for (int k = 1; k <= D; k++) {
        cin >> a >> b >> x >> y;
        // erase the ath cards
        w[a] = b;
        // reinsert the diff card

        // knapsack
        ms(dp, 0);
        for (int j = 1; j <= B; j++) {
            int idx = 0;

            // lop through all cards
                // if this card is in the range [x, y] and its worth buying (is idx < B/j)
                    // 0-1 knapsack consider buying
        }
    
    }

    return 0;
}