// https://dmoj.ca/problem/ccc20s1
//#include <iostream>
//#include <math.h>
//#include <vector>
//#include <algorithm>
#include <bits/stdc++.h> 
//#include <utility>
//#include <cstdio>
//#include <tuple>

double abso(double n) {
    if (n < 0) {
        n = 0-n;
    }
    return n;
}

int main() {
    int pairs;
    double a, b;
    double da, db;
    double spd, maxspd;
    std::cin >> pairs;

    std::vector<std::pair<double, double> > locations;

    for (int i = 0; i < pairs; i++) {
        std::cin >> a >> b;
        locations.push_back(std::make_pair(a, b));
    } 
    std::sort(locations.rbegin(), locations.rend());

    da = std::get<0>(locations[0])-std::get<0>(locations[1]);
    db = std::get<1>(locations[0])-std::get<1>(locations[1]);
    maxspd = (double)abso(db/da);
    
    for (int i = 2; i < pairs; i++) {
        da = std::get<0>(locations[i-1])-std::get<0>(locations[i]);
        db = std::get<1>(locations[i-1])-std::get<1>(locations[i]);
        spd = (double)abso(db/da);
        if (spd > maxspd) {
            maxspd = spd;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << maxspd << std::endl;

    return 0;
}