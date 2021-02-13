// https://dmoj.ca/problem/ccc12j1
#include <iostream>

int main() {
    int limit, speed, fine;

    std::cin >> limit >> speed;

    if ((speed - limit) <= 0) {
        std::cout << "Congratulations, you are within the speed limit!";
    }
    else if ((speed - limit) <= 20) {
        std::cout << "You are speeding and your fine is $100.";
    }
    else if ((speed - limit) <= 30) {
        std::cout << "You are speeding and your fine is $270.";
    }
    else {
        std::cout << "You are speeding and your fine is $500.";
    }
    return 0;
}