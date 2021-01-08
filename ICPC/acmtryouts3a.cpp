/*
University of Toronto ACM-ICPC Tryouts 2013 Problem 3A - A Research Project
Key Concepts: Implementation
https://dmoj.ca/problem/acmtryouts3a
Solution by Kevin Guo
*/
#include <iostream>

int main() {
    int guys, pics;
    std::cin >> guys;

    for (int i = 0; i < guys; i++) {
        std::cin >> pics;
        int top = 0, bot = 100;
        int rating;
        for (int j = 0; j < pics; j++) {
            std::cin >> rating;
            if (rating > top) {
                top = rating;
            }
            if (rating < bot) {
                bot = rating;
            }
        }
        std::cout << bot << " " << top << std::endl;
    }

    return 0;
}