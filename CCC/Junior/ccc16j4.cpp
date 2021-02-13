// https://dmoj.ca/problem/ccc16j4
#include <iostream>
#include <string>
#include <math.h>

int main() {
    std::string input;
    std::cin >> input;

    int time = 0, travel = 120; //Time in minutes
    if (input[3] == '4') {
        time += 40;
    } else if (input[3] == '2') {
        time += 20;
    }

    time += (input[1] - '0') * 60;
    if (input[0] == '1') {
        time += 600;
    } else if (input[0] == '2') {
        time += 1200;
    }

    while (travel > 0) {
        if ((60 * 7 <= time && time < 60 * 10) || (60 * 15 <= time && time < 60 * 19)) {//Is rush hour
            travel -= 5;
        } else {
            travel -= 10;
        }
        time += 10;
        if (time >= 60 * 24) {
            time -= 60 * 24;
        }
    }
    if (time < 600) {
        std::cout << "0";
    }
    std::cout << floor(time/60) << ":" << time % 60;
    if (time % 60 == 0) {
        std::cout << "0";
    }

    return 0;
}