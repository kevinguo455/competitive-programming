/*
COCI '08 Contest 6 #4 Cuskija
Key Concepts: Ad Hoc, Simple Math (divisibility)
https://dmoj.ca/problem/coci08c6p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    scanf("%d", &size);
    queue<int> m0, m1, m2;
    for (int i = 0; i < size; i++) {
        int x; cin >> x;
        if (x % 3 == 0) 
            m0.push(x);
        else if (x % 3 == 1)
            m1.push(x);
        else 
            m2.push(x);
    }

    if ((m0.size() == 0 && m1.size() > 0 && m2.size() > 0) || m0.size() > m1.size() + m2.size() + 1) {
        cout << "impossible" << endl;
        return 0;
    }

    while (m1.size() > 0) {
        if (m0.size() > 1) {
            cout << m0.front() << " ";
            m0.pop();
        }
        cout << m1.front() << " ";
        m1.pop();
    }

    if (m0.size() > 0) {
        cout << m0.front() << " ";
        m0.pop();
    }

    while (m2.size() > 0) {
        cout << m2.front() << " ";
        m2.pop();
        if (m0.size() > 0) {
            cout << m0.front() << " ";
            m0.pop();
        }
    }

    cout << endl;

    return 0;
}