/*
Necroposting
Key Concepts: Implementation
https://dmoj.ca/problem/necroposting
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int year_days = 365;
const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int y, m, d;

    void init() {
        string s, t; cin >> s;
        stringstream ss(s);
        getline(ss, t, '/');
        y = stoi(t);
        getline(ss, t, '/');
        m = stoi(t);
        getline(ss, t, '/');
        d = stoi(t);
    }

    int nth_day() {
        int ans = d;
        for (int i = 0; i < m-1; i++) ans += month_days[i];
        ans += y * year_days;
        if (m > 2) ans += y/4 - y/100 + y/400;
        else ans += (y-1)/4 - (y-1)/100 + (y-1)/400;
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Date a, b;
    a.init();
    b.init();
    cout << b.nth_day() - a.nth_day() << '\n';

    return 0;
}