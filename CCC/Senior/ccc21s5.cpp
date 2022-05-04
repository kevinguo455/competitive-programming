/*
CCC '21 S5 - Math Homework
Key Concepts: Intermediate Math (GCD/LCM), Data Structures (Difference Array, Sparse Table)
https://dmoj.ca/problem/ccc21s5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005, MAXZ = 16, MAXK = 18; 

int N, M;
short diff[MAXZ+1][MAXN];   // range assignments
int arr[MAXN];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

struct Rule{int a, b, z;} rules[MAXN];

int st[MAXN][MAXK];
int lg2[MAXN];

int query(int l, int r) {
    if (l == r) return st[l][0];
    int k = lg2[r-l+1];
    return gcd(st[l][k-1], st[r-(1<<k)+1][k-1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    // read GCD restrictions
    for (int i = 1; i <= M; i++) {
        cin >> rules[i].a >> rules[i].b >> rules[i].z;
        diff[rules[i].z][rules[i].a]++;
        diff[rules[i].z][rules[i].b+1]--;
    }

    // construct array of LCMs
    for (int i = 1; i <= N; i++) {
        arr[i] = 1;
        for (int z = 1; z <= MAXZ; z++) {
            diff[z][i+1] += diff[z][i];
            if (diff[z][i] > 0) arr[i] = lcm(arr[i], z);
        }
    }

    // precompute logs base 2
    for (int i = 2; i <= N; i++) lg2[i] = lg2[i/2] + 1;

    // build sparse table (GCD queries)
    for (int i = 1; i <= N; i++) st[i][0] = arr[i];
    for (int j = 1; j <= lg2[N]; j++) {
        for (int i = 1; i + (1<<j) <= N + 1; i++) {
            st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    // verify GCD restrictions
    for (int i = 1; i <= M; i++) {
        int a = rules[i].z;
        int b = query(rules[i].a, rules[i].b);
        if (rules[i].z != query(rules[i].a, rules[i].b)) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // output array
    for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}