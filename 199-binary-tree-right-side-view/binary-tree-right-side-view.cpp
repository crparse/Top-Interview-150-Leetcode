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
    void recursion(TreeNode *root, int level, vector<int> &solution){
        if(root == NULL) return;
        if(solution.size() == level) solution.push_back(root->val);
        recursion(root->right, level+1, solution);
        recursion(root->left, level+1, solution);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        recursion(root, 0, solution);
        return solution;
    }
};
