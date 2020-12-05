// https://dmoj.ca/problem/ccc15s1
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> x(n, 0);
	int i = 0;
	while (n > 0) {
		std::cin >> x[i];
		if (x[i] == 0 && i != 0) {
			i--;
			x[i] = 0;
		}
		else {
			i++;
		}
		n--;
	}

	int sum = 0;
	for (int j = 0; j < i; j++) {
		sum += x[j];
	}

	std::cout << sum;
    return 0;
}
