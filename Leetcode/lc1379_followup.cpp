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

// Follow up: Could you solve the problem if repeated values on the tree are allowed?

class Solution {
public:
    
    // Simultaneously traverse the original and cloned tree until
    //    we find the node in the original tree that target points to.
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) return NULL;
        if (original == target) return cloned;
        TreeNode *ans = getTargetCopy(original->left, cloned->left, target);
        if (ans == NULL) return getTargetCopy(original->right, cloned->right, target);
        return ans;
    }
};
