/*
Leetcode 160. Intersection of Two Linked Lists
Key Concepts: Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Time Complexity: O(N+M), where N and M are the lengths of lists A and B, respectively.
// Space Complexity: O(1)

// Idea: Let a be the number of nodes to skip ahead in listA to reach the intersected node (or the end of the list).
//       Let b be the number of nodes to skip ahead in listB to reach the intersected node (or the end of the list).
//       Let c be the length of the intersected portion of the lists.
//       Then the length of listA is a+c, and the length of listB is b+c. 
//       Since (a+c)+b = (b+c)+a, simultaneously travelling (listA + listB) and (listB + listA) will guarantee
//       meeting at their earliest intersection.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;          // (listA + listB) and (listB + listA) have the same length
        while (curA != nullptr || curB != nullptr) {    //   so we traverse them until they both reach their end
            if (curA == nullptr) curA = headB;
            if (curB == nullptr) curB = headA;
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
