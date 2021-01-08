/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 1C - Foxhole
Key Concepts: Simulation
https://dmoj.ca/problem/acmtryouts1b
Solution by Kevin Guo
*/

#include <iostream>
#include <vector>
#include <string>

int main() {
    int t, h, w, n;
    std::cin >> t;
    int treasures;
    std::string floor;
    std::vector<std::string> ground;
    int foxx;
    int foxy;
    char step;
    for (int i = 0; i < t; i++) {
        treasures = 0;
        floor = "";
        ground.clear();
        foxx = 0;
        foxy = 0;
        std::cin >> h >> w >> n;
        for (int j = 0; j < w; j++) {
            floor += "E";
        }
        ground.push_back(floor);
        for (int j = 0; j < h; j++) {
            std::cin >> floor;
            ground.push_back(floor);
        }
        for (int j = 0; j < n; j++) {
            std::cin >> step;
            if (step == 'R') {
                foxx = std::min(w-1,foxx+1);
                if (ground[foxy][foxx] == 'S') {
                    foxx--;
                }
            }
            else if (step == 'L') {
                foxx = std::max(0,foxx-1);
                if (ground[foxy][foxx] == 'S') {
                    foxx++;
                }
            }
            else if (step == 'D') {
                foxy = std::min(h,foxy+1);
                if (ground[foxy][foxx] == 'S') {
                    foxy--;
                }
            }
            if (foxy != -1) {
                if (ground[foxy][foxx] == 'T') {
                    treasures++;
                    ground[foxy][foxx] = 'E';
                }
            }
            while (foxy != h) {
                if (ground[foxy+1][foxx] != 'E') {
                    break;
                }
                foxy++;
            }
            //std::cout << "Foxpos: " << foxx << " " << foxy << std::endl;
        }
        std::cout << treasures << std::endl;
    }
    return 0;
}
