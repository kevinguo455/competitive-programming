/*
Leetcode 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Key Concepts: Binary Tree Traversal
https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Traverse the cloned tree until a node with the same value as the target node is found.
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == NULL) return NULL;
        if (cloned->val == target->val) return cloned;
        TreeNode *ans = getTargetCopy(original, cloned->left, target);
        if (ans == NULL) return getTargetCopy(original, cloned->right, target);
        return ans;
    }
};
