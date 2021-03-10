/*
Back To School '18: Harambe
Key Concepts: Implementation
https://dmoj.ca/problem/bts18p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a; getline(cin, a);
    string b; getline(cin, b);
    int x = 0, y; cin >> y;
    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] != b[i]) x++;
        if (a[i] == ' ' ^ b[i] == ' ') x = 0x3f3f3f3f;
    }
    cout << (x <= y ? "Plagiarized" : "No plagiarism") << '\n';

    return 0;
}