// https://dmoj.ca/problem/ccc14s2
#include <iostream>
#include <string>
#include <vector>

int main() {
	int students;
	std::cin >> students;
	std::vector<std::string> a(students);
	std::vector<std::string> b(students);

	for (int i = 0; i < students; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < students; i++) {
		std::cin >> b[i];
	}

	for (int i = 0; i < students; i++) {
		if (a[i] == b[i]) {
			std::cout << "bad";
			return 0;
		}
		for (int j = i; j >= 0; j--) {
			if (b[i] == a[j] && b[j] != a[i]) {
				std::cout << "bad";
				return 0;
			}
		}
	}

	std::cout << "good";
	return 0;
}
