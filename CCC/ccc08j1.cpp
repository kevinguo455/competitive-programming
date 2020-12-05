// https://dmoj.ca/problem/ccc08j1
#include <iostream>
#include <math.h>

int main() {

    double weight,height,bmi;
    std::cin >> weight >> height;
    bmi = weight / pow(height,2);

    if (bmi > 25 ) {
        std::cout << "Overweight";
    }
    else if (bmi < 18.5) {
        std::cout << "Underweight";
    }
    else {
        std::cout << "Normal weight";
    }

    return 0;
}