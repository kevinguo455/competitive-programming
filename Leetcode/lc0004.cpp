/*
Leetcode 4. Median of Two Sorted Arrays
Key Concepts: Two Pointers
https://leetcode.com/problems/median-of-two-sorted-arrays/
Solution by Kevin Guo
*/
#include <stdio.h>
#include <limits.h>

inline int min(int a, int b) {
    return (a < b) ? a : b;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Time Complexity: O(n)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    // ensure nums1Size <= nums2Size
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int l = 0, r = nums1Size, m1, m2, vl1, vl2, vr1, vr2;
    while (l <= r) {
        m1 = (l+r+1)/2;
        m2 = (nums1Size + nums2Size + 1)/2 - m1;
        
        vl1 = (m1 == 0) ? INT_MIN : nums1[m1-1];
        vl2 = (m2 == 0) ? INT_MIN : nums2[m2-1];
        vr1 = (m1 == nums1Size) ? INT_MAX : nums1[m1];
        vr2 = (m2 == nums2Size) ? INT_MAX : nums2[m2];
        
        if (vl1 > vr2) {
            r = m1 - 1;
        } else if (vr1 < vl2) {
            l = m1 + 1;
        } else break;
    }
    
    int maxl = max(vl1, vl2);
    int minr = min(vr1, vr2);
    
    if ((nums1Size + nums2Size) % 2 == 0) {
        return (maxl + minr) / 2.0;
    } else {
        return maxl;
    }
}
