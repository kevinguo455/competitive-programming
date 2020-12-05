// https://dmoj.ca/problem/ccc06j1
#include <iostream>
#include <math.h>

int main() {

    int calories=0,burger,drink,side,dessert;
    std::cin >> burger >> side >> drink >> dessert;

    switch (burger) {
        case 1: calories+=461;
            break;
        case 2: calories+=431;
            break;
        case 3: calories+=420;
    }

    switch (side) {
        case 1: calories+=100;
            break;
        case 2: calories+=57;
            break;
        case 3: calories+=70;
    }

    switch (drink) {
        case 1: calories+=130;
            break;
        case 2: calories+=160;
            break;
        case 3: calories+=118;
    }

    switch (dessert) {
        case 1: calories+=167;
            break;
        case 2: calories+=266;
            break;
        case 3: calories+=75;
    }

    std::cout << "Your total Calorie count is " << calories << ".";

    return 0;
}