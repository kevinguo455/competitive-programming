/*
Leetcode 1302. Deepest Leaves Sum
Key Concepts: Recursion
https://leetcode.com/problems/deepest-leaves-sum/
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Returns a pair {depth, sum} containing the sum of the deepest layer and 
    //   the depth of that layer.
    pair<int, int> deepestLayerSum(TreeNode* root) {
        if (root == NULL) return {0, 0};
        
        pair<int, int> l = deepestLayerSum(root->left);
        pair<int, int> r = deepestLayerSum(root->right);
        if (l.first < r.first) swap(l, r);                              // ensure depth(l) >= depth(r)
        
        if (l.first == 0) return {1, root->val};                        // if this node is a leaf node
        if (l.first == r.first) return {l.first+1, l.second+r.second};  // if both children have the same depth
        return {l.first+1, l.second};                                   // if l has a greater depth than r
    }

    int deepestLeavesSum(TreeNode* root) {
        return deepestLayerSum(root).second;
    }
};
