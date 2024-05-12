/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int currSum) {
        if (!root) return 0;
        currSum = currSum * 10 + root->val;
        // If the current node is a leaf node, return the current sum
        if (!root->left && !root->right) return currSum;
        // Recursively calculate the sum for left and right subtrees
        return dfs(root->left, currSum) + dfs(root->right, currSum);
    }
};
