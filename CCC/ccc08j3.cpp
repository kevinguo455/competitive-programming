/*
CCC '08 J3 - GPS Text Entry
Key Concepts: Implementation
https://dmoj.ca/problem/ccc08j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

// returns the coordinates of a letter on the keyboard
pii coord(char c) {
    if (c == ' ') return {4, 2};
    if (c == '-') return {4, 3};
    if (c == '.') return {4, 4};
    if (c == '/') return {4, 5};    // end character
    if (c <= 'F') return {0, c-'A'};
    if (c <= 'L') return {1, c-'G'};
    if (c <= 'R') return {2, c-'M'};
    if (c <= 'X') return {3, c-'S'};
    if (c <= 'Z') return {4, c-'Y'};
    return {-10000, -10000};
}

// return the distance between two coordinates
int dist(pii a, pii b) {
    return abs(a.fi-b.fi) + abs(a.se-b.se);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    string s; getline(cin, s);
    s = 'A' + s + '/';
    for (int i = 1; i < (int) s.size(); i++) {
        ans += dist(coord(s[i-1]), coord(s[i]));
    }
    cout << ans << "\n";

    return 0;
}