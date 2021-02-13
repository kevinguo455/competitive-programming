// https://dmoj.ca/problem/ccc13s2
#include <iostream>
#include <vector>

int main() {
	int weightLimit, cars, crossingWeight = 0;
	std::cin >> weightLimit >> cars;

	std::vector<int> carWeight(cars);
	for (int i = 0; i < cars; i++) {
		std::cin >> carWeight[i];
		crossingWeight += carWeight[i];
		if (i >= 4) {
			crossingWeight -= carWeight[i - 4];
		}
		if (crossingWeight > weightLimit) {
			std::cout << i;
			return 0;
		}
	}
	
	std::cout << cars;

    return 0;
}