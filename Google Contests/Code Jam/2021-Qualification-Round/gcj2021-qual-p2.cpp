/*
Code Jam 2021 Qualification Round Problem 2 - Moons and Umbrellas
Key Concepts: Dynamic Programming
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

// dp_c[i] is the minimum cost of the string up to index i, choosing str[i] = 'C'
// dp_j[i] is the minimum cost of the string up to index i, choosing str[i] = 'J'
int dp_c[MAXN], dp_j[MAXN];

int solve() {
    int X, Y;
    string str;
    cin >> X >> Y >> str;

    memset(dp_c, 0x3f, sizeof(dp_c));
    memset(dp_j, 0x3f, sizeof(dp_j));

    // if str[0] == 'C' or str[0] == '?', then it is possible to start the resulting string with 'C'
    if (str[0] != 'J') dp_c[0] = 0;
    // similar case for starting resulting string with 'J'
    if (str[0] != 'C') dp_j[0] = 0;

    for (int i = 1; i < str.length(); ++i) {
        if (str[i] != 'J') dp_c[i] = min(dp_c[i-1], dp_j[i-1] + Y);
        if (str[i] != 'C') dp_j[i] = min(dp_j[i-1], dp_c[i-1] + X);
    }

    return min(dp_c[str.length()-1], dp_j[str.length()-1]);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}