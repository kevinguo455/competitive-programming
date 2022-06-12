/*
Leetcode 88. Merge Sorted Array
Key Concepts: Greedy Algorithm, Two Pointers
https://leetcode.com/problems/merge-sorted-array/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

/*
// An implementation of merging the elements from smallest to largest.
// An extra array must be used to prevent elements from being overwritten.

// Time Complexity: O(m+n)
// Space Complexity: O(m)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1orig(nums1.begin(), nums1.begin()+m);
        int ptr1 = 0, ptr2 = 0, idx = 0;
        while (ptr1 != m || ptr2 != n) {
            if (ptr1 == m) nums1[idx++] = nums2[ptr2++];
            else if (ptr2 == n) nums1[idx++] = nums1orig[ptr1++];
            else if (nums1orig[ptr1] < nums2[ptr2]) nums1[idx++] = nums1orig[ptr1++];
            else nums1[idx++] = nums2[ptr2++];
        }
    }
};

*/

// Elements can be merged in place if merged from largest to smallest.
// When processed in this order, elements are guaranteed to not be overwritten.

// Time Complexity: O(m+n)
// Space Complexity: O(1) extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m, ptr2 = n, idx = m+n;
        while (ptr1 != 0 && ptr2 != 0) {
            if (nums1[ptr1-1] > nums2[ptr2-1]) nums1[--idx] = nums1[--ptr1];
            else nums1[--idx] = nums2[--ptr2];
        }
        while (ptr1 != 0) {
            nums1[--idx] = nums1[--ptr1];
        }
        while (ptr2 != 0) {
            nums1[--idx] = nums2[--ptr2];
        }
    }
};

// An alternative and equivalent implementation.

/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m, ptr2 = n, idx = m+n;
        while (ptr1 != 0 || ptr2 != 0) {
            if (ptr1 == 0) nums1[--idx] = nums2[--ptr2];
            else if (ptr2 == 0) nums1[--idx] = nums1[--ptr1];
            else if (nums1[ptr1-1] > nums2[ptr2-1]) nums1[--idx] = nums1[--ptr1];
            else nums1[--idx] = nums2[--ptr2];
        }
    }
};
*/
