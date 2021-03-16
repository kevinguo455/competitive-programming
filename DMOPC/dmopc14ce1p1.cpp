/*
DMOPC '14 Exam Time P1 - French Homework
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc14ce1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string a, b; cin >> a >> b;
    cout << a << "-tu ";
    if (b[b.length()-1] == 's') cout << "les ";
    else if (b[b.length()-1] == 'e') cout << "la ";
    else cout << "le ";
    cout << b << " ?\n";

    return 0;
}