// https://dmoj.ca/problem/ccc07j1
#include <iostream>

int main() {

    int num1, num2, num3, res;
    std::cin >> num1 >> num2 >> num3;

    if ((num1 <= num2 && num2 <= num3)||(num3 <= num2 && num2 <= num1)) {
        res = num2;
    }
    else if ((num1 <= num3 && num3 <= num2)||(num2 <= num3 && num3 <= num1)) {
        res = num3;
    }
    else {
        res = num1;
    }

    std::cout << res;

    return 0;
}