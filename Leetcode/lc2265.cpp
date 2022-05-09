/*
Leetcode 2265. Count Nodes Equal to Average of Subtree
Key Concepts: Recursion
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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

struct Res {
    int cnt;    // number of nodes equal to average of subtree
    int sum;    // sum of nodes in sumbtree
    int size;   // size of subtree
};

class Solution {
public:

    Res solve(TreeNode* root) {
        if (root == NULL) return {0, 0, 0};

        // recursively find information of subtrees
        Res l = solve(root->left);
        Res r = solve(root->right);

        // combine information of subtrees
        int size = 1 + l.size + r.size;
        int sum = root->val + l.sum + r.sum;
        int cnt = l.cnt + r.cnt;
        
        if (sum != 0 && sum/size == root->val) ++cnt;
        return {cnt,sum,size};
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root).cnt;
    }

};
