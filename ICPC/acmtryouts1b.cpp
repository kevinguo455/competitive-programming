/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 1B - The Foxen's Treasure
Key Concepts: Implementation
https://dmoj.ca/problem/acmtryouts1b
Solution by Kevin Guo
*/
#include <iostream>
#include <vector>

int lcm(std::vector<int> x) { //FINDS LCM OF ALL NUMBERS IN A VECTOR
    return 100000;
}

int main() {
    int scenario, foxen;
    int awake[4];
    int asleep[4];
    int start[4];
    int steal = 0;
    std::vector<int> cycle(0);
    std::cin >> scenario;

    for (int i = 0; i < scenario; i++) {
        cycle.clear();
        std::cin >> foxen;
        //GET ALL VALUES
        for (int j = 0; j < foxen; j++) {
            std::cin >> awake[j] >> asleep[j] >> start[j];
            asleep[j] += awake[j];
            cycle.push_back(asleep[j]);
        }
        steal = 0; //check for stealing
        for (int j = 0; j < foxen; j++) {
            if (start[j] <= awake[j]) { //IF FOXEN IS AWAKE
                steal++; //Don't steal
            }
        }
        //LOGIC
        for (int hours = 0; hours < lcm(cycle); hours++) {
            if (steal == 0) { //steal!!
                std::cout << hours << std::endl;
                break;
            }
            for (int j = 0; j < foxen; j++) { //Advance time
                if (start[j] == asleep[j]) {
                    start[j] = 1;
                } else {
                    start[j]++;
                }
            }
            steal = 0;
            for (int j = 0; j < foxen; j++) { //check for stealing
                if (start[j] <= awake[j]) { //IF FOXEN IS AWAKE
                    steal++; //Don't steal
                }
            }
            if (steal == 0) { //steal!!
                std::cout << hours << std::endl;
                break;
            }
            if (hours == lcm(cycle)-1) { //give up
                std::cout << "Foxen are too powerful" << std::endl;
                break;
            }
        }
    }
    return 0;
}