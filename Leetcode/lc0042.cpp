/*
Leetcode 42. Trapping Rain Water
Key Concepts: Monotonic Stack
https://leetcode.com/problems/trapping-rain-water/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: Maintain a monotonic decreasing stack of bar heights.
// Time Complexity: O(n)

struct Bar {
    int height;
    int index;
};

int trap(vector<int>& height) {
    int ans = 0;
        
    stack<Bar> s;
      
    for (int i = 0; i < height.size(); ++i) {
        while (!s.empty() && height[i] >= s.top().height) {
            Bar b = s.top(); s.pop();
            if (!s.empty()) ans += (i - s.top().index-1) * (min(s.top().height, height[i]) - b.height);
        }
        s.push({height[i], i});
    }
     
    return ans;
}
