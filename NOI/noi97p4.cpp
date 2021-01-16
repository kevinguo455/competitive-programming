/*
NOI '97 P4 - Perfect Tour
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/noi97p4
Solution by Kevin Guo
*/
#include <iostream>
#include <vector>

int main()
{
	int horizontal, vertical; // Amount of horizontal streets, amount of vertical streets
	std::cin >> horizontal >> vertical;
	std::vector<std::vector<int> > rating(horizontal, std::vector<int>(vertical - 1)); // Array of rating of the street to the right of point [horizontal][vertical]

	for (int i = 0; i < horizontal; i++) {
		for (int j = 0; j < vertical - 1; j++) {
			std::cin >> rating[i][j];
		}
	}

	int tourScore = 0, maxTourScore = 0, optimalPathScore = 0;
	int path = 0, maxPath;

	// Find optimal path through all elements
	std::vector<int> optimalPath(vertical);
	for (int i = 0; i < vertical - 1; i++) {
		maxPath = -150;
		for (int j = 0; j < horizontal; j++) {
			path = rating[j][i];
			if (path > maxPath) {
				maxPath = path;
			}
		}
		optimalPathScore += maxPath;
		optimalPath[i] = maxPath;
	}

	optimalPath[vertical - 1] = 0;

	// Remove elements of beginning and end of tour for optimal tour
	for (int start = 0; start < vertical - 1; start++) {
		tourScore = optimalPathScore;
		optimalPathScore -= optimalPath[start];
		for (int end = vertical - 1; end >= start; end--) {
			tourScore -= optimalPath[end];
			if (tourScore > maxTourScore) {
				maxTourScore = tourScore;
			}
		}
	}

	std::cout << maxTourScore;

	return 0;
}