/*
USACO 2020 December Contest, Bronze - Problem 3. Stuck in a Rut
Key Concepts: Implementation
http://www.usaco.org/index.php?page=viewproblem&cpid=1049
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x;  // starting x coord
    int y;  // starting y coord
    int s;  // score (grass eaten)
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

        if (f == 'N') n.push_back({x, y, 0, i});
        else e.push_back({x, y, 0, i});
    }

    sort(n.begin(), n.end(), cmpX);
    sort(e.begin(), e.end(), cmpY);

    for (int i = 0; i < n.size(); i++) {
        for (int j = 0; j < e.size(); j++) {
            int dx = n[i].x - e[j].x;
            int dy = e[j].y - n[i].y;
            if (dy < 0 || dx < 0) continue; // these cows don't intersect

            if (dy > dx && e[j].s == 0) {              // stop north cow (if east cow still moving)
                n[i].s = dy;
                break;
            }
            else if (dx > dy && e[j].s == 0) {         // stop east cow (if east cow still moving)
                e[j].s = dx;
            }
        }
    }

    n.reserve(n.size() + e.size());
    n.insert(n.end(), e.begin(), e.end());
    sort(n.begin(), n.end(), cmpID);

    for (int i = 0; i < n.size(); i++) {
        if (n[i].s == 0) cout << "Infinity\n";
        else cout << n[i].s << "\n";
    }

    return 0;
}