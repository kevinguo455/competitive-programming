// https://dmoj.ca/problem/ccc05j1
#include <iostream>
#include <math.h>

int main() {

    int daytime,evening,weekend;
    float planA,planB;
    std::cin >> daytime >> evening >> weekend;

    planA = (std::max(daytime-100,0) * 25 + evening * 15 + weekend * 20) / 100.0;
    planB = (std::max(daytime-250,0) * 45 + evening * 35 + weekend * 25) / 100.0;

    std::cout << "Plan A costs " << planA << std::endl << "Plan B costs " << planB << std::endl;

    if (planA == planB) {
        std::cout << "Plan A and B are the same price.";
    }
    else if (planA > planB) {
        std::cout << "Plan B is cheapest.";
    }
    else {
        std::cout << "Plan A is cheapest.";
    }

    return 0;
}