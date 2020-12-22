/*
USACO 2020 December Contest, Silver - Problem 3. Stuck in a Rut
Key Concepts: Implementation
http://www.usaco.org/index.php?page=viewproblem&cpid=1052
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x;  // starting x coord
    int y;  // starting y coord
    int b;  // blame
    bool s; // stopped? 
    int id; // position in input
};

bool cmpX(Cow a, Cow b) {
    return a.x < b.x;
}

bool cmpY(Cow a, Cow b) {
    return a.y < b.y;
}

bool cmpID(Cow a, Cow b) {
    return a.id < b.id;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    vector<Cow> n, e;   // north cows, east cows

    int cows, x, y; cin >> cows;
    char f;

    for (int i = 0; i < cows; i++) {
        cin >> f >> x >> y;

        if (f == 'N') n.push_back({x, y, 0, 0, i});
        else e.push_back({x, y, 0, 0, i});
    }

    sort(n.begin(), n.end(), cmpX);
    sort(e.begin(), e.end(), cmpY);

    for (int i = 0; i < n.size(); i++) {
        for (int j = 0; j < e.size(); j++) {
            int dx = n[i].x - e[j].x;
            int dy = e[j].y - n[i].y;
            if (dy < 0 || dx < 0) continue; // these cows don't intersect

            if (dy > dx && e[j].s == 0) {              // stop north cow (if east cow still moving)
                n[i].s = 1;
                e[j].b += n[i].b + 1;    // transfer blame
                break;
            }
            else if (dx > dy && e[j].s == 0) {         // stop east cow (if east cow still moving)
                e[j].s = 1;
                n[i].b += e[j].b + 1;    // transfer blame
            }
        }
    }

    n.reserve(n.size() + e.size());
    n.insert(n.end(), e.begin(), e.end());
    sort(n.begin(), n.end(), cmpID);

    for (int i = 0; i < n.size(); i++) {
        cout << n[i].b << "\n";
    }

    return 0;
}